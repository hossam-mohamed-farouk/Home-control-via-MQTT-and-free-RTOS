/*
 * app.h
 *
 * Created: 7/20/2020 11:33:07 AM
 *  Author: H
 */ 


#ifndef APP_H_
#define APP_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "board.h"
#include "adc_bitfield.h"
#include "mqtt.h"

#define				E_MQTT_PUBACK	(1<<0)
#define				E_MQTT_SUBACK	(1<<1)
#define				E_MQTT_CONNACK	(1<<2)

void T_Control(void* pvData);
void T_Monitor(void* pvData);
void T_RespHandle(void* pvData);
void T_Connect(void* pvData);
void system_init(void);


#endif /* APP_H_ */