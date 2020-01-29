/*
 * main.cpp
 *
 *  Created on: May 19, 2019
 *      Author: halitosisman
 *
 *  Sets the RGB LED bits on the board
 */

#define LEDMSK 0b00001110
#define GPIOPADCFG 0x20
#define LEDADDROFF 0x38

#include <ti/drivers/Board.h>
#include <ti/drivers/gpio/GPIOCC32XX.h>
#include <ti/devices/cc32xx/inc/hw_gpio.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/devices/cc32xx/inc/hw_apps_rcm.h>
#include <ti/devices/cc32xx/inc/hw_ocp_shared.h>

static uint32_t * const PRC_GPIOA1 = (uint32_t *) (ARCM_BASE + APPS_RCM_O_GPIO_B_CLK_GATING);
static uint32_t * const GPIOA1DIR = (uint32_t *) (GPIOA1_BASE + GPIO_O_GPIO_DIR);
static uint32_t * const GPIOLEDDATA = (uint32_t *) (GPIOA1_BASE + LEDADDROFF);
static uint32_t * const GPIO9PAD = (uint32_t *) (OCP_SHARED_BASE + OCP_SHARED_O_GPIO_PAD_CONFIG_9);
static uint32_t * const GPIO10PAD = (uint32_t *) (OCP_SHARED_BASE + OCP_SHARED_O_GPIO_PAD_CONFIG_10);
static uint32_t * const GPIO11PAD = (uint32_t *) (OCP_SHARED_BASE + OCP_SHARED_O_GPIO_PAD_CONFIG_11);

int main() {
    //Board_init();

    *PRC_GPIOA1 |= APPS_RCM_GPIO_B_CLK_GATING_GPIO_B_RUN_CLK_ENABLE;  // Initialize GPIOB CLK
    //note that 3 clock cycles need to pass before writing to  the GPIOs
    // Luckily there's more than enough instructions in between writes to make that happen


    *GPIOA1DIR |= LEDMSK; //  Set LED pins as outputs
    *GPIO9PAD &= ~OCP_SHARED_GPIO_PAD_CONFIG_1_MEM_GPIO_PAD_CONFIG_1_M;
    *GPIO9PAD |= GPIOPADCFG;
    *GPIO10PAD &= ~OCP_SHARED_GPIO_PAD_CONFIG_1_MEM_GPIO_PAD_CONFIG_1_M;
    *GPIO10PAD |= GPIOPADCFG;
    *GPIO11PAD &= ~OCP_SHARED_GPIO_PAD_CONFIG_1_MEM_GPIO_PAD_CONFIG_1_M;
    *GPIO11PAD |= GPIOPADCFG;

    *GPIOLEDDATA = 0b0100; //MSB 3 bits map to G, R, B colors of the LED respectively

    while(1) {}
}


