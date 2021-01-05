/*
 * T_Monitor.h
 *
 * Created: 7/20/2020 11:39:22 AM
 *  Author: H
 */ 


#ifndef T_MONITOR_H_
#define T_MONITOR_H_

#include "app.h"

extern xSemaphoreHandle 	bsConnect;						//semaphore
extern xQueueHandle			mqControl;						//msg_queue
extern EventGroupHandle_t	egMQTT;							//event_group
extern EventBits_t			ebValMQTT;						//event_group_bits

extern U_8 system_up;



#endif /* T_MONITOR_H_ */