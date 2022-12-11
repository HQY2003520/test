#include <REGX52.H>
#include <smg.h>

sbit MCN=P1^0;

unsigned int counter=0,compare=100,speed,key,a=0;

void UartInit(void)		//9600bps@11.0592MHz-----��
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;		//���ö�ʱ��ʼֵ
	TH1 = 0xFD;		//���ö�ʱ����ֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	EA=1;           //�����ж�
	ES=1;           //�ж�ʹ��
	PS=1;           //���ȼ�
}

void Timer0Init(void)		//10΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x91;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
}


void main()
{
	UartInit();
	Timer0Init();
	while(1)
	{
		if(a==0) compare=0;
		else if(speed==0) compare=30;
		else if(speed==1) compare=65;
		else if(speed==2) compare=100;
		SMG_Location_number(1,speed+1);
	}
}

void motor_PWM(void) interrupt 1// PWM
{	
	TL0 = 0x91;		                        //���ö�ʱ��ʼֵ
	TH0 = 0xFF;		                        //���ö�ʱ��ʼֵ
		if(counter <compare)   MCN=1;	   //on	
		else                   MCN=0;      //off 
		counter++;	
	    if(counter>100)        counter=0; 
}

void blue_teeth(void) interrupt 4
{
	key=SBUF;
	if(RI==1)
	{
		if(key==0xff)
		{
			speed+=1;                        //����
		}
		if(key==0xee)
		{
			a = ~a;                         //�������
		}
		RI=0;
	}
	speed%=3;
	
}