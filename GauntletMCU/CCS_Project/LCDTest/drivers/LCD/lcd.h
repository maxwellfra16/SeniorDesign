/*
 * lcd.h
 *
 *  Created on: Feb 26, 2020
 *      Author: pbloemer
 */

#ifndef DRIVERS_LCD_LCD_H_
#define DRIVERS_LCD_LCD_H_

#include "drivers/LCD/ILI9341.h"


// Dependency: FG_graphics.h -> lcd.h -> chipset.h
// chipset.h callbacks need to be defined and then used to define lcd.h callbacks
#ifdef _cplusplus
#define
extern "C" {
#endif

#define LCD_COLUMNS 320
#define LCD_ROWS 240


void lcd_init();
void lcd_clear();


#ifdef _cplusplus
#define
extern }
#endif

#endif /* DRIVERS_LCD_LCD_H_ */
