#include <REGX52.H>
#include <delay.h>

#define C 15           //�����¶�
#define MHZ  11.0592   //��Ƭ������Ƶ��

sbit Trig=P0^0;
sbit Echo=P3^2;

void Timer0Init(void)		//������
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x09;		//���ö�ʱ��ģʽ
	TL1 = 0x00;		//���ö�ʱ��ʼֵ
	TH1 = 0x00;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;        //��ʱ�����ἴ��ʼ
}

void ultra_init(void)//������
{
	Trig=0;
	Echo=0;
	Timer0Init();
}

int get_distance(void)
{
	unsigned char timeH,timeL;
	unsigned int distance,time;
	unsigned int time_counter=0;
	Trig=1;
	Delay10us(1);
	Trig=0;
	Echo=1;
	 while(!Echo)//�ȴ�
	 {
		time_counter++;
		 Delay10us(1);
		 if(time_counter>10000)
		 {
			return -1;//����
		 }
	 }
	 time_counter=0;
     while(Echo)//�ȴ�
	 {
		time_counter++;
		Delay10us(1);
		 if(time_counter>10000)
		 {
			return -2;//����
		 }
	 }
     timeH =TH0;
	 timeL =TL0;
	 TH0=0;//���ü�����
	 TL0=0;
     time=timeH*256+timeL;
	 if(time>70000)return -3;//����
	 distance=time*(MHZ/12)/10000*170;//���룺CM
	 return distance;

}