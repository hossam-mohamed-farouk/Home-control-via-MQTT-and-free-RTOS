/*
 * T_Control.h
 *
 * Created: 7/20/2020 11:38:52 AM
 *  Author: H
 */ 


#ifndef T_CONTROL_H_
#define T_CONTROL_H_

#include "app.h"

extern xSemaphoreHandle 	bsConnect;						//semaphore
extern xQueueHandle			mqControl;						//msg_queue
extern EventGroupHandle_t	egMQTT;							//event_group
extern EventBits_t			ebValMQTT;						//event_group_bits

extern U_8 system_up;



#endif /* T_CONTROL_H_ */