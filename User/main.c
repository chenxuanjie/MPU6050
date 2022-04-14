#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "mpu6050.h"  
#include "inv_mpu.h"
#include "Delay.h"

float pitch,roll,yaw; 		//≈∑¿≠Ω«

int main(void)
{
	OLED_Init();
	MPU_Init();					//≥ı ºªØMPU6050
	
	while(mpu_dmp_init())
	{
		Delay_ms(20);
	}
	OLED_ShowString(1,1,"Hello World");
	while(1)
	{
		mpu_dmp_get_data(&pitch,&roll,&yaw);
		OLED_ShowSignedNum(2, 1, (int)pitch, 4);
		OLED_ShowSignedNum(3, 1, (int)roll, 8);
		OLED_ShowSignedNum(4, 1, (int)yaw, 8);
		
	}
}
