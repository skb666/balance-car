/*!
  * @file     stc8h
  *
  * @brief    STC8H
  *
  * @company  北京龙邱智能科技
  *
  * @author   LQ-005
  *
  * @note     无
  *
  * @version  V1.0
  *
  * @par URL  http://shop36265907.taobao.com
  *           http://www.lqist.cn
  *
  * @email    chiusir@163.com
  *
  * @date     2020年3月20日
  */


#ifndef	_STC8xxxx_H
#define	_STC8xxxx_H

#include <intrins.h>

/** 单片机系统时钟 注意和ISP下载软件设置的时钟一致 */
#define MAIN_Fosc 24000000L


/*  BYTE Registers  */
sfr P0    = 0x80;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr	S4CON = 0x84;
sfr	S4BUF = 0x85;
sfr PCON  = 0x87;

sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr	AUXR = 0x8E;
sfr WAKE_CLKO = 0x8F;
sfr INT_CLKO  = 0x8F;

sfr P1    = 0x90;
sfr P1M1  = 0x91;	//P1M1.n,P1M0.n 	=00--->Standard,	01--->push-pull		实际上1T的都一样
sfr P1M0  = 0x92;	//					=10--->pure input,	11--->open drain
sfr P0M1  = 0x93;	//P0M1.n,P0M0.n 	=00--->Standard,	01--->push-pull
sfr P0M0  = 0x94;	//					=10--->pure input,	11--->open drain
sfr P2M1  = 0x95;	//P2M1.n,P2M0.n 	=00--->Standard,	01--->push-pull
sfr P2M0  = 0x96;	//					=10--->pure input,	11--->open drain


sfr SCON  = 0x98;
sfr SBUF  = 0x99;
sfr S2CON = 0x9A;	//
sfr S2BUF = 0x9B;	//
sfr IRCBAND = 0x9d;
sfr LIRTRIM = 0x9e;
sfr IRTRIM  = 0x9f;

sfr P2    = 0xA0;
sfr P_SW1 = 0xA2;

sfr IE    = 0xA8;
sfr SADDR = 0xA9;
sfr WKTCL = 0xAA;	//唤醒定时器低字节
sfr WKTCH = 0xAB;	//唤醒定时器高字节
sfr	S3CON = 0xAC;
sfr S3BUF = 0xAD;
sfr TA    = 0xAE;
sfr IE2   = 0xAF;	

sfr P3    = 0xB0;
sfr P3M1  = 0xB1;	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
sfr P3M0  = 0xB2;	//					=10--->pure input,	11--->open drain
sfr P4M1  = 0xB3;	//P4M1.n,P4M0.n 	=00--->Standard,	01--->push-pull
sfr P4M0  = 0xB4;	//					=10--->pure input,	11--->open drain
sfr IP2   = 0xB5;	//STC12C5A60S2系列
sfr IP2H  = 0xB6;	//STC12C5A60S2系列
sfr IPH   = 0xB7;



sfr IP        = 0xB8;
sfr SADEN     = 0xB9;
sfr	P_SW2     = 0xBA;
sfr ADC_CONTR = 0xBC;	//ADC控制寄存器
sfr ADC_RES   = 0xBD;	//ADC结果高字节
sfr ADC_RESL  = 0xBE;	//ADC结果低字节

sfr P4        = 0xC0;
sfr WDT_CONTR = 0xC1;
sfr IAP_DATA  = 0xC2;
sfr IAP_ADDRH = 0xC3;
sfr IAP_ADDRL = 0xC4;
sfr IAP_CMD   = 0xC5;
sfr IAP_TRIG  = 0xC6;
sfr IAP_CONTR = 0xC7;

sfr ISP_DATA  = 0xC2;
sfr ISP_ADDRH = 0xC3;
sfr ISP_ADDRL = 0xC4;
sfr ISP_CMD   = 0xC5;
sfr ISP_TRIG  = 0xC6;
sfr ISP_CONTR = 0xC7;

sfr P5     = 0xC8;	//
sfr P5M1   = 0xC9;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
sfr P5M0   = 0xCA;	//					=10--->pure input,	11--->open drain
sfr P6M1   = 0xCB;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
sfr P6M0   = 0xCC;	//					=10--->pure input,	11--->open drain
sfr SPSTAT = 0xCD;	//
sfr SPCTL  = 0xCE;	//
sfr SPDAT  = 0xCF;	//

sfr PSW    = 0xD0;
sfr	T4T3M  = 0xD1;
sfr	T4H    = 0xD2;
sfr	T4L    = 0xD3;
sfr	T3H    = 0xD4;
sfr	T3L    = 0xD5;
sfr	T2H    = 0xD6;
sfr	T2L    = 0xD7;

sfr	TH4    = 0xD2;
sfr	TL4    = 0xD3;
sfr	TH3    = 0xD4;
sfr	TL3    = 0xD5;
sfr	TH2    = 0xD6;
sfr	TL2    = 0xD7;

sfr USBCLK = 0xdc;
sfr	ADCCFG = 0xDE;	//
sfr IP3    = 0xDF;

sfr ACC    = 0xE0;
sfr	P7M1   = 0xE1;
sfr	P7M0   = 0xE2;
sfr	DPS    = 0xE3;
sfr	DPL1   = 0xE4;
sfr	DPH1   = 0xE5;
sfr	CMPCR1 = 0xE6;
sfr	CMPCR2 = 0xE7;

sfr	P6     = 0xE8;
sfr USBDAT = 0xec;
sfr IP3H   = 0xEE;
sfr	AUXINTIF = 0xEF;	//辅助中断标志 B6-INT4IF, B5-INT3IF, B4-INT2IF, B2-T4IF, B1-T3IF, B0-T2IF

sfr B        = 0xF0;
sfr USBCON   = 0xf4;
sfr IAP_TPS  = 0xF5;	//IAP 等待时间控制寄存器


sfr	P7     = 0xF8;
sfr USBADR = 0xfc;
sfr	RSTCFG = 0xFF;		//






//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
//===============================================================
#define	EAXSFR()		P_SW2 |=  0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */

#define CLKSEL      (*(unsigned char volatile xdata *)0xfe00)
#define	CKSEL		(*(unsigned char volatile xdata *)0xfe00)	/* 主时钟源选择    */
#define	CLKDIV		(*(unsigned char volatile xdata *)0xfe01)	/* 主时钟分频      */
#define	IRC24MCR	(*(unsigned char volatile xdata *)0xfe02)	/* IRC 24MHZ控制   */
#define	XOSCCR		(*(unsigned char volatile xdata *)0xfe03)	/* XOSC控制        */
#define	IRC32KCR	(*(unsigned char volatile xdata *)0xfe04)	/* IRC 32KHZ控制   */
#define MCLKOCR     (*(unsigned char volatile xdata *)0xfe05)	/* 时钟输出控制   */

#define	MainFosc_IRC24M()	CKSEL = (CKSEL & ~0x03)			/* 选择内部24MHZ时钟 */
#define	MainFosc_XTAL()		CKSEL = (CKSEL & ~0x03) | 0x01	/* 选择外部晶振或时钟 */
#define	EXT_CLOCK()			XOSCCR = 0x80					/* 选择外部时钟 */
#define	EXT_CRYSTAL()		XOSCCR = 0xC0					/* 选择外部晶振 */
#define	MainFosc_IRC32K()	CKSEL  =  CKSEL | 0x03			/* 选择内部32K时钟 */
#define	MainFosc_OutP54()	MCLKOCR &=  ~0x80     		    /* 从P5.4输出主时钟分频 */
#define	MainFosc_OutP16()	MCLKOCR |=  0x80	    		/* 从P1.6输出主时钟分频 */
#define	MCLKO_None()		MCLKOCR &=  ~0x00		    	/* 主时钟不输出 	*/
#define	MCLKO_DIV(n)		MCLKOCR |=  n	                /* 主时钟n分频输出 */



#define	P0PU		(*(unsigned char volatile xdata *)0xfe10)	/* P0 4.1K Pull Up Enable  */
#define	P1PU		(*(unsigned char volatile xdata *)0xfe11)	/* P1 4.1K Pull Up Enable  */
#define	P2PU		(*(unsigned char volatile xdata *)0xfe12)	/* P2 4.1K Pull Up Enable  */
#define	P3PU		(*(unsigned char volatile xdata *)0xfe13)	/* P3 4.1K Pull Up Enable  */
#define	P4PU		(*(unsigned char volatile xdata *)0xfe14)	/* P4 4.1K Pull Up Enable  */
#define	P5PU		(*(unsigned char volatile xdata *)0xfe15)	/* P5 4.1K Pull Up Enable  */
#define	P6PU		(*(unsigned char volatile xdata *)0xfe16)	/* P6 4.1K Pull Up Enable  */
#define	P7PU		(*(unsigned char volatile xdata *)0xfe17)	/* P7 4.1K Pull Up Enable  */

#define	P0NCS		(*(unsigned char volatile xdata *)0xfe18)	/* P0 Non Schmit Trigger  */
#define	P1NCS		(*(unsigned char volatile xdata *)0xfe19)	/* P1 Non Schmit Trigger  */
#define	P2NCS		(*(unsigned char volatile xdata *)0xfe1a)	/* P2 Non Schmit Trigger  */
#define	P3NCS		(*(unsigned char volatile xdata *)0xfe1b)	/* P3 Non Schmit Trigger  */
#define	P4NCS		(*(unsigned char volatile xdata *)0xfe1c)	/* P4 Non Schmit Trigger  */
#define	P5NCS		(*(unsigned char volatile xdata *)0xfe1d)	/* P5 Non Schmit Trigger  */
#define	P6NCS		(*(unsigned char volatile xdata *)0xfe1e)	/* P6 Non Schmit Trigger  */
#define	P7NCS		(*(unsigned char volatile xdata *)0xfe1f)	/* P7 Non Schmit Trigger  */

#define P0SR        (*(unsigned char        volatile    xdata       *)0xfe20)
#define P1SR        (*(unsigned char        volatile    xdata       *)0xfe21)
#define P2SR        (*(unsigned char        volatile    xdata       *)0xfe22)
#define P3SR        (*(unsigned char        volatile    xdata       *)0xfe23)
#define P4SR        (*(unsigned char        volatile    xdata       *)0xfe24)
#define P5SR        (*(unsigned char        volatile    xdata       *)0xfe25)
#define P6SR        (*(unsigned char        volatile    xdata       *)0xfe26)
#define P7SR        (*(unsigned char        volatile    xdata       *)0xfe27)
	
#define P0DR        (*(unsigned char        volatile    xdata       *)0xfe28)
#define P1DR        (*(unsigned char        volatile    xdata       *)0xfe29)
#define P2DR        (*(unsigned char        volatile    xdata       *)0xfe2a)
#define P3DR        (*(unsigned char        volatile    xdata       *)0xfe2b)
#define P4DR        (*(unsigned char        volatile    xdata       *)0xfe2c)
#define P5DR        (*(unsigned char        volatile    xdata       *)0xfe2d)
#define P6DR        (*(unsigned char        volatile    xdata       *)0xfe2e)
#define P7DR        (*(unsigned char        volatile    xdata       *)0xfe2f)
	
#define P0IE        (*(unsigned char        volatile    xdata       *)0xfe30)
#define P1IE        (*(unsigned char        volatile    xdata       *)0xfe31)
#define P3IE        (*(unsigned char        volatile    xdata       *)0xfe33)

#define	I2CCFG		(*(unsigned char volatile xdata *)0xfe80)	/*   */
#define	I2CMSCR		(*(unsigned char volatile xdata *)0xfe81)	/*   */
#define	I2CMSST		(*(unsigned char volatile xdata *)0xfe82)	/*   */
#define	I2CSLCR		(*(unsigned char volatile xdata *)0xfe83)	/*   */
#define	I2CSLST		(*(unsigned char volatile xdata *)0xfe84)	/*   */
#define	I2CSLADR	(*(unsigned char volatile xdata *)0xfe85)	/*   */
#define	I2CTXD		(*(unsigned char volatile xdata *)0xfe86)	/*   */
#define	I2CRXD		(*(unsigned char volatile xdata *)0xfe87)	/*   */
#define	I2CMSAUX	(*(unsigned char volatile xdata *)0xfe88)	/*   */

#define TM2PS       (*(unsigned char        volatile    xdata       *)0xfea2)
#define TM3PS       (*(unsigned char        volatile    xdata       *)0xfea3)
#define TM4PS       (*(unsigned char        volatile    xdata       *)0xfea4)
#define ADCTIM      (*(unsigned char        volatile    xdata       *)0xfea8)




/* STC8H 的PWM寄存器  */
#if (STC8H == 1)

#define PWM1_ETRPS  (*(unsigned char volatile xdata *) 0xFEB0)  /* PWM1 的 ETR 选择寄存器  */
#define PWM1_ENO    (*(unsigned char volatile xdata *) 0xFEB1)  /* PWM1 输出使能控制  */
#define PWM1_PS     (*(unsigned char volatile xdata *) 0xFEB2)  /* PWM1 输出脚选择寄存器  */
#define PWM1_IOAUX  (*(unsigned char volatile xdata *) 0xfeb3)
#define PWM2_ETRPS  (*(unsigned char volatile xdata *) 0xfeb4)
#define PWM2_ENO    (*(unsigned char volatile xdata *) 0xFEB5)  /* PWM2 输出使能控制  */
#define PWM2_PS     (*(unsigned char volatile xdata *) 0xFEB6)  /* PWM2 输出脚选择寄存器  */
#define PWM2_IOAUX  (*(unsigned char volatile xdata *) 0xfeb7)

#define     PWM1_CR1    (*(unsigned char volatile xdata *)0xfec0)
#define     PWM1_CR2    (*(unsigned char volatile xdata *)0xfec1)
#define     PWM1_SMCR   (*(unsigned char volatile xdata *)0xfec2)
#define     PWM1_ETR    (*(unsigned char volatile xdata *)0xfec3)
#define     PWM1_IER    (*(unsigned char volatile xdata *)0xfec4)
#define     PWM1_SR1    (*(unsigned char volatile xdata *)0xfec5)
#define     PWM1_SR2    (*(unsigned char volatile xdata *)0xfec6)
#define     PWM1_EGR    (*(unsigned char volatile xdata *)0xfec7)
#define     PWM1_CCMR1  (*(unsigned char volatile xdata *)0xfec8)
#define     PWM1_CCMR2  (*(unsigned char volatile xdata *)0xfec9)
#define     PWM1_CCMR3  (*(unsigned char volatile xdata *)0xfeca)
#define     PWM1_CCMR4  (*(unsigned char volatile xdata *)0xfecb)
#define     PWM1_CCER1  (*(unsigned char volatile xdata *)0xfecc)
#define     PWM1_CCER2  (*(unsigned char volatile xdata *)0xfecd)
#define     PWM1_CNTR   (*(unsigned int volatile xdata *)0xfece)
#define     PWM1_CNTRH  (*(unsigned char volatile xdata *)0xfece)
#define     PWM1_CNTRL  (*(unsigned char volatile xdata *)0xfecf)
#define     PWM1_PSCR   (*(unsigned int volatile xdata *)0xfed0)
#define     PWM1_PSCRH  (*(unsigned char volatile xdata *)0xfed0)
#define     PWM1_PSCRL  (*(unsigned char volatile xdata *)0xfed1)
#define     PWM1_ARR    (*(unsigned int volatile xdata *)0xfed2)
#define     PWM1_ARRH   (*(unsigned char volatile xdata *)0xfed2)
#define     PWM1_ARRL   (*(unsigned char volatile xdata *)0xfed3)
#define     PWM1_RCR    (*(unsigned char volatile xdata *)0xfed4)
#define     PWM1_CCR1   (*(unsigned int volatile xdata *)0xfed5)
#define     PWM1_CCR1H  (*(unsigned char volatile xdata *)0xfed5)
#define     PWM1_CCR1L  (*(unsigned char volatile xdata *)0xfed6)
#define     PWM1_CCR2   (*(unsigned int volatile xdata *)0xfed7)
#define     PWM1_CCR2H  (*(unsigned char volatile xdata *)0xfed7)
#define     PWM1_CCR2L  (*(unsigned char volatile xdata *)0xfed8)
#define     PWM1_CCR3   (*(unsigned int volatile xdata *)0xfed9)
#define     PWM1_CCR3H  (*(unsigned char volatile xdata *)0xfed9)
#define     PWM1_CCR3L  (*(unsigned char volatile xdata *)0xfeda)
#define     PWM1_CCR4   (*(unsigned int volatile xdata *)0xfedb)
#define     PWM1_CCR4H  (*(unsigned char volatile xdata *)0xfedb)
#define     PWM1_CCR4L  (*(unsigned char volatile xdata *)0xfedc)
#define     PWM1_BKR    (*(unsigned char volatile xdata *)0xfedd)
#define     PWM1_DTR    (*(unsigned char volatile xdata *)0xfede)
#define     PWM1_OISR   (*(unsigned char volatile xdata *)0xfedf)
#define     PWM2_CR1    (*(unsigned char volatile xdata *)0xfee0)
#define     PWM2_CR2    (*(unsigned char volatile xdata *)0xfee1)
#define     PWM2_SMCR   (*(unsigned char volatile xdata *)0xfee2)
#define     PWM2_ETR    (*(unsigned char volatile xdata *)0xfee3)
#define     PWM2_IER    (*(unsigned char volatile xdata *)0xfee4)
#define     PWM2_SR1    (*(unsigned char volatile xdata *)0xfee5)
#define     PWM2_SR2    (*(unsigned char volatile xdata *)0xfee6)
#define     PWM2_EGR    (*(unsigned char volatile xdata *)0xfee7)
#define     PWM2_CCMR1  (*(unsigned char volatile xdata *)0xfee8)
#define     PWM2_CCMR2  (*(unsigned char volatile xdata *)0xfee9)
#define     PWM2_CCMR3  (*(unsigned char volatile xdata *)0xfeea)
#define     PWM2_CCMR4  (*(unsigned char volatile xdata *)0xfeeb)
#define     PWM2_CCER1  (*(unsigned char volatile xdata *)0xfeec)
#define     PWM2_CCER2  (*(unsigned char volatile xdata *)0xfeed)
#define     PWM2_CNTR   (*(unsigned int volatile xdata *)0xfeee)
#define     PWM2_CNTRH  (*(unsigned char volatile xdata *)0xfeee)
#define     PWM2_CNTRL  (*(unsigned char volatile xdata *)0xfeef)
#define     PWM2_PSCR   (*(unsigned int volatile xdata *)0xfef0)
#define     PWM2_PSCRH  (*(unsigned char volatile xdata *)0xfef0)
#define     PWM2_PSCRL  (*(unsigned char volatile xdata *)0xfef1)
#define     PWM2_ARR    (*(unsigned int volatile xdata *)0xfef2)
#define     PWM2_ARRH   (*(unsigned char volatile xdata *)0xfef2)
#define     PWM2_ARRL   (*(unsigned char volatile xdata *)0xfef3)
#define     PWM2_RCR    (*(unsigned char volatile xdata *)0xfef4)
#define     PWM2_CCR1   (*(unsigned int volatile xdata *)0xfef5)
#define     PWM2_CCR1H  (*(unsigned char volatile xdata *)0xfef5)
#define     PWM2_CCR1L  (*(unsigned char volatile xdata *)0xfef6)
#define     PWM2_CCR2   (*(unsigned int volatile xdata *)0xfef7)
#define     PWM2_CCR2H  (*(unsigned char volatile xdata *)0xfef7)
#define     PWM2_CCR2L  (*(unsigned char volatile xdata *)0xfef8)
#define     PWM2_CCR3   (*(unsigned int volatile xdata *)0xfef9)
#define     PWM2_CCR3H  (*(unsigned char volatile xdata *)0xfef9)
#define     PWM2_CCR3L  (*(unsigned char volatile xdata *)0xfefa)
#define     PWM2_CCR4   (*(unsigned int volatile xdata *)0xfefb)
#define     PWM2_CCR4H  (*(unsigned char volatile xdata *)0xfefb)
#define     PWM2_CCR4L  (*(unsigned char volatile xdata *)0xfefc)
#define     PWM2_BKR    (*(unsigned char volatile xdata *)0xfefd)
#define     PWM2_DTR    (*(unsigned char volatile xdata *)0xfefe)
#define     PWM2_OISR   (*(unsigned char volatile xdata *)0xfeff)
	

typedef struct PWM_struct
{
	volatile unsigned char CR1; /*!< control register 1 */
	volatile unsigned char CR2; /*!< control register 2 */
	volatile unsigned char SMCR; /*!< Synchro mode control register */
	volatile unsigned char ETR; /*!< external trigger register */
	volatile unsigned char IER; /*!< interrupt enable register*/
	volatile unsigned char SR1; /*!< status register 1 */
	volatile unsigned char SR2; /*!< status register 2 */
	volatile unsigned char EGR; /*!< event generation register */
	volatile unsigned char CCMR1; /*!< CC mode register 1 */
	volatile unsigned char CCMR2; /*!< CC mode register 2 */
	volatile unsigned char CCMR3; /*!< CC mode register 3 */
	volatile unsigned char CCMR4; /*!< CC mode register 4 */
	volatile unsigned char CCER1; /*!< CC enable register 1 */
	volatile unsigned char CCER2; /*!< CC enable register 2 */
	volatile unsigned char CNTRH; /*!< counter high */
	volatile unsigned char CNTRL; /*!< counter low */
	volatile unsigned char PSCRH; /*!< prescaler high */
	volatile unsigned char PSCRL; /*!< prescaler low */
	volatile unsigned char ARRH; /*!< auto-reload register high */
	volatile unsigned char ARRL; /*!< auto-reload register low */
	volatile unsigned char RCR; /*!< Repetition Counter register */
	volatile unsigned char CCR1H; /*!< capture/compare register 1 high */
	volatile unsigned char CCR1L; /*!< capture/compare register 1 low */
	volatile unsigned char CCR2H; /*!< capture/compare register 2 high */
	volatile unsigned char CCR2L; /*!< capture/compare register 2 low */
	volatile unsigned char CCR3H; /*!< capture/compare register 3 high */
	volatile unsigned char CCR3L; /*!< capture/compare register 3 low */
	volatile unsigned char CCR4H; /*!< capture/compare register 3 high */
	volatile unsigned char CCR4L; /*!< capture/compare register 3 low */
	volatile unsigned char BKR; /*!< Break Register */
	volatile unsigned char DTR; /*!< dead-time register */
	volatile unsigned char OISR; /*!< Output idle register */
}PWM_TypeDef;

#define PWM1_BaseAddress 0xFEC0
#define PWM2_BaseAddress 0xFEE0
#define PWM1 ((PWM_TypeDef xdata*) PWM1_BaseAddress)
#define PWM2 ((PWM_TypeDef xdata*) PWM2_BaseAddress)


/* STC8G PWM寄存器 */
#elif (STC8G == 1)
sfr         PWMSET      =           0xF1;
sfr         PCA_PWM0    =           0xF2;
sfr         PCA_PWM1    =           0xF3;
sfr         PCA_PWM2    =           0xF4;
sfr         PWMCFG01    =           0xF6;
sfr         PWMCFG23    =           0xF7;
sfr         CH          =           0xF9;
sfr         CCAP0H      =           0xFA;
sfr         CCAP1H      =           0xFB;
sfr         CCAP2H      =           0xFC;
sfr         PWMCFG45    =           0xFE;

sfr CCON = 0xd8; 
sbit CF = CCON^7; 
sbit CR = CCON^6; 
sbit CCF2 = CCON^2; 
sbit CCF1 = CCON^1; 
sbit CCF0 = CCON^0; 
sfr CMOD = 0xd9; 
sfr CL = 0xe9; 
sfr CCAPM0 = 0xda; 
sfr CCAP0L = 0xea;  
sfr CCAPM1 = 0xdb; 
sfr CCAP1L = 0xeb; 
sfr CCAPM2 = 0xdc; 
sfr CCAP2L = 0xec;

#define     PWM0C       (*(unsigned int  volatile xdata *)0xFF00)
#define     PWM0CKS     (*(unsigned char volatile xdata *)0xFF02)
#define     PWM0IF      (*(unsigned char volatile xdata *)0xFF05)
#define     PWM0FDCR    (*(unsigned char volatile xdata *)0xFF06)
#define     PWM00T1     (*(unsigned int  volatile xdata *)0xFF10)
#define     PWM00T2     (*(unsigned int  volatile xdata *)0xFF12) 
#define     PWM00CR     (*(unsigned char volatile xdata *)0xFF14)
#define     PWM00HLD    (*(unsigned char volatile xdata *)0xFF15)
#define     PWM01T1     (*(unsigned int  volatile xdata *)0xFF18)
#define     PWM01T2     (*(unsigned int  volatile xdata *)0xFF1A)
#define     PWM01CR     (*(unsigned char volatile xdata *)0xFF1C)
#define     PWM01HLD    (*(unsigned char volatile xdata *)0xFF1D)
#define     PWM02T1     (*(unsigned int  volatile xdata *)0xFF20)
#define     PWM02T2     (*(unsigned int  volatile xdata *)0xFF22)
#define     PWM02CR     (*(unsigned char volatile xdata *)0xFF24)
#define     PWM02HLD    (*(unsigned char volatile xdata *)0xFF25)
#define     PWM03T1     (*(unsigned int  volatile xdata *)0xFF28)
#define     PWM03T2     (*(unsigned int  volatile xdata *)0xFF2A)
#define     PWM03CR     (*(unsigned char volatile xdata *)0xFF2C)
#define     PWM03HLD    (*(unsigned char volatile xdata *)0xFF2D)
#define     PWM04T1     (*(unsigned int  volatile xdata *)0xFF30)
#define     PWM04T2     (*(unsigned int  volatile xdata *)0xFF32)
#define     PWM04CR     (*(unsigned char volatile xdata *)0xFF34)
#define     PWM04HLD    (*(unsigned char volatile xdata *)0xFF35)
#define     PWM05T1     (*(unsigned int  volatile xdata *)0xFF38)
#define     PWM05T2     (*(unsigned int  volatile xdata *)0xFF3A)
#define     PWM05CR     (*(unsigned char volatile xdata *)0xFF3C)
#define     PWM05HLD    (*(unsigned char volatile xdata *)0xFF3D)
#define     PWM06T1     (*(unsigned int  volatile xdata *)0xFF40)
#define     PWM06T2     (*(unsigned int  volatile xdata *)0xFF42)
#define     PWM06CR     (*(unsigned char volatile xdata *)0xFF44)
#define     PWM06HLD    (*(unsigned char volatile xdata *)0xFF45)
#define     PWM07T1     (*(unsigned int  volatile xdata *)0xFF48)
#define     PWM07T2     (*(unsigned int  volatile xdata *)0xFF4A)
#define     PWM07CR     (*(unsigned char volatile xdata *)0xFF4C)
#define     PWM07HLD    (*(unsigned char volatile xdata *)0xFF4D)
	
#define     PWM1C       (*(unsigned int  volatile xdata *)0xFF50)
#define     PWM1CKS     (*(unsigned char volatile xdata *)0xFF52)
#define     PWM1IF      (*(unsigned char volatile xdata *)0xFF55)
#define     PWM1FDCR    (*(unsigned char volatile xdata *)0xFF56)
#define     PWM10T1     (*(unsigned int  volatile xdata *)0xFF60)
#define     PWM10T2     (*(unsigned int  volatile xdata *)0xFF62)
#define     PWM10CR     (*(unsigned char volatile xdata *)0xFF64)
#define     PWM10HLD    (*(unsigned char volatile xdata *)0xFF65)
#define     PWM11T1     (*(unsigned int  volatile xdata *)0xFF68)
#define     PWM11T2     (*(unsigned int  volatile xdata *)0xFF6A)
#define     PWM11CR     (*(unsigned char volatile xdata *)0xFF6C)
#define     PWM11HLD    (*(unsigned char volatile xdata *)0xFF6D)
#define     PWM12T1     (*(unsigned int  volatile xdata *)0xFF70)
#define     PWM12T2     (*(unsigned int  volatile xdata *)0xFF72)
#define     PWM12CR     (*(unsigned char volatile xdata *)0xFF74)
#define     PWM12HLD    (*(unsigned char volatile xdata *)0xFF75)
#define     PWM13T1     (*(unsigned int  volatile xdata *)0xFF78)
#define     PWM13T2     (*(unsigned int  volatile xdata *)0xFF7A)
#define     PWM13CR     (*(unsigned char volatile xdata *)0xFF7C)
#define     PWM13HLD    (*(unsigned char volatile xdata *)0xFF7D)
#define     PWM14T1     (*(unsigned int  volatile xdata *)0xFF80)
#define     PWM14T2     (*(unsigned int  volatile xdata *)0xFF82)
#define     PWM14CR     (*(unsigned char volatile xdata *)0xFF84)
#define     PWM14HLD    (*(unsigned char volatile xdata *)0xFF85)
#define     PWM15T1     (*(unsigned int  volatile xdata *)0xFF88)
#define     PWM15T2     (*(unsigned int  volatile xdata *)0xFF8A)
#define     PWM15CR     (*(unsigned char volatile xdata *)0xFF8C)
#define     PWM15HLD    (*(unsigned char volatile xdata *)0xFF8D)
#define     PWM16T1     (*(unsigned int  volatile xdata *)0xFF90)
#define     PWM16T2     (*(unsigned int  volatile xdata *)0xFF92)
#define     PWM16CR     (*(unsigned char volatile xdata *)0xFF94)
#define     PWM16HLD    (*(unsigned char volatile xdata *)0xFF95)
#define     PWM17T1     (*(unsigned int  volatile xdata *)0xFF98)
#define     PWM17T2     (*(unsigned int  volatile xdata *)0xFF9A)
#define     PWM17CR     (*(unsigned char volatile xdata *)0xFF9C)
#define     PWM17HLD    (*(unsigned char volatile xdata *)0xFF9D)
	
#define     PWM2C       (*(unsigned int  volatile xdata *)0xFFA0)
#define     PWM2CKS     (*(unsigned char volatile xdata *)0xFFA2)
#define     PWM2IF      (*(unsigned char volatile xdata *)0xFFA5)
#define     PWM2FDCR    (*(unsigned char volatile xdata *)0xFFA6)
#define     PWM20T1     (*(unsigned int  volatile xdata *)0xFFB0)
#define     PWM20T2     (*(unsigned int  volatile xdata *)0xFFB2)
#define     PWM20CR     (*(unsigned char volatile xdata *)0xFFB4)
#define     PWM20HLD    (*(unsigned char volatile xdata *)0xFFB5)
#define     PWM21T1     (*(unsigned int  volatile xdata *)0xFFB8)
#define     PWM21T2     (*(unsigned int  volatile xdata *)0xFFBA)
#define     PWM21CR     (*(unsigned char volatile xdata *)0xFFBC)
#define     PWM21HLD    (*(unsigned char volatile xdata *)0xFFBD)
#define     PWM22T1     (*(unsigned int  volatile xdata *)0xFFC0)
#define     PWM22T2     (*(unsigned int  volatile xdata *)0xFFC2)
#define     PWM22CR     (*(unsigned char volatile xdata *)0xFFC4)
#define     PWM22HLD    (*(unsigned char volatile xdata *)0xFFC5)
#define     PWM23T1     (*(unsigned int  volatile xdata *)0xFFC8)
#define     PWM23T2     (*(unsigned int  volatile xdata *)0xFFCA)
#define     PWM23CR     (*(unsigned char volatile xdata *)0xFFCC)
#define     PWM23HLD    (*(unsigned char volatile xdata *)0xFFCD)
#define     PWM24T1     (*(unsigned int  volatile xdata *)0xFFD0)
#define     PWM24T2     (*(unsigned int  volatile xdata *)0xFFD2)
#define     PWM24CR     (*(unsigned char volatile xdata *)0xFFD4)
#define     PWM24HLD    (*(unsigned char volatile xdata *)0xFFD5)
#define     PWM25T1     (*(unsigned int  volatile xdata *)0xFFD8)
#define     PWM25T2     (*(unsigned int  volatile xdata *)0xFFDA)
#define     PWM25CR     (*(unsigned char volatile xdata *)0xFFDC)
#define     PWM25HLD    (*(unsigned char volatile xdata *)0xFFDD)
#define     PWM26T1     (*(unsigned int  volatile xdata *)0xFFE0)
#define     PWM26T2     (*(unsigned int  volatile xdata *)0xFFE2)
#define     PWM26CR     (*(unsigned char volatile xdata *)0xFFE4)
#define     PWM26HLD    (*(unsigned char volatile xdata *)0xFFE5)
#define     PWM27T1     (*(unsigned int  volatile xdata *)0xFFE8)
#define     PWM27T2     (*(unsigned int  volatile xdata *)0xFFEA)
#define     PWM27CR     (*(unsigned char volatile xdata *)0xFFEC)
#define     PWM27HLD    (*(unsigned char volatile xdata *)0xFFED)
	                                
#define     PWM3C       (*(unsigned int  volatile xdata *)0xFC00)
#define     PWM3CKS     (*(unsigned char volatile xdata *)0xFC02)
#define     PWM3IF      (*(unsigned char volatile xdata *)0xFC05)
#define     PWM3FDCR    (*(unsigned char volatile xdata *)0xFC06)
#define     PWM30T1     (*(unsigned int  volatile xdata *)0xFC10)
#define     PWM30T2     (*(unsigned int  volatile xdata *)0xFC12)
#define     PWM30CR     (*(unsigned char volatile xdata *)0xFC14)
#define     PWM30HLD    (*(unsigned char volatile xdata *)0xFC15)
#define     PWM31T1     (*(unsigned int  volatile xdata *)0xFC18)
#define     PWM31T2     (*(unsigned int  volatile xdata *)0xFC1A)
#define     PWM31CR     (*(unsigned char volatile xdata *)0xFC1C)
#define     PWM31HLD    (*(unsigned char volatile xdata *)0xFC1D)
#define     PWM32T1     (*(unsigned int  volatile xdata *)0xFC20)
#define     PWM32T2     (*(unsigned int  volatile xdata *)0xFC22)
#define     PWM32CR     (*(unsigned char volatile xdata *)0xFC24)
#define     PWM32HLD    (*(unsigned char volatile xdata *)0xFC25)
#define     PWM33T1     (*(unsigned int  volatile xdata *)0xFC28)
#define     PWM33T2     (*(unsigned int  volatile xdata *)0xFC2A)
#define     PWM33CR     (*(unsigned char volatile xdata *)0xFC2C)
#define     PWM33HLD    (*(unsigned char volatile xdata *)0xFC2D)
#define     PWM34T1     (*(unsigned int  volatile xdata *)0xFC30)
#define     PWM34T2     (*(unsigned int  volatile xdata *)0xFC32)
#define     PWM34CR     (*(unsigned char volatile xdata *)0xFC34)
#define     PWM34HLD    (*(unsigned char volatile xdata *)0xFC35)
#define     PWM35T1     (*(unsigned int  volatile xdata *)0xFC38)
#define     PWM35T2     (*(unsigned int  volatile xdata *)0xFC3A)
#define     PWM35CR     (*(unsigned char volatile xdata *)0xFC3C)
#define     PWM35HLD    (*(unsigned char volatile xdata *)0xFC3D)
#define     PWM36T1     (*(unsigned int  volatile xdata *)0xFC40)
#define     PWM36T2     (*(unsigned int  volatile xdata *)0xFC42)
#define     PWM36CR     (*(unsigned char volatile xdata *)0xFC44)
#define     PWM36HLD    (*(unsigned char volatile xdata *)0xFC45)
#define     PWM37T1     (*(unsigned int  volatile xdata *)0xFC48)
#define     PWM37T2     (*(unsigned int  volatile xdata *)0xFC4A)
#define     PWM37CR     (*(unsigned char volatile xdata *)0xFC4C)
#define     PWM37HLD    (*(unsigned char volatile xdata *)0xFC4D)
	
#define     PWM4C       (*(unsigned int  volatile xdata *)0xFC50)
#define     PWM4CKS     (*(unsigned char volatile xdata *)0xFC52)
#define     PWM4IF      (*(unsigned char volatile xdata *)0xFC55)
#define     PWM4FDCR    (*(unsigned char volatile xdata *)0xFC56)
#define     PWM40T1     (*(unsigned int  volatile xdata *)0xFC60)
#define     PWM40T2     (*(unsigned int  volatile xdata *)0xFC62)
#define     PWM40CR     (*(unsigned char volatile xdata *)0xFC64)
#define     PWM40HLD    (*(unsigned char volatile xdata *)0xFC65)
#define     PWM41T1     (*(unsigned int  volatile xdata *)0xFC68)
#define     PWM41T2     (*(unsigned int  volatile xdata *)0xFC6A)
#define     PWM41CR     (*(unsigned char volatile xdata *)0xFC6C)
#define     PWM41HLD    (*(unsigned char volatile xdata *)0xFC6D)
#define     PWM42T1     (*(unsigned int  volatile xdata *)0xFC70)
#define     PWM42T2     (*(unsigned int  volatile xdata *)0xFC72)
#define     PWM42CR     (*(unsigned char volatile xdata *)0xFC74)
#define     PWM42HLD    (*(unsigned char volatile xdata *)0xFC75)
#define     PWM43T1     (*(unsigned int  volatile xdata *)0xFC78)
#define     PWM43T2     (*(unsigned int  volatile xdata *)0xFC7A)
#define     PWM43CR     (*(unsigned char volatile xdata *)0xFC7C)
#define     PWM43HLD    (*(unsigned char volatile xdata *)0xFC7D)
#define     PWM44T1     (*(unsigned int  volatile xdata *)0xFC80)
#define     PWM44T2     (*(unsigned int  volatile xdata *)0xFC82)
#define     PWM44CR     (*(unsigned char volatile xdata *)0xFC84)
#define     PWM44HLD    (*(unsigned char volatile xdata *)0xFC85)
#define     PWM45T1     (*(unsigned int  volatile xdata *)0xFC88)
#define     PWM45T2     (*(unsigned int  volatile xdata *)0xFC8A)
#define     PWM45CR     (*(unsigned char volatile xdata *)0xFC8C)
#define     PWM45HLD    (*(unsigned char volatile xdata *)0xFC8D)
#define     PWM46T1     (*(unsigned int  volatile xdata *)0xFC90)
#define     PWM46T2     (*(unsigned int  volatile xdata *)0xFC92)
#define     PWM46CR     (*(unsigned char volatile xdata *)0xFC94)
#define     PWM46HLD    (*(unsigned char volatile xdata *)0xFC95)
#define     PWM47T1     (*(unsigned int  volatile xdata *)0xFC98)
#define     PWM47T2     (*(unsigned int  volatile xdata *)0xFC9A)
#define     PWM47CR     (*(unsigned char volatile xdata *)0xFC9C)
#define     PWM47HLD    (*(unsigned char volatile xdata *)0xFC9D)
	                                
#define     PWM5C       (*(unsigned int  volatile xdata *)0xFCA0)
#define     PWM5CKS     (*(unsigned char volatile xdata *)0xFCA2)
#define     PWM5IF      (*(unsigned char volatile xdata *)0xFCA5)
#define     PWM5FDCR    (*(unsigned char volatile xdata *)0xFCA6)
#define     PWM50T1     (*(unsigned int  volatile xdata *)0xFCB0)
#define     PWM50T2     (*(unsigned int  volatile xdata *)0xFCB2)
#define     PWM50CR     (*(unsigned char volatile xdata *)0xFCB4)
#define     PWM50HLD    (*(unsigned char volatile xdata *)0xFCB5)
#define     PWM51T1     (*(unsigned int  volatile xdata *)0xFCB8)
#define     PWM51T2     (*(unsigned int  volatile xdata *)0xFCBA)
#define     PWM51CR     (*(unsigned char volatile xdata *)0xFCBC)
#define     PWM51HLD    (*(unsigned char volatile xdata *)0xFCBD)
#define     PWM52T1     (*(unsigned int  volatile xdata *)0xFCC0)
#define     PWM52T2     (*(unsigned int  volatile xdata *)0xFCC2)
#define     PWM52CR     (*(unsigned char volatile xdata *)0xFCC4)
#define     PWM52HLD    (*(unsigned char volatile xdata *)0xFCC5)
#define     PWM53T1     (*(unsigned int  volatile xdata *)0xFCC8)
#define     PWM53T2     (*(unsigned int  volatile xdata *)0xFCCA)
#define     PWM53CR     (*(unsigned char volatile xdata *)0xFCCC)
#define     PWM53HLD    (*(unsigned char volatile xdata *)0xFCCD)
#define     PWM54T1     (*(unsigned int  volatile xdata *)0xFCD0)
#define     PWM54T2     (*(unsigned int  volatile xdata *)0xFCD2)
#define     PWM54CR     (*(unsigned char volatile xdata *)0xFCD4)
#define     PWM54HLD    (*(unsigned char volatile xdata *)0xFCD5)
#define     PWM55T1     (*(unsigned int  volatile xdata *)0xFCD8)
#define     PWM55T2     (*(unsigned int  volatile xdata *)0xFCDA)
#define     PWM55CR     (*(unsigned char volatile xdata *)0xFCDC)
#define     PWM55HLD    (*(unsigned char volatile xdata *)0xFCDD)
#define     PWM56T1     (*(unsigned int  volatile xdata *)0xFCE0)
#define     PWM56T2     (*(unsigned int  volatile xdata *)0xFCE2)
#define     PWM56CR     (*(unsigned char volatile xdata *)0xFCE4)
#define     PWM56HLD    (*(unsigned char volatile xdata *)0xFCE5)
#define     PWM57T1     (*(unsigned int  volatile xdata *)0xFCE8)
#define     PWM57T2     (*(unsigned int  volatile xdata *)0xFCEA)
#define     PWM57CR     (*(unsigned char volatile xdata *)0xFCEC)
#define     PWM57HLD    (*(unsigned char volatile xdata *)0xFCED)


#elif (STC8A == 1)

sfr PWMCR       =   0xfe;
sfr PWMFDCR     =   0xf7;
sfr PWMIF       =   0xf6;
sfr PWMCFG      =   0xf1;

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define PWM0T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM0T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM0CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM0HLD     (*(unsigned char volatile xdata *)0xff05)
#define PWM1T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM1T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM1CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM1HLD     (*(unsigned char volatile xdata *)0xff15)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM2HLD     (*(unsigned char volatile xdata *)0xff25)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM3HLD     (*(unsigned char volatile xdata *)0xff35)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM4HLD     (*(unsigned char volatile xdata *)0xff45)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff50)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff54)
#define PWM5HLD     (*(unsigned char volatile xdata *)0xff55)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff60)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff62)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff64)
#define PWM6HLD     (*(unsigned char volatile xdata *)0xff65)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff70)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff72)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff74)
#define PWM7HLD     (*(unsigned char volatile xdata *)0xff75)
	

#endif
/*  BIT Registers  */
/*  PSW   */
sbit CY   = PSW^7;
sbit AC   = PSW^6;
sbit F0   = PSW^5;
sbit RS1  = PSW^4;
sbit RS0  = PSW^3;
sbit OV   = PSW^2;
sbit F1   = PSW^1;
sbit P    = PSW^0;

/*  TCON  */
sbit TF1  = TCON^7;	//定时器1溢出中断标志位
sbit TR1  = TCON^6;	//定时器1运行控制位
sbit TF0  = TCON^5;	//定时器0溢出中断标志位
sbit TR0  = TCON^4;	//定时器0运行控制位
sbit IE1  = TCON^3;	//外中断1标志位
sbit IT1  = TCON^2;	//外中断1信号方式控制位，1：下降沿中断，0：上升下降均中断。
sbit IE0  = TCON^1;	//外中断0标志位
sbit IT0  = TCON^0;	//外中断0信号方式控制位，1：下降沿中断，0：上升下降均中断。

/*  P0  */
sbit  P00 = P0^0;
sbit  P01 = P0^1;
sbit  P02 = P0^2;
sbit  P03 = P0^3;
sbit  P04 = P0^4;
sbit  P05 = P0^5;
sbit  P06 = P0^6;
sbit  P07 = P0^7;

/*  P1  */
sbit  P10 = P1^0;
sbit  P11 = P1^1;
sbit  P12 = P1^2;
sbit  P13 = P1^3;
sbit  P14 = P1^4;
sbit  P15 = P1^5;
sbit  P16 = P1^6;
sbit  P17 = P1^7;

sbit  RXD2      = P1^0;
sbit  TXD2      = P1^1;
sbit  CCP1      = P1^0;
sbit  CCP0      = P1^1;
sbit  SPI_SS_1    = P1^2;
sbit  SPI_MOSI_1  = P1^3;
sbit  SPI_MISO_1  = P1^4;
sbit  SPI_SCLK_1  = P1^5;

sbit  SPI_SS_2    = P2^2;
sbit  SPI_MOSI_2  = P2^3;
sbit  SPI_MISO_2  = P2^4;
sbit  SPI_SCLK_2  = P2^5;

sbit  SPI_SS_3    = P5^4;
sbit  SPI_MOSI_3  = P4^0;
sbit  SPI_MISO_3  = P4^1;
sbit  SPI_SCLK_3  = P4^3;

sbit  SPI_SS_4    = P3^5;
sbit  SPI_MOSI_4  = P3^4;
sbit  SPI_MISO_4  = P3^3;
sbit  SPI_SCLK_4  = P3^2;

/*  P2  */
sbit  P20 = P2^0;
sbit  P21 = P2^1;
sbit  P22 = P2^2;
sbit  P23 = P2^3;
sbit  P24 = P2^4;
sbit  P25 = P2^5;
sbit  P26 = P2^6;
sbit  P27 = P2^7;

/*  P3  */
sbit  P30 = P3^0;
sbit  P31 = P3^1;
sbit  P32 = P3^2;
sbit  P33 = P3^3;
sbit  P34 = P3^4;
sbit  P35 = P3^5;
sbit  P36 = P3^6;
sbit  P37 = P3^7;

sbit RXD  = P3^0;
sbit TXD  = P3^1;
sbit INT0 = P3^2;
sbit INT1 = P3^3;
sbit T0   = P3^4;
sbit T1   = P3^5;
sbit WR   = P3^6;
sbit RD   = P3^7;
sbit CCP2  = P3^7;

sbit CLKOUT0   = P3^5;
sbit CLKOUT1   = P3^4;

/*  P4  */
sbit  P40 = P4^0;
sbit  P41 = P4^1;
sbit  P42 = P4^2;
sbit  P43 = P4^3;
sbit  P44 = P4^4;
sbit  P45 = P4^5;
sbit  P46 = P4^6;
sbit  P47 = P4^7;

/*  P5  */
sbit  P50 = P5^0;
sbit  P51 = P5^1;
sbit  P52 = P5^2;
sbit  P53 = P5^3;
sbit  P54 = P5^4;
sbit  P55 = P5^5;
sbit  P56 = P5^6;
sbit  P57 = P5^7;

/*  P6  */
sbit  P60 = P6^0;
sbit  P61 = P6^1;
sbit  P62 = P6^2;
sbit  P63 = P6^3;
sbit  P64 = P6^4;
sbit  P65 = P6^5;
sbit  P66 = P6^6;
sbit  P67 = P6^7;

/*  P7  */
sbit  P70 = P7^0;
sbit  P71 = P7^1;
sbit  P72 = P7^2;
sbit  P73 = P7^3;
sbit  P74 = P7^4;
sbit  P75 = P7^5;
sbit  P76 = P7^6;
sbit  P77 = P7^7;


/*  SCON  */
sbit SM0  = SCON^7;	//SM0/FE		SM0 SM1 = 00 ~ 11: 方式0~3
sbit SM1  = SCON^6;	//
sbit SM2  = SCON^5;	//多机通讯
sbit REN  = SCON^4;	//接收允许
sbit TB8  = SCON^3;	//发送数据第8位
sbit RB8  = SCON^2;	//接收数据第8位
sbit TI   = SCON^1;	//发送中断标志位
sbit RI   = SCON^0;	//接收中断标志位

/*  IE   */
sbit EA   = IE^7;	//中断允许总控制位
sbit ELVD = IE^6;	//低压监测中断允许位
sbit EADC = IE^5;	//ADC 中断 允许位
sbit ES   = IE^4;	//串行中断 允许控制位
sbit ET1  = IE^3;	//定时中断1允许控制位
sbit EX1  = IE^2;	//外部中断1允许控制位
sbit ET0  = IE^1;	//定时中断0允许控制位
sbit EX0  = IE^0;	//外部中断0允许控制位

sbit ACC0 = ACC^0;
sbit ACC1 = ACC^1;
sbit ACC2 = ACC^2;
sbit ACC3 = ACC^3;
sbit ACC4 = ACC^4;
sbit ACC5 = ACC^5;
sbit ACC6 = ACC^6;
sbit ACC7 = ACC^7;

sbit B0 = B^0;
sbit B1 = B^1;
sbit B2 = B^2;
sbit B3 = B^3;
sbit B4 = B^4;
sbit B5 = B^5;
sbit B6 = B^6;
sbit B7 = B^7;

//                                          7     6     5    4    3    2    1    0    Reset Value
//sfr IP      = 0xB8; //中断优先级低位      PPCA  PLVD  PADC  PS   PT1  PX1  PT0  PX0   0000,0000
//--------
sbit PPCA	= IP^7;	//PCA 模块中断优先级
sbit PLVD	= IP^6;	//低压监测中断优先级
sbit PADC	= IP^5;	//ADC 中断优先级
sbit PS   	= IP^4;	//串行中断1优先级设定位
sbit PT1	= IP^3;	//定时中断1优先级设定位
sbit PX1	= IP^2;	//外部中断1优先级设定位
sbit PT0	= IP^1;	//定时中断0优先级设定位
sbit PX0	= IP^0;	//外部中断0优先级设定位



//                                           7      6      5     4     3     2    1     0        Reset Value
//sfr IPH   = 0xB7; //中断优先级高位         -    PLVDH  PADCH  PSH  PT1H  PX1H  PT0H  PX0H      0000,0000
#define		PPCAH	0x80
#define		PLVDH	0x40
#define		PADCH	0x20
#define		PSH		0x10
#define		PT1H	0x08
#define		PX1H	0x04
#define		PT0H	0x02
#define		PX0H	0x01

//sfr IP2   = 0xB5; //                       PUSB  PI2C   PCMP   PX4  PPWM2  PPWM1 PSPI PS2       0000,0000
#define PUSB        0x80
#define PI2C        0x40
#define PCMP        0x20
#define PX4         0x10
#define PPWM2       0x08
#define PPWM1       0x04
#define PSPI        0x02
#define PS2         0x01

//sfr IP2H  = 0xB6; // -                     PUSBH PI2CH PCMPH PX4H PPWM2H PPWM1H PSPIH PS2H      0000,0000
#define PUSBH       0x80
#define PI2CH       0x40
#define PCMPH       0x20
#define PX4H        0x10
#define PPWM2H      0x08
#define PPWM1H      0x04
#define PSPIH       0x02
#define PS2H        0x01

//sfr IP3   = 0xDF;
//sfr IP3H  = 0xEE;
#define PS3         0x01
#define PS4         0x02

/* 设置中断优先级 n范围： 0-3  3优先级最高 */
#define SET_INT0_PRIORITY(n)    PX0 = n%2,  (n>1) ? (IPH |= PX0H ): (IPH &= ~PX0H  )      //设置外部中断0优先级
#define SET_TIMER0_PRIORITY(n)  PT0 = n%2,  (n>1) ? (IPH |= PT0H ): (IPH &= ~PT0H  )      //设置定时中断0优先级
#define SET_INT1_PRIORITY(n)    PX1 = n%2,  (n>1) ? (IPH |= PX1H ): (IPH &= ~PX1H  )      //设置外部中断1优先级
#define SET_TIMER1_PRIORITY(n)  PT1 = n%2,  (n>1) ? (IPH |= PT1H ): (IPH &= ~PT1H  )      //设置定时中断1优先级
#define SET_UART1_PRIORITY(n)   PS  = n%2,  (n>1) ? (IPH |= PSH  ): (IPH &= ~PSH   )      //设置串行中断1优先级
#define SET_ADC_PRIORITY(n)     PADC= n%2,  (n>1) ? (IPH |= PADCH): (IPH &= ~PADCH )      // ADC 中断优先级
#define SET_LADC_PRIORITY(n)    PLVD= n%2,  (n>1) ? (IPH |= PLVDH): (IPH &= ~PLVDH )      // 低压监测中断优先级

#define SET_USB_PRIORITY(n)     (n%2 == 0) ? (IP2 &= ~PUSB ) : (IP2 |= PUSB );   (n>1) ? (IP2H |= PUSBH ) : (IP2H &= ~PUSBH )  //设置USB中断优先级
#define SET_IIC_PRIORITY(n)     (n%2 == 0) ? (IP2 &= ~PI2C ) : (IP2 |= PI2C );   (n>1) ? (IP2H |= PI2CH ) : (IP2H &= ~PI2CH )  //设置IIC中断优先级
#define SET_PCMP_PRIORITY(n)    (n%2 == 0) ? (IP2 &= ~PCMP ) : (IP2 |= PCMP );   (n>1) ? (IP2H |= PCMPH ) : (IP2H &= ~PCMPH )  //设置比较器中断优先级
#define SET_INT4_PRIORITY(n)    (n%2 == 0) ? (IP2 &= ~PX4  ) : (IP2 |= PX4  );   (n>1) ? (IP2H |= PX4H  ) : (IP2H &= ~PX4H  )  //设置外部中断4优先级
#define SET_PWM2_PRIORITY(n)    (n%2 == 0) ? (IP2 &= ~PPWM2) : (IP2 |= PPWM2);   (n>1) ? (IP2H |= PPWM2H) : (IP2H &= ~PPWM2H)  //设置PWM2中断优先级
#define SET_PWM1_PRIORITY(n)    (n%2 == 0) ? (IP2 &= ~PPWM1) : (IP2 |= PPWM1);   (n>1) ? (IP2H |= PPWM1H) : (IP2H &= ~PPWM1H)  //设置PWM1中断优先级
#define SET_SPI_PRIORITY(n)     (n%2 == 0) ? (IP2 &= ~PSPI ) : (IP2 |= PSPI );   (n>1) ? (IP2H |= PSPIH ) : (IP2H &= ~PSPIH )  //设置SPI中断优先级
#define SET_UART2_PRIORITY(n)   (n%2 == 0) ? (IP2 &= ~PS2  ) : (IP2 |= PS2  );   (n>1) ? (IP2H |= PS2H  ) : (IP2H &= ~PS2H  )  //设置串口2中断优先级
                                                                                                                             
#define SET_UART3_PRIORITY(n)   (n%2 == 0) ? (IP3 &= ~PS3  ) : (IP3 |= PS3  );   (n>1) ? (IP3H |= PS3   ) : (IP3H &= ~PS3   ) //设置串口3中断优先级
#define SET_UART4_PRIORITY(n)   (n%2 == 0) ? (IP3 &= ~PS4  ) : (IP3 |= PS4  );   (n>1) ? (IP3H |= PS4   ) : (IP3H &= ~PS4   ) //设置串口4中断优先级
/*************************************************************************************************/


/**********************************************************/
//						   7     6       5      4     3      2      1      0    Reset Value
//sfr AUXR  = 0x8E;		T0x12 T1x12 UART_M0x6  T2R  T2_C/T T2x12 EXTRAM  S1ST2  0000,0000	//Auxiliary Register 

#define 	ExternalRAM_enable()		AUXR |=  2		/* 允许外部XRAM，禁止使用内部8k RAM     */
#define 	InternalRAM_enable()		AUXR &= ~2		/* 禁止外部XRAM，允许使用内部8k RAM     */
#define		S1_M0x6()					AUXR |=  (1<<5)	/* UART Mode0 Speed is 6x Standard       */
#define		S1_M0x1()					AUXR &= ~(1<<5)	/* default,	UART Mode0 Speed is Standard */



/* 看门狗 */
//sfr WDT_CONTR = 0xC1; //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
#define D_WDT_FLAG			(1<<7)
#define D_EN_WDT			(1<<5)
#define D_CLR_WDT			(1<<4)	/* auto clear	*/
#define D_IDLE_WDT			(1<<3)	/* WDT counter when Idle	*/
#define D_WDT_SCALE_2		0
#define D_WDT_SCALE_4		1
#define D_WDT_SCALE_8		2		/* 看门狗溢出时间 T = 12*393216 * (2^D_WDT_SCALE_x) / MAIN_Fosc	*/
#define D_WDT_SCALE_16		3
#define D_WDT_SCALE_32		4
#define D_WDT_SCALE_64		5
#define D_WDT_SCALE_128		6
#define D_WDT_SCALE_256		7

#define	WDT_Init(n)	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + (n)		/* 初始化WDT，喂狗 */
#define WDT_Clear() WDT_CONTR &= ~D_CLR_WDT



//						  7     6      5    4     3      2    1     0     Reset Value
//sfr PCON   = 0x87;	SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000	 //Power Control 
//SMOD		//串口双倍速
//SMOD0
#define		LVDF		(1<<5)	/* P4.6低压检测标志 */
//POF
//GF1
//GF0
//#define 	D_PD		2		/* set 1, power down mode */
//#define 	D_IDLE		1		/* set 1, idle mode */
#define		MCU_IDLE()			PCON |= 1	/* MCU 进入 IDLE 模式 */
#define		MCU_POWER_DOWN()	PCON |= 2	/* MCU 进入 睡眠 模式 */



/**********************************************************/
typedef 	unsigned char	uint8_t;
typedef 	char	        int8_t;
typedef 	unsigned int	uint16_t;
typedef 	int	            int16_t;
typedef 	unsigned long	uint32_t;
typedef 	long	        int32_t;
/**********************************************************/
#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP50() NOP10(),NOP40()
#define NOP100() NOP50(),NOP50()
#define NOP200() NOP100(),NOP100()
#define NOP(N)  NOP##N()




//sfr INT_CLKO = 0x8F;	//附加的 SFR WAKE_CLKO (地址：0x8F)
#define		LVD_InterruptEnable()		ELVD = 1
#define		LVD_InterruptDisable()		ELVD = 0


//sfr WKTCL = 0xAA;	//STC11F\10和STC15系列 唤醒定时器低字节
//sfr WKTCH = 0xAB;	//STC11F\10和STC15系列 唤醒定时器高字节
//	B7		B6	B5	B4	B3	B2	B1	B0		B7	B6	B5	B4	B3	B2	B1	B0
//	WKTEN				S11	S10	S9	S8		S7	S6	S5	S4	S3	S2	S1	S0	n * 560us
#define		WakeTimerDisable()		WKTCH &= 0x7f	/* WKTEN = 0		禁止睡眠唤醒定时器 */
#define		WakeTimerSet(scale)		WKTCL = (scale) % 256,WKTCH = (scale) / 256 | 0x80	/* WKTEN = 1	允许睡眠唤醒定时器 */



#define	TRUE	1
#define	FALSE	0

//=============================================================

//========================================

#define	PolityLow			0	//低优先级中断
#define	PolityHigh			1	//高优先级中断

//========================================

#define		ENABLE		1
#define		DISABLE		0


#endif
