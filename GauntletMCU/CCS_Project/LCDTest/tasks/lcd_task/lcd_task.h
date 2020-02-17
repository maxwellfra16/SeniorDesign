/*
 * net_thread.h
 *
 *  Created on: Feb 6, 2020
 *      Author: halitosisman
 */


#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "pthread.h"
#include "configs/Board.h"

#include <ti/drivers/GPIO.h>
#include <ti/devices/cc32xx/inc/hw_types.h>
#include <ti/devices/cc32xx/driverlib/gpio.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>

#include "tasks/FGtask.h"

#define SL_TASK_STACK_SIZE 2048 // copied from TI's tcpecho example
#define SPAWN_TASK_PRIORITY 9 // also copied from TI's tcpecho example

#define LCD_DBUS_HIGH (GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)
#define LCD_DBUS_LOW (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3)


#ifndef TASKS_LCD_TASK_LCD_TASK_H_
#define TASKS_LCD_TASK_LCD_TASK_H_

#ifdef _cplusplus
#define
extern "C" {
#endif


/*!
    \brief          lcd_task

    FreeRTOS task function for Finity Gauntlet graphical functions

    \param          par    -   Standard FreeRTOS task parameters.

    \return         void

    \note

*/
void lcd_task(void * par);


#ifdef _cplusplus
#define
extern }
#endif


#endif /* TASKS_NET_TASK_NET_TASK_H_ */
