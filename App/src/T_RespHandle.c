/*
 * T_RespHandle.c
 *
 * Created: 7/20/2020 11:40:04 AM
 *  Author: H
 */ 

#include "T_RespHandle.h"

static U_8 recPacket[30];

void T_RespHandle(void* pvData)
{
	U_8 u8Byte = 0;
	RecState recState = 0;
	U_8 recInd = 0;
	U_8 remLen = 0;
	while(1)
	{
		if (uart_receive_byte_unblock(UART_0,&u8Byte))
		{
			switch(recState)
			{
				case RS_NONE:
					if (u8Byte == 0x20 || u8Byte == 0x30 || u8Byte == 0x32 || u8Byte == 0x40 || u8Byte == 0x90)
					{
						recPacket[0] = u8Byte;
						recState = RS_PackType;
					}
				break;
				
				case RS_PackType:
					recPacket[1] = u8Byte;
					remLen = u8Byte;
					recInd = 0;
					recState = RS_Remain;
				break;
				
				case RS_Remain:
					recPacket[recInd + 2] = u8Byte;
					recInd ++;
					if (recInd == remLen)
					{
						recState = RS_NONE;
						switch (recPacket[0])
						{
							case 0x30:
								xQueueSend(mqControl,recPacket,0);
							break;
							
							case 0x32:
								/*PUBACK should be transmitted*/
							break;
							
							case 0x20:
								xEventGroupSetBits(egMQTT,E_MQTT_CONNACK);
							break;
							
							case 0x40:
								xEventGroupSetBits(egMQTT,E_MQTT_PUBACK);
							break;
							
							case 0x90:
								xEventGroupSetBits(egMQTT,E_MQTT_SUBACK);
							break;							
						}
					}
				break;
			}
		}
		else vTaskDelay(1);
	}
}