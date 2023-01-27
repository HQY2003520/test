#include <REGX52.H>
#include <Timer.h>
#include <Move.h>

/*
ѭ������
*/
sbit AL =P2^0;
sbit BL =P2^1;
sbit CL =P2^2;
sbit DL =P2^3;
sbit EL =P2^4;

extern unsigned int ENA_compare;
extern unsigned int ENB_compare; 
extern unsigned int EN_counter;
extern unsigned int compare;

void Track()   //1Ϊ�� 0Ϊ��   ��1   ��0     ��⵽����Ϊ��1   
{
	
	if(AL==1&&BL==1&&CL==1&&DL==1&&EL==1) 							//С������      ��ȫ��Ϊ11111
		{
			ENA_compare=75;                        //������ʼת��
			ENB_compare=75;                       //�ҵ����ʼת��
			Stop_move();
		}	
		
		
	if(AL==1&&BL==0&&CL==1&&DL==1&&EL==1)  //С���ұ�ɨ�赽���ߣ���΢ƫ��  С��Ӧ�������ƶ�  10111
		{
			ENA_compare=30;                           //������ʼת��
			ENB_compare=15;                       //�ҵ����ʼת��
			Go_move();
		}
		
	if(AL==0&&BL==1&&CL==1&&DL==1&&EL==1)  //С���ұ�ɨ�赽���ߣ�תСȦ��  С��Ӧ�������ƶ�  01111
		{
			
			ENA_compare=25;                           //������ʼת��
			ENB_compare=60;                       //�ҵ����ʼת��
			Go_move();
			
		}
		
	if(AL==1&&BL==1&&CL==1&&DL==0&&EL==1)  //С�����ɨ�赽���ߣ���΢ƫ�ң� С��Ӧ�������ƶ�     11101
		{
			
			ENA_compare=15;                           //������ʼת��
			ENB_compare=30;                       //�ҵ����ʼת��
			Go_move();
		}		
		
		if(AL==1&&BL==1&&CL==1&&DL==1&&EL==0)  //С�����ɨ�赽���ߣ�תСȦ��  С��Ӧ�������ƶ�  11110
		{
			
			ENA_compare=60;                           //������ʼת��
			ENB_compare=25;                       //�ҵ����ʼת��
			Go_move();
			
		}	
		
		
	if(AL==1&&BL==1&&CL==0&&DL==1&&EL==1)  //С�����߶����յ������ߺ������м�С��ֱ��      ȫ����Ϊ00100
		{
			
			ENA_compare=75;                        //������ʼת��
			ENB_compare=75;                       //�ҵ����ʼת��
			Go_move();			
		}
}

