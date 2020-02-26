/*
 * lcd.c
 *
 *  Created on: Feb 26, 2020
 *      Author: pbloemer
 */


#include "lcd.h"


void lcd_clear() {
    uint8_t color[] = {0x0, 0x0};

    mem_write.tag = NO_CMD;

    pg_set.data.small[0] = 0x0;
    pg_set.data.small[1] = 0x0;
    pg_set.data.small[2] = 0x01;
    pg_set.data.small[3] = 0x3F;

    cl_set.data.small[0] = 0x0;
    cl_set.data.small[1] = 0x0;
    cl_set.data.small[2] = 0x0;
    cl_set.data.small[3] = 0xEF;

    ILI_write(pg_set);
    ILI_write(cl_set);
    ILI_write(mem_write);
    FG_write_color((uint8_t *) color, sizeof(color), LCD_COLUMNS * LCD_ROWS);
}
