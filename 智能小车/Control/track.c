#include <REGX52.H>
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

//unsigned char a;
//unsigned char b;
//unsigned char c;
//unsigned char d;
//unsigned char e;

//void Track()
//{							
//							if(AL==1&&BL==1&&CL==1&&DL==1&&EL==1)          //�˳�ѭ��ģʽ       ȫ����Ϊ11111
//								{		
//									ENA_compare=50;                        //������ʼת��
//									ENB_compare=50;									//�ҵ����ʼת��
//									Go_move();
//								}
//							if(AL==0&&BL==0&&CL==0&&DL==0&&EL==0)          //����       ȫ��Ϊ00000
//							{
//									
//									ENA_compare=50;                        			//������ʼת��
//									ENB_compare=50;									//�ҵ����ʼת��
//									Stop_move();
//							}
//							else
//							{
//								
//								a=AL;
//								b=BL;
//								c=CL;
//								d=DL;
//								e=EL;	
//									if(a+b>d+e)//���������
//                                       {
//												ENA_compare=40;                        			//������ʼת��
//												ENB_compare=40;									//�ҵ����ʼת��										
//												Left_move();               //��ת
//				
//											
//										}
//									if(a+b<d+e)//�������ұ�
//										{
//											    ENA_compare=40;                        			//������ʼת��
//											    ENB_compare=40;									//�ҵ����ʼת��
//											    Right_move();												//��ת
//										}
//									if((a&&b&&d&&e)&&!c)
//									{
//											    ENA_compare=25;                        			//������ʼת��
//											    ENB_compare=25;									//�ҵ����ʼת��
//											    Go_move();               //ֱ��										
//									
//									}
//							}	
//}

void Track()   
{	

	if(AL==1&&BL==1&&CL==0&&DL==1&&EL==1)      //С�����߶����յ������ߺ������м�С��ֱ��       00100
		{
			Go_move();			
		}
	else if(AL==1&&BL==0&&DL==1&&EL==1)          //С���ұ�ɨ�赽���ߣ���΢ƫ��  С��Ӧ�������ƶ�  10111
		{                                           
			ENA_compare=60;			                        //������ʼת��
			ENB_compare=25;          			              //�ҵ����ʼת��
			Go_move();
		}				
	else if(AL==1&&BL==1&&DL==0&&EL==1)          //С�����ɨ�赽���ߣ���΢ƫ�ң� С��Ӧ�������ƶ�     11101
		{			
			ENA_compare=25;                        //������ʼת��
			ENB_compare=60;                        //�ҵ����ʼת��
			Go_move();
		}
	else if(AL==0&&BL==1&&DL==1&&EL==1)  		   //С���ұ�ɨ�赽���ߣ�תСȦ��  С��Ӧ�������ƶ�  01111
		{							
			ENA_compare=35;                        //������ʼת��
			ENB_compare=35;                        //�ҵ����ʼת��
			Right_move();
			while(BL==1);
		}
	else if(AL==0&&BL==0&&EL==1)  		   //С���ұ�ɨ�赽���ߣ�תСȦ��  С��Ӧ�������ƶ�  00111
		{				
			ENA_compare=40;                        //������ʼת��
			ENB_compare=40;                        //�ҵ����ʼת��
			Right_move();
			while(CL==1);
		}					
	else if(AL==1&&BL==1&&DL==1&&EL==0)      //С�����ɨ�赽���ߣ�תСȦ��  С��Ӧ�������ƶ�  11110
		{			
			ENA_compare=35;                        //������ʼת��
			ENB_compare=35;                        //�ҵ����ʼת��
			Left_move();
			while(DL==1);
		}
	else if(AL==1&&DL==0&&EL==0)      //С�����ɨ�赽���ߣ�תСȦ��  С��Ӧ�������ƶ�  11100
		{			
			ENA_compare=40;                        //������ʼת��
			ENB_compare=40;                        //�ҵ����ʼת��
			Left_move();
			while(CL==1);
		}
	else
	{
			if(AL==0&&BL==0&&CL==0&&DL==0&&EL==0)          //�˳�ѭ��ģʽ       ȫ��Ϊ11111
			{
				
				ENA_compare=50;                        //������ʼת��
				ENB_compare=50;                        //�ҵ����ʼת��
				Stop_move();
			}
			if(AL==1&&BL==1&&CL==1&&DL==1&&EL==1)          //�˳�ѭ��ģʽ       ȫ��Ϊ11111
			{
				
				ENA_compare=50;                        //������ʼת��
				ENB_compare=50;                        //�ҵ����ʼת��
				Go_move();
			}
	}
	
	
}

