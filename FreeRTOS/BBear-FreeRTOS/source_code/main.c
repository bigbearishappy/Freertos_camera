#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void systeminit()
{
	GPIO_InitTypeDef GPIO_InitTypeStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitTypeStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitTypeStruct);
}

void delay()
{
	int i = 0, j = 0;
	for(i = 0;i < 1000; i++)
		for(j = 0; j < 1000; j++);
}

void LED1_FUN(void *pvParameters)
{
	for(;;){
		vTaskDelay(100);
		GPIO_ResetBits(GPIOC, GPIO_Pin_10);
		vTaskDelay(100);
		GPIO_SetBits(GPIOC, GPIO_Pin_10);
	}
}

void LED2_FUN(void *pvParameters)
{
	for(;;){
		vTaskDelay(200);
		GPIO_SetBits(GPIOC, GPIO_Pin_11);
		vTaskDelay(200);
		GPIO_ResetBits(GPIOC, GPIO_Pin_11);
	}
}

int main()
{
	systeminit();
	
	xTaskCreate( LED1_FUN, "LED1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( LED2_FUN, "LED2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );
	
	vTaskStartScheduler();
	return 0;
}
