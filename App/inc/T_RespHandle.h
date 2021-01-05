/*
 * T_RespHandle.h
 *
 * Created: 7/20/2020 11:39:54 AM
 *  Author: H
 */ 


#ifndef T_RESPHANDLE_H_
#define T_RESPHANDLE_H_

#include "app.h"


extern xSemaphoreHandle 	bsConnect;						//semaphore
extern xQueueHandle			mqControl;						//msg_queue
extern EventGroupHandle_t	egMQTT;							//event_group
extern EventBits_t			ebValMQTT;						//event_group_bits

typedef enum
{
	RS_NONE, RS_PackType, RS_Remain
}RecState;



#endif /* T_RESPHANDLE_H_ */