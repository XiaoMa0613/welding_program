/*
 * m_gpio.c
 *
 *  Created on: 2024年6月19日
 *      Author: durant35
 */

#include "driverlib.h"
#include "device.h"
#include "c2000ware_libraries.h"
#include "m_gpio.h"

void init_GPIO(void)
{
    EALLOW;
    //gpio_test
    GPIO_setPinConfig(GPIO_34_GPIO34);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);

    //epwm1
    GPIO_setPinConfig(GPIO_0_EPWM1_A);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM1A, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_1_EPWM1_B);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM1B, GPIO_PIN_TYPE_STD);

    //epwm2
    GPIO_setPinConfig(GPIO_2_EPWM2_A);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM2A, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_3_EPWM2_B);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM2B, GPIO_PIN_TYPE_STD);

    //epwm3
    GPIO_setPinConfig(GPIO_4_EPWM3_A);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM3A, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_5_EPWM3_B);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM3B, GPIO_PIN_TYPE_STD);

    //epwm4
    GPIO_setPinConfig(GPIO_6_EPWM4_A);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM4A, GPIO_PIN_TYPE_STD);
    GPIO_setPinConfig(GPIO_7_EPWM4_B);
    GPIO_setPadConfig(DEVICE_GPIO_PIN_EPWM4B, GPIO_PIN_TYPE_STD);

    EDIS;
}


