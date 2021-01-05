/*
 * T_Monitor.c
 *
 * Created: 7/20/2020 11:39:33 AM
 *  Author: H
 */ 

#include "T_Monitor.h"


void T_Monitor(void* pvData)
{
	U_8 temp = 0;
	U_16 adcValue = 0;
	EventBits_t ebValues = 0;
	
	while(1)
	{
		if (system_up == 1)
		{
			/* read temp from temp sensor */
			adcValue = adc_b_read(0);
			temp = ((adcValue/1023.0)*150);
			/*Publish temp*/
			MQTT_Publish("NTIU",&temp,1,1);
			/* Wait for pubACK*/
			ebValues = xEventGroupWaitBits(egMQTT,E_MQTT_PUBACK,1,0,5000);
		
			if (ebValues&E_MQTT_PUBACK)
			{
				/*Publish done*/
			} 
			else
			{
				system_up = 0;
				xSemaphoreGive(bsConnect);
			}
		}
		
		vTaskDelay(10000);  //10 sec >> 10 * ticks_per_second 
	}
}