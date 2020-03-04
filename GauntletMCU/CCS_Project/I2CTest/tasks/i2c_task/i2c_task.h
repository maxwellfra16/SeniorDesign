/*
 * i2c_task.h
 *
 *  Created on: Feb 15, 2020
 *      Author: maxwellfra16
 */


#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "pthread.h"
#include "configs/Board.h"

#include "tasks/FGtask.h"

#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>

#define SL_TASK_STACK_SIZE 2048 // copied from TI's tcpecho example
#define SPAWN_TASK_PRIORITY 9 // also copied from TI's tcpecho example


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
void i2c_task(void * par);


#ifdef _cplusplus
#define
extern }
#endif


#endif /* TASKS_NET_TASK_NET_TASK_H_ */
