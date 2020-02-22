/*
 * lcd.c
 *
 *  Created on: Feb 21, 2020
 *      Author: pbloemer
 *
 *
 *      Initialization code largely copied from
 *       https://github.com/adafruit/TFTLCD-Library/blob/master/Adafruit_TFTLCD.cpp for source on initialization
 *
 */


#include "ILI9341.h"


void ili_init() {
    // TODO Set CSX


    write8(ILI9341_SOFTRESET)
    //write8(0);
    vTaskDelay(pdMS_TO_TICKS(5));
    write8(ILI9341_DISPLAYOFF)
    //write8(0);

    write8(ILI9341_POWERCONTROL1);
    write8(0x23);
    write8(ILI9341_POWERCONTROL2);
    write8(0x10);
    write8(ILI9341_VCOMCONTROL1);
    write8(0x2B);
    write8(0x2B);
    write8(ILI9341_VCOMCONTROL2);
    write8(0xC0);
    write8(ILI9341_MEMCONTROL);
    write8(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
    write8(ILI9341_PIXELFORMAT);
    write8(0x55);
    write8(ILI9341_FRAMECONTROL);
    write8(0x00);
    write8(0x1B);

    //write8(ILI9341_ENTRYMODE, 0x07);

    write8(ILI9341_SLEEPOUT);
    //write8(0);
    vTaskDelay(pdMS_TO_TICKS(150));
    write8(ILI9341_DISPLAYON)
    //write8(0);
    vTaskDelay(pdMS_TO_TICKS(500));

    // TODO Addr window will need to be set
    //setAddrWindow(0, 0, TFTWIDTH - 1
}
