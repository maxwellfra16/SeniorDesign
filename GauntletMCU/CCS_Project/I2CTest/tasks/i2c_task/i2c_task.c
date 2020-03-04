/*
 * i2c_task.c
 *
 *  Created on: Feb 15, 2020
 *      Author: maxwellfra16
 *
 *
 *      Much of the initialization code here was copied from the Simplelink CC32xx SDK tcpecho example
 */


#include <tasks/i2c_task/i2c_task.h>
#define CONFIG_I2C_TMP              0
#define TX_SEND_DATA 0x0011


QueueHandle_t sl_event_box;

void i2c_task(void * par) {
    I2C_Handle      i2c;
    I2C_Params      i2cParams;
    I2C_Transaction i2cTransaction;
    uint8_t         txBuffer[1];
    uint8_t         rxBuffer[2];
    GPIO_init();
    I2C_init();
    I2C_Params_init(&i2cParams);
    i2c = I2C_open(CONFIG_I2C_TMP, &i2cParams);
    txBuffer[0] = TX_SEND_DATA;
    i2cTransaction.writeBuf   = txBuffer;
    i2cTransaction.writeCount = 1;
    i2cTransaction.readBuf    = rxBuffer;
    i2cTransaction.readCount  = 1;
    i2cTransaction.slaveAddress = 0x0100011;
    while(1) {
        if (!I2C_transfer(i2c, &i2cTransaction)) {
            GPIO_toggle(PIN_LED_GREEN);
            }
        vTaskDelay( pdMS_TO_TICKS(500) );
    }
}
