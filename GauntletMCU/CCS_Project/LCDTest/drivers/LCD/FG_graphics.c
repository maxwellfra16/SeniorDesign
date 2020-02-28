/*
 * FG_graphics.c
 *
 *  Created on: Feb 27, 2020
 *      Author: halitosisman
 */


#include "drivers/LCD/FG_graphics.h"




static Graphics_Rectangle wrist_display_limits =
{
     .xMax = LCD_COLUMNS - 1,
     .xMin = 0,
     .yMax = LCD_ROWS - 1,
     .yMin = 0
};

static Graphics_Display wrist_display =
{
     .displayData = NULL,
     .heigth = LCD_ROWS,
     .pFxns = NULL, // TODO Define these.
     .size = sizeof(Graphics_Display),
     .width = LCD_COLUMNS
};

Graphics_Context wrist_context =
{
     .background = 0,
     .clipRegion = wr_display_limits,
     .font = g_sFontCm12,
     .foreground = 0,
     .size = sizeof(Graphics_Context),
     .display = wrist_display
};


void pfnPixelDraw(const Graphics_Display * pDisplay, int16_t lX, int16_t lY, uint16_t ulValue) {
    // TODO continue here
}


void FG_graphics_init() {
    lcd_init();
    lcd_clear();


}
