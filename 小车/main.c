#include <REGX52.H>
#include <HCSR04.h>
#include <delay.h>

/*
���
*/
sbit IN1 = P3^4;
sbit IN2 = P3^5;
sbit IN3 = P3^6;
sbit IN4 = P3^7;

/*
ѭ������
*/
sbit AL =P2^0;
sbit BL =P2^1;
sbit CL =P2^2;
sbit DL =P2^3;
sbit EL =P2^4;

/*
���Һ���
*/
sbit LLED =P0^6;
sbit RLED =P0^7;

/*
SG90���
*/
sbit PWM=P1^0;//����ź�


void Timer1Init(void)		//100΢��@11.0592MHz
{
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0xAE;		//���ö�ʱ��ʼֵ
	TH1 = 0xFB;		//���ö�ʱ��ʼֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ET1=1;
	EA=1;
}



/*
		//ǰ��
		IN1=1;//���
		IN2=0;
		
		IN3=1;//�ұ�
		IN4=0;
*/
/*
		//��ת
		IN1=0;//���
		IN2=1;
		
		IN3=1;//�ұ�
		IN4=0;
*/
/*
		//��ת
		IN1=1;//���
		IN2=0;
		
		IN3=0;//�ұ�
		IN4=1;
*/

unsigned int  lenth,Lr,Ll;
unsigned int  L=10;//10cm
unsigned int counter=0,compare=10;


void main(void)
{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	unsigned char e;
	ultra_init();
	Timer1Init();
	while(1)
	{	
		a=AL;
		b=BL;
		c=CL;
		d=DL;
		e=EL;
		lenth=get_distance();
		if(lenth>L)
		{
				if(LLED==RLED)
				{
								IN1=1;//���//ǰ��
								IN2=0;
								IN3=1;//�ұ�
								IN4=0;
								if(a+b>d+e)//���������
								{
									//��ת
									IN1=0;//���
									IN2=1;
									IN3=1;//�ұ�
									IN4=0;
								}
								else if(a+b<d+e)//�������ұ�
								{
									//��ת
									IN1=1;//���
									IN2=0;
									IN3=0;//�ұ�
									IN4=1;
								}
								else//����ƫ��
								{
									//ǰ��
									IN1=1;//���
									IN2=0;
									IN3=1;//�ұ�
									IN4=0;	
								}
				}
				else
				{
					if(RLED==0)
					{
						//��ת
						IN1=1;//���
						IN2=1;
						
						IN3=1;//�ұ�
						IN4=0;
					}
					else
					{
						//��ת
						IN1=1;//���
						IN2=0;
						
						IN3=1;//�ұ�
						IN4=1;
					}
				}
		}
		else
		{
			//ֹͣ
			IN1=1;//���
			IN2=1;			
			IN3=1;//�ұ�
			IN4=1;
			
			Delay10us(15000);
			compare=4;//�ұ�
			Delay10us(25000);
			Lr=get_distance();
			Delay10us(25000);
			compare=15;//���
			Delay10us(25000);
			Ll=get_distance();
			Delay10us(25000);
			compare=10;//��λ��ǰ
					if(Lr>Ll||Lr<0)
					{
						//��ת
						IN1=1;//���
						IN2=0;	
						IN3=0;//�ұ�
						IN4=1;
					}
					else
					{
						//��ת
						IN1=0;//���
						IN2=1;
						IN3=1;//�ұ�
						IN4=0;
					}
					Delay10us(33500);
		}  
	}
}

void Timer_T1(void) interrupt 3
{
	TL1 = 0xAE;		//���ö�ʱ��ʼֵ
	TH1 = 0xFB;		//���ö�ʱ��ʼֵ
	if(counter<compare)
	{
		PWM=1;
	}
	else
	{
		PWM=0;
	}
	counter++;
	if(counter>200)
	{
		counter=0;
	}

}