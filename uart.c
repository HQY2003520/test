#include <REGX52.H>
/*
���ڳ�ʼ��
*/
void UartInit(void)		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xF4;		//���ö�ʱ��ʼֵ
	TH1 = 0xF4;		//���ö�ʱ����ֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	EA  =1;         //��ʱ����
	ES  =1;        //�ж�ʹ��
}
/*
����һ�ֽ�
byte�������͵�����

*/
void Uart_sendbyte(unsigned char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}
//�жϷ�����
/*
	void int0() interrupt 4
	{
		if(RI==1)
		{
		 P2=SBUF;					//�ж�SBUF�е�����Ϊ��Ƭ�����յ�����
		 Uart_sendbyte(SBUF);		//����Է����յ�������
		 TI=0;
		 RI=0;
			
		}
	}
*/