#ifndef __MPUIIC_H
#define __MPUIIC_H
#include "sys.h"

//��������
#define MPU6050_PEIPH	RCC_APB2Periph_GPIOB
#define MPU6050_GPIO	GPIOB
#define MPU6050_SCL		GPIO_Pin_8	
#define MPU6050_SDA		GPIO_Pin_9	

//IO��������
#define MPU_SDA_IN()  {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=8<<4;}
#define MPU_SDA_OUT() {GPIOB->CRH&=0XFFFFFF0F;GPIOB->CRH|=7<<4;}

//IO��������	 
#define MPU_IIC_SCL    PBout(8) 		//SCL
#define MPU_IIC_SDA    PBout(9) 		//SDA	 
#define MPU_READ_SDA   PBin(9) 		//����SDA 

//IIC���в�������
void MPU_IIC_Delay(void);				//MPU IIC��ʱ����
void Mpu6050_I2C_Init(void);                //��ʼ��IIC��IO��				 
void MPU_IIC_Start(void);				//����IIC��ʼ�ź�
void MPU_IIC_Stop(void);	  			//����IICֹͣ�ź�
void MPU_IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 Mpu6050_I2C_ReadByte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 MPU_IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void MPU_IIC_Ack(void);					//IIC����ACK�ź�
void MPU_IIC_NAck(void);				//IIC������ACK�ź�

void IMPU_IC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 MPU_IIC_Read_One_Byte(u8 daddr,u8 addr);	  
#endif
















