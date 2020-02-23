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


unsigned char test[] = {0xFF, 0x0a, 0x50, 0x05};

static volatile uint32_t * const wrx = (uint32_t *) (GPIOA0_BASE + LCD_WRX_MSK);
static volatile uint32_t * const dcx = (uint32_t *) (GPIOA0_BASE + LCD_DCX_MSK);
static volatile uint32_t * const data_74 = (uint32_t *) (GPIOA0_BASE + LCD_D74_MSK);
static volatile uint32_t * const data_30 = (uint32_t *) (GPIOA1_BASE + LCD_D30_MSK);

QueueHandle_t sl_event_box;


inline void set_dcx(uint8_t val) {
    *dcx = val;
}


inline void write8(uint8_t val) {
    *data_74 = val;
    *data_30 = val;
    __asm("    nop"); // These NOP counts were eye balled.
    __asm("    nop");
    __asm("    nop");
    __asm("    nop");

    *wrx = 0xFF;
    __asm("    nop");
    __asm("    nop");
    __asm("    nop");
    __asm("    nop");
    __asm("    nop");
    __asm("    nop");
    *wrx = 0x0;
}


void lcd_task(void * par) {
    GPIO_init();

    *wrx = 0x0;
    *data_74 = 0x0;
    *data_30 = 0x0;

    while (1) {
        test[0] = ~test[0];
        *data_74 = test[0];
        *data_30 = test[0];
        __asm("    nop"); // These NOP counts were eye balled.
        __asm("    nop");
        __asm("    nop");
        __asm("    nop");

        *wrx = 0xFF;
        __asm("    nop");
        __asm("    nop");
        __asm("    nop");
        __asm("    nop");
        __asm("    nop");
        __asm("    nop");
        *wrx = 0x0;
    }

}
