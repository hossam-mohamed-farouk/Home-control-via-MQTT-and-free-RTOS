/*
 * app.c
 *
 * Created: 7/20/2020 11:32:53 AM
 *  Author: H
 */ 

#include "app.h"

/*OS services*/
/* semaphore to communicate with the MQTT Broker */
xSemaphoreHandle	bsConnect;						
/*msg_queue*/
xQueueHandle		mqControl;						
/*event_group*/
EventGroupHandle_t	egMQTT;	
/*event_group_bits*/			
EventBits_t			ebValMQTT;						

int main(void)
{
	system_init();
	/*Create OS services*/
	vSemaphoreCreateBinary(bsConnect,1);
	mqControl = xQueueCreate(2,30);
	egMQTT = xEventGroupCreate();
	/*Create Tasks*/
	xTaskCreate(T_Monitor,"T_Monitor",100,NULL,1,NULL);
	xTaskCreate(T_Control,"T_Control",100,NULL,2,NULL);
	xTaskCreate(T_Connect,"T_Connect",100,NULL,3,NULL);
	xTaskCreate(T_RespHandle,"T_RespHandle",100,NULL,4,NULL);
	/*Start OS*/
	vTaskStartScheduler();
}

void system_init(void)
{
	led_init();
	leds_init(0x03);
	adc_b_init();
	MQTT_Init();
}