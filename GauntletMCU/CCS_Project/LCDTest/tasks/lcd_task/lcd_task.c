/*
 * net_task.c
 *
 *  Created on: Feb 6, 2020
 *      Author: halitosisman
 *
 *
 *      Much of the initialization code here was copied from the Simplelink CC32xx SDK tcpecho example
 */


#include <tasks/lcd_task/lcd_task.h>

unsigned char test[] = {0x4a, 0x6b, 0x10, 0x00, 0xff, 0x66};

QueueHandle_t sl_event_box;

void lcd_task(void * par) {
    GPIO_init();

    while (1) {
        GPIOPinWrite(GPIOA0_BASE, LCD_DBUS_HIGH, test[0]);
        GPIOPinWrite(GPIOA1_BASE, LCD_DBUS_LOW, test[1]);
        GPIOPinWrite(GPIOA0_BASE, LCD_DBUS_HIGH, test[2]);
        GPIOPinWrite(GPIOA1_BASE, LCD_DBUS_LOW, test[3]);
        GPIOPinWrite(GPIOA0_BASE, LCD_DBUS_HIGH, test[4]);
        GPIOPinWrite(GPIOA1_BASE, LCD_DBUS_LOW, test[5]);
        GPIO_toggle(LCD_WRX);
        vTaskDelay(  pdMS_TO_TICKS( 1000 ) );
    }
}
