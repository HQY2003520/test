#include <REGX52.H>

/*
���ʹ��
*/
sbit ENA = P1^2;
sbit ENB = P1^7;

/*
SG90���
*/
sbit PWM=P2^5;//����ź�

unsigned int  counter=0;
unsigned int  compare=3;
unsigned int  EN_counter=0;
unsigned int  ENA_compare=60;
unsigned int  ENB_compare=60;

void Timer1Init(void)		//500΢��@11.0592MHz
{
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x10;		//���ö�ʱ��ģʽ
	TL1 = 0x33;		//���ö�ʱ��ʼֵ
	TH1 = 0xFE;		//���ö�ʱ��ʼֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	EA=1;
	ET1=1;
	PT1=1;
}

void Timer2Init(void)		//100΢��@11.0592MHz
{
	T2MOD = 0;		//��ʼ��ģʽ�Ĵ���
	T2CON = 0;		//��ʼ�����ƼĴ���
	TL2 = 0xA4;		//���ö�ʱ��ʼֵ
	TH2 = 0xFF;		//���ö�ʱ��ʼֵ
	RCAP2L = 0xA4;		//���ö�ʱ����ֵ
	RCAP2H = 0xFF;		//���ö�ʱ����ֵ
	TR2 = 1;		//��ʱ��2��ʼ��ʱ
	ET2=1;
	EA=1;
	PT2=0;
}

void Timer_T1(void) interrupt 3
{
	TL1 = 0x33;		//���ö�ʱ��ʼֵ
	TH1 = 0xFE;		//���ö�ʱ��ʼֵ
	
	counter++;
	
	if(counter>40)
	{
		counter=0;
	}
	
	if(counter<compare)
	{
		PWM=1;
	}
	else
	{
		PWM=0;
	}
	
}

void EN_PWM() interrupt 5
{
	RCAP2L = 0xA4;		//���ö�ʱ����ֵ
	RCAP2H = 0xFF;		//���ö�ʱ����ֵ
	TF2=0;              //��λ����
	
	EN_counter++;
				
				if(EN_counter>100)
				{
					EN_counter=0;
				}
				
	if(EN_counter<ENA_compare)
	{
		ENA=1;
	}
	else
	{
		ENA=0;
	}
		if(EN_counter<ENB_compare)
		{
			ENB=1;
		}
		else
		{
			ENB=0;
		}
}

