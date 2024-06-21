/*
 * m_gpio.h
 *
 *  Created on: 2024年6月19日
 *      Author: durant35
 */

#ifndef BSP_INCLUDES_M_GPIO_H_
#define BSP_INCLUDES_M_GPIO_H_

//epwm引脚
#define DEVICE_GPIO_PIN_EPWM1B      1U
#define DEVICE_GPIO_PIN_EPWM2A      2U
#define DEVICE_GPIO_PIN_EPWM2B      3U
#define DEVICE_GPIO_PIN_EPWM3A      4U
#define DEVICE_GPIO_PIN_EPWM3B      5U
#define DEVICE_GPIO_PIN_EPWM4A      6U
#define DEVICE_GPIO_PIN_EPWM4B      7U

//adc引脚

void init_GPIO(void);
#endif /* BSP_INCLUDES_M_GPIO_H_ */
