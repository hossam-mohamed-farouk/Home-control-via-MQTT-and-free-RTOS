/*
 * T_Control.c
 *
 * Created: 7/20/2020 11:39:06 AM
 *  Author: H
 */ 

#include "T_Control.h"

static U_8 cmdPacket[30];

/* L1 -> LED On, L0 -> LED Off */
//$,TV,ON,#
/*
void T_Control(void* pvData)
{
	U_8 ind = 0;
	while(1)
	{
		if (xQueueReceive(mqControl,cmdPacket,portMAX_DELAY))
		{
			for (ind = 0; ind < cmdPacket[1]; ind++)
			{
				if (cmdPacket[ind + 2] == 'L')
				{
					if (cmdPacket[ind + 2 + 1] == '1')
					{
						led_on();
					}
					else if (cmdPacket[ind + 2 + 1] == '0')
					{
						led_off();
					}
				}
			}
		}
	}
}
*/

void T_Control(void* pvData)
{
	U_8 ind = 0;
	while(1)
	{
		if (xQueueReceive(mqControl,cmdPacket,portMAX_DELAY))
		{
			for (ind = 0; ind < cmdPacket[1]; ind++)
			{
				if (cmdPacket[ind + 2] == '$')
				{
					if (!strcmp("$,TV,ON,#",&cmdPacket[ind + 2])) 
					{
						leds_on(0x01);
					}
					else if (!strcmp("$,TV,OFF,#",&cmdPacket[ind + 2]))
					{
						leds_off(0x01);
					}
					else if (!strcmp("$,AC,ON,#",&cmdPacket[ind + 2]))
					{
						leds_on(0x02);
					}
					else if (!strcmp("$,AC,OFF,#",&cmdPacket[ind + 2]))
					{
						leds_off(0x02);
					}
					else
					{
						led_toggle();
					}
				}
			}
		}
	}
}