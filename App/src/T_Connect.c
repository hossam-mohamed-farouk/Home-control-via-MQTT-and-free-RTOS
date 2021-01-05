/*
 * T_Connect.c
 *
 * Created: 7/20/2020 11:40:36 AM
 *  Author: H
 */ 

#include "T_Connect.h"

U_8 system_up = 0;

void T_Connect(void* pvData)
{
	EventBits_t ebValues = 0;
	
	while(1)
	{
		if (xSemaphoreTake(bsConnect, portMAX_DELAY))
		{
			/*Connect MQTT*/
			MQTT_Connect("HMF95");
			/*CONACK*/
			ebValues = xEventGroupWaitBits(egMQTT,E_MQTT_CONNACK,1,0,5000);			
			if (ebValues&E_MQTT_CONNACK)
			{
				/*Connect succeed*/
				  /*Subscribe*/
				vTaskDelay(1000);
				//MQTT_Sbscribe("control");
				
				MQTT_Sbscribe("NTI");
				ebValues = xEventGroupWaitBits(egMQTT,E_MQTT_SUBACK,1,0,5000);	
				/*SUBACK*/
				if (ebValues&E_MQTT_SUBACK)
				{
					  /* Done */
					system_up = 1;
					
				} 
				else
				{
					xSemaphoreGive(bsConnect);
				}
			}
			else
			{
				//system_up = 0;
				xSemaphoreGive(bsConnect);
			}
		}
	}
}