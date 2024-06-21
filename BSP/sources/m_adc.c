/*
 * m_adc.c
 *
 *  Created on: 2024年6月19日
 *      Author: durant35
 */

#include "driverlib.h"
#include "device.h"
#include "m_adc.h"

void init_ADC(void)
{
    // ADC使用片内参考3.3V
    // Setup VREF as internal
    ADC_setVREF(ADCA_BASE, ADC_REFERENCE_INTERNAL, ADC_REFERENCE_3_3V);

    // ADC时钟5分频
    // Set ADCCLK divider to /8 = 12.5Mhz
    ADC_setPrescaler(ADCA_BASE, ADC_CLK_DIV_5_0);
    ADC_setPrescaler(ADCB_BASE, ADC_CLK_DIV_5_0);

    // 设置转换结束时触发中断
    // Set pulse positions to late
    ADC_setInterruptPulseMode(ADCA_BASE, ADC_PULSE_END_OF_CONV);

    // 启动AD并延迟1ms
    // Power up the ADCs and then delay for 1 ms
    ADC_enableConverter(ADCA_BASE);
    ADC_enableConverter(ADCB_BASE);

    DEVICE_DELAY_US(1000);

    // 采样窗口持续10个系统时钟, 触发源为EPWM1A_SOC (2808是软件触发）
    // - SOC0 will convert pin A0 with a sample window of 10 SYSCLK cycles.
    // - SOC1 will convert pin A1 with a sample window of 10 SYSCLK cycles.
    //
#if 0
    //如需软件触发，修改第三个参数为ADC_TRIGGER_SW_ONLY
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_SW_ONLY,
                 ADC_CH_ADCIN0, 10);
#endif
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN0, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN1, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN2, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN3, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN4, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER5, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN5, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER6, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN6, 10);
    ADC_setupSOC(ADCA_BASE, ADC_SOC_NUMBER7, ADC_TRIGGER_EPWM1_SOCA,
                 ADC_CH_ADCIN7, 10);
    // 设置中断为ADCINT1，并启用
    // Set SOC1 to set the interrupt 1 flag. Enable the interrupt and make
    // sure its flag is cleared.
    ADC_setInterruptSource(ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER1);
    ADC_enableInterrupt(ADCA_BASE, ADC_INT_NUMBER1);
    ADC_clearInterruptStatus(ADCA_BASE, ADC_INT_NUMBER1);
}

