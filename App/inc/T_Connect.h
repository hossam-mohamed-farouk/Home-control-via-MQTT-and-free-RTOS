/*
 * T_Connect.h
 *
 * Created: 7/20/2020 11:40:26 AM
 *  Author: H
 */ 


#ifndef T_CONNECT_H_
#define T_CONNECT_H_

#include "app.h"

extern xSemaphoreHandle 	bsConnect;						//semaphore
extern xQueueHandle			mqControl;						//msg_queue
extern EventGroupHandle_t	egMQTT;							//event_group
extern EventBits_t			ebValMQTT;						//event_group_bits



#endif /* T_CONNECT_H_ */