/*!
  * @file     main.c
  *
  * @brief    STC8H
  *
  * @company  北京龙邱智能科技
  *
  * @author   LQ-005
  *
  * @note     无
  *
  * @version  V1.1 版权所有，单位使用请先联系授权
  *
  *           软件平台 keil c51v960a
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @email    chiusir@163.com
  *
  * @date     2020年3月20日
  */

#include "main.h"

/**
  * @brief    不精确延时
  *
  * @param    无
  *
  * @return   无
  *
  * @note     无
  *
  * @example  delayms(100);
  *
  * @date     2019/4/22 星期一
*/
void delayms(uint32_t ms){  //延时函数
	while(ms--){
		uint16_t xdata i = 300;
		while(i--){
			NOP(50);
		}
	}
}

// extern float a[3],w[3],angle[3],T;
extern uint8_t sign0, sign_k;
extern uint8_t f_sw;
extern int L_V, R_V;
volatile uint8_t xdata sign_delay = 0, sign_start = 0;
volatile uint8_t xdata flag_turn = 0, flag_turn0 = 0, flag_speed = 0, flag_speed0 = 0, flag_rh = 0;
volatile uint8_t xdata delay_cnt = 0;
volatile float xdata tx_float[3];
volatile int xdata tx_int[6];
volatile uint8_t bt_info[27];
float xdata angle_out=0.0f;
int xdata stand_pid_out = 0;
int xdata speed_pid_out = 0;
int xdata turn_pid_out = 0;
int32_t xdata pid_out_l, pid_out_r;
#if (OLED_DBG == 1)
volatile char xdata txt[35];
volatile uint16_t xdata ccd_buf[128];
volatile uint16_t xdata cnt1;
volatile uint8_t xdata i;
#endif

void main(){
	//注意 系统时钟默认使用ISP软件设置的IRC频率 
	//注意 如果修改系统时钟，请修改stc8.h中的 MAIN_Fosc 时钟，否则可能会导致串口波特率错误、定时器不准等问题
	//注意 单片机栈大小有限，请尽可能的少用局部变量，尽量用全局变量
	//注意 如果使用局部变量，请将局部变量定义在任何执行语句之前，在块的开头声明所有局部变量。
	//注意 STC8默认P54为普通IO 如果要使用P54做复位管脚，请修改寄存器 RSTCFG = 0x50; //复位寄存器，如果是0x00，则复位管脚用作普通IO
	//注意 uart收发均会使用到串口中断，串口初始化后，一定要开启总中断再使用串口进行收发操作 不要在串口中断中进行串口发送操作
	
	volatile float xdata angle1 = 0.0f;
	volatile uint16_t xdata sum = 0;
	volatile uint8_t xdata cnt = 0;
	
	RSTCFG = 0x50; //复位寄存器，如果是0x00，则复位管脚用作普通IO
	
	P_SW1 |= (1<<4);
	P_SW1 &= 0xdf;
	EA = 1;             //开启总中断
	CR = 1; 			//启动 PCA 计时器
	
	Motor_Init();
	Enc_Init();
	TIMER0_InitSys();
	UART1_InitTimer1P30P31(115200);		// 下载
	UART3_InitTimer2P50P51(115200);		// 蓝牙
	IIC_Init(); 						// mpu6050	SCL->P1.0 | SDA->P1.1
	My_ADC_Init();
	RGB_Init;
	BEEP_Init;
	Dial_Init;
	
#if (OLED_DBG == 1)
	OLED_Init();
	CCD_Init();
#else
	PIN_InitPureInput(3, 0);
	INT4_Enable();
#endif
	
	// 陀螺仪初始化
	if(MPU6050_Init())
    {
#if (OLED_DBG == 1)
		OLED_CLS();
        OLED_P8x16Str(15,2,"6050 Test Fail \r\n");
#endif
		printf("\r\n6050 Test Fail \r\n");
        while(1);
    }
	
	if(!Dial1){
		// 充电等待
		while(1){
			Get_ADC_Value();
			if(cap_v[0]>=580) 
				break;
		}
		
		// 电满提示
		BEEP = 0;
		delayms(500);
		BEEP = 1;
		EEPROM_R_SW = 1;
	}

	// 主循环
	while(1){
#if (OLED_DBG == 1)
		// OLED信息显示
		sprintf((char*)txt,"adc_hl: %6d", adc_hl);
		OLED_P6x8Str(0,0,txt);
		sprintf((char*)txt,"adc_hr: %6d", adc_hr);
		OLED_P6x8Str(0,1,txt);
		sprintf((char*)txt,"adc_vl: %6d", adc_vl);
		OLED_P6x8Str(0,2,txt);
		sprintf((char*)txt,"adc_vr: %6d", adc_vr);
		OLED_P6x8Str(0,3,txt);
		sprintf((char*)txt,"adc_z: %6d", adc_z);
		OLED_P6x8Str(0,4,txt);
#endif

		// 5ms
		if(sign0){
			// mpu6050数据采集、处理
			MPU_Get_Raw_data(&aacx,&aacy,&aacz,&gyrox,&gyroy,&gyroz);
			angle1 = -atan2(aacx, aacz) * RtA;
			angle_out = LowPassFilter_kalman(angle1, gyroy) / 100;
			
			// ADC数据采集、处理
			Get_ADC_Value();
			
			// 入环检测
//			if(adc_z[0] > 660 && adc_hl[0]+adc_hr[0] > 700){
//				if(flag_rh == 0){
//					if(adc_vl[0]-adc_vr[0] > 150)flag_rh = -1;
//					else if(adc_vl[0]-adc_vr[0] < -150)flag_rh = 1;
//				}
//			}else{
//				if(flag_rh == 1 && adc_vl[0]-adc_vr[0] >= 40){
//					ADC_SW1 = 0;
//					RH_Sign = 1;
//					flag_turn = 95;
//					sign_delay = 1;
//				}else if(flag_rh == -1 && adc_vl[0]-adc_vr[0] <= -40){
//					ADC_SW1 = 0;
//					RH_Sign = 1;
//					flag_turn = -95;
//					sign_delay = 1;
//				}
//			}
			
			// 电量提示
			if(cap_v[0] <= 180){
				R = 0;
			}else if(cap_v[0] >= 580){
				R = 1;
			}
			
			sign0 = 0;
			
			cnt++;
			if(cnt == 2){			// 10ms
				cnt = 0;
				
#if (OLED_DBG == 1) 
				// 采集ccd图像
				CCD_Collect(ccd_buf);
				cnt1 = 0;
				for(i=0; i<128; i++)
				{
					OLED_Set_Pos(i , 5); 
					if(ccd_buf[i] > threshold)
						OLED_WrDat(0xFF);
					else{
						OLED_WrDat(0x00);
						cnt1++;
					}
				}
#endif
				
#if (DEBUG == 1)
				// 蓝牙信息发送
				tx_float[0] = Turn_Set;
				tx_float[1] = angle1;
				tx_float[2] = angle_out;
				tx_int[0] = adc_hl[0];
				tx_int[1] = adc_hr[0];
				tx_int[2] = adc_vl[0];
				tx_int[3] = adc_vr[0];
				tx_int[4] = adc_z[0];
				tx_int[5] = cap_v[0];
				bt_info[0] = 0xa5;
				bt_info[26] = 0x5a;
				sum = Packet(sizeof(int), 6, (void *)tx_int, bt_info+1);
				sum += Packet(sizeof(float), 3, (void *)tx_float, bt_info+13);
				bt_info[25] = sum&0xff;
				UART3_PutBuff(bt_info, 27);
#endif
				
				if(sign_start == 0){
					if(adc_hl[0] + adc_hr[0] + adc_vl[0] + adc_vr[0] >= 250){
						sign_start = 1;
						ADC_SW1 = 1;
						Speed_New = 63.0f;
					}
				}else{
					if(sign_k){
						sign_delay = 1;
					}
				}
								
				// 测试状态标记
				if(RK_Sign){
					ADC_SW1 = 0;
					flag_speed0 = 1;
					flag_turn = 150;
					sign_delay = 1;
				}else{
					// 速度缓冲
					if(abs(L_V) <= 5 && abs(R_V) <= 5)
						Speed_Set = 36.0f;
					if(Speed_Set < Speed_New){
						Speed_Set += 0.15;
					}else if(Speed_Set > Speed_New){
						Speed_Set -= 0.15;
					}
				}
				
				// PID计算
				stand_pid_out = Stand(angle_out);
				speed_pid_out = Speed(L_V, R_V);
				turn_pid_out = Turn(L_V, R_V);
				
				// 编码器计数清零
				L_V = 0;
				R_V = 0;

				// EEPROM读写检测
				if(EEPROM_W_SW){
					eeprom_w();
					EEPROM_W_SW = 0;
				}
				if(EEPROM_R_SW){
					eeprom_r();
					EEPROM_R_SW = 0;
				}
				
				// 角度环开关
				if(Stand_SW){
					pid_out_l = pid_out_r = stand_pid_out;
				}else{
					pid_out_l = pid_out_r = 0;
				}
				
				// 速度环开关
				if(Speed_SW){
					pid_out_l -= speed_pid_out;
					pid_out_r -= speed_pid_out;
				}
				
				// 角度、速度限幅
				if(pid_out_l > 9000)pid_out_l = 9000;
				else if(pid_out_l < -9000)pid_out_l = -9000;
				if(pid_out_r > 9000)pid_out_r = 9000;
				else if(pid_out_r < -9000)pid_out_r = -9000;
				
				// 方向环开关
				if(Turn_SW){
					pid_out_l -= turn_pid_out;
					pid_out_r += turn_pid_out;
				}
				
				// 电感控制开关
				if(ADC_SW && ADC_SW1){
					if(!Dial2){
						G = 1;
						B = 0;
						Turn_Set = ADC_PID();
					}else{
						G = 0;
						B = 1;
						Turn_Set = ADC_H_PID();
					}
				}
				
				// 电机工作开关
				if(Stop_Sign || angle_out>100.0f || angle_out<-100.0f){
					Motor_Control(0, 0);
				}else{
			   		Motor_Control(pid_out_l, pid_out_r);
				}
				
				// 标志位计数延迟
				if(sign_delay){
					delay_cnt++;
					// 500 ms
					if(delay_cnt >= 50){
						delay_cnt = 0;
						sign_delay = 0;
						if(sign_k){
							sign_k = 0;
							Stop_Sign = 0;
						}
						
						flag_turn0 = 0;
						flag_speed0 = 0;
						flag_turn = 0;
						flag_speed = 0;
						
						if(RK_Sign){
							Turn_Set = 0;
							RK_Sign = 0;
							ADC_SW1 = 1;
							Speed_Set = 0;
						}else if(RH_Sign){
							Turn_Set = 0;
							RH_Sign = 0;
							ADC_SW1 = 1;
							flag_rh = 0;
						}
					}else{
//						if(flag_turn){
//							Turn_Set = flag_turn;
//						}else if(flag_turn0){
//							Turn_Set = 0;
//						}
//						if(flag_speed){
//							Speed_Set = flag_speed;
//						}else if(flag_speed0){
//							Speed_Set = 0;
//							Speed_New = 0;
//						}
						if(sign_k){
							Stop_Sign = 1;
						}
					}
				}
			}
		}
	}
}
