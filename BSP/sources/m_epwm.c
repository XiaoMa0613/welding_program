/*
 * epwm.c
 *
 *  Created on: 2024年6月19日
 *      Author: durant35
 */
#include "driverlib.h"
#include "m_epwm.h"

void init_All_EPWM(void)
{
    initEPWM1();
    initEPWM2();
    initEPWM3();
    initEPWM4();
}

void initEPWM1(void)
{
    // 设置ePWM的时钟TBCLK 在100MHz的主频下，每一个TBCLK对应 10ns
    EPWM_setTimeBasePeriod(EPWM1_BASE, EPWM1_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM1_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM1_BASE, 0U);

    // 设置SYNC源选择
    EPWM_setSyncOutPulseMode(EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_COUNTER_ZERO);

    // 设置CMPA和CMPB
    EPWM_setCounterCompareValue(EPWM1_BASE,
                                EPWM_COUNTER_COMPARE_A,
                                EPWM1_MIN_CMPA);
    EPWM_setCounterCompareValue(EPWM1_BASE,
                                EPWM_COUNTER_COMPARE_B,
                                EPWM1_MAX_CMPB);

    // 设置为增计数模式，所以PWM的周期是 10ns*5000=50us，对应20kHz
    EPWM_setTimeBaseCounterMode(EPWM1_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(EPWM1_BASE);
    EPWM_setClockPrescaler(EPWM1_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    // 设置影子寄存器，在计数为0时装载
    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM1_BASE,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    // 设置ePWM动作方式
    // 对于EPWM1A,当增计数==PRD时输出高,当增计数==CMPA时输出低
    // 对于EPWM1B,没开
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
#if 0
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM1_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    // 设置触发中断的时刻,这里设置为计数器为0时触发。
    // 使能中断。
    // 设置每隔3次触发一次中断，上限15次。
    EPWM_setInterruptSource(EPWM1_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(EPWM1_BASE);
    EPWM_setInterruptEventCount(EPWM1_BASE, 3U);
#endif
#if 1
    //设置ADC的SOC，先禁止ADC触发
    EPWM_disableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    //设置SOC源为计数器等于PRD，每10次产生一个SOC_A
    EPWM_setADCTriggerSource(EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);
    EPWM_setADCTriggerEventPrescale(EPWM1_BASE, EPWM_SOC_A, 10);
    //开启ADC触发
    EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
#endif
}

void initEPWM2(void)
{
    // 设置ePWM的时钟TBCLK 在100MHz的主频下，每一个TBCLK对应 10ns
    EPWM_setTimeBasePeriod(EPWM2_BASE, EPWM2_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM2_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM2_BASE, 0U);

    // 设置CMPA和CMPB
    EPWM_setCounterCompareValue(EPWM2_BASE,
                                EPWM_COUNTER_COMPARE_A,
                                EPWM2_MIN_CMPA);
    EPWM_setCounterCompareValue(EPWM2_BASE,
                                EPWM_COUNTER_COMPARE_B,
                                EPWM2_MAX_CMPB);

    // 设置为增计数模式，所以PWM的周期是 10ns*5000=50us，对应20kHz
    EPWM_setTimeBaseCounterMode(EPWM2_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(EPWM2_BASE);
    EPWM_setClockPrescaler(EPWM2_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    // 设置影子寄存器，在计数为0时装载
    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM2_BASE,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    // 设置ePWM动作方式
    // 对于EPWM2A,当增计数==PRD时输出高,当增计数==CMPA时输出低
    // 对于EPWM2B,当增计数==CMP时输出高,当增计数==PRD时输出低
    EPWM_setActionQualifierAction(EPWM2_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM2_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    EPWM_setActionQualifierAction(EPWM2_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM2_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);

    // 设置触发中断的时刻,这里设置为计数器为PRD时触发。
    // 使能中断。
    // 设置每隔3次触发一次中断，上限15次。
    EPWM_setInterruptSource(EPWM2_BASE, EPWM_INT_TBCTR_PERIOD);
    EPWM_enableInterrupt(EPWM2_BASE);
    EPWM_setInterruptEventCount(EPWM2_BASE, 3U);
}

void initEPWM3(void)
{
    // 设置ePWM的时钟TBCLK 在100MHz的主频下，每一个TBCLK对应 10ns
    EPWM_setTimeBasePeriod(EPWM3_BASE, EPWM3_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM3_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM3_BASE, 0U);

    // 设置CMPA和CMPB
    EPWM_setCounterCompareValue(EPWM3_BASE,
                                EPWM_COUNTER_COMPARE_A,
                                EPWM3_MIN_CMPA);
    EPWM_setCounterCompareValue(EPWM3_BASE,
                                EPWM_COUNTER_COMPARE_B,
                                EPWM3_MAX_CMPB);

    // 设置为增计数模式，所以PWM的周期是 10ns*5000=50us，对应20kHz
    EPWM_setTimeBaseCounterMode(EPWM3_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(EPWM3_BASE);
    EPWM_setClockPrescaler(EPWM3_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    // 设置影子寄存器，在计数为0时装载
    EPWM_setCounterCompareShadowLoadMode(EPWM3_BASE,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM3_BASE,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    // 设置ePWM动作方式
    // 对于EPWM1A,当增计数==PRD时输出高,当增计数==CMPA时输出低
    // 对于EPWM1B,没开
    EPWM_setActionQualifierAction(EPWM3_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM3_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
#if 0
    EPWM_setActionQualifierAction(EPWM3_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM3_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    // 设置触发中断的时刻,这里设置为计数器为0时触发。
    // 使能中断。
    // 设置每隔3次触发一次中断，上限15次。
    EPWM_setInterruptSource(EPWM3_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(EPWM3_BASE);
    EPWM_setInterruptEventCount(EPWM3_BASE, 3U);
#endif
}

void initEPWM4(void)
{
    // 设置ePWM的时钟TBCLK 在100MHz的主频下，每一个TBCLK对应 10ns
    EPWM_setTimeBasePeriod(EPWM4_BASE, EPWM4_TIMER_TBPRD);
    EPWM_setPhaseShift(EPWM4_BASE, 0U);
    EPWM_setTimeBaseCounter(EPWM4_BASE, 0U);

    // 设置CMPA和CMPB
    EPWM_setCounterCompareValue(EPWM4_BASE,
                                EPWM_COUNTER_COMPARE_A,
                                EPWM3_MIN_CMPA);
    EPWM_setCounterCompareValue(EPWM4_BASE,
                                EPWM_COUNTER_COMPARE_B,
                                EPWM4_MAX_CMPB);

    // 设置为增计数模式，所以PWM的周期是 10ns*5000=50us，对应20kHz
    EPWM_setTimeBaseCounterMode(EPWM4_BASE, EPWM_COUNTER_MODE_UP);
    EPWM_disablePhaseShiftLoad(EPWM4_BASE);
    EPWM_setClockPrescaler(EPWM4_BASE,
                           EPWM_CLOCK_DIVIDER_1,
                           EPWM_HSCLOCK_DIVIDER_1);

    // 设置影子寄存器，在计数为0时装载
    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                         EPWM_COUNTER_COMPARE_A,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    EPWM_setCounterCompareShadowLoadMode(EPWM4_BASE,
                                         EPWM_COUNTER_COMPARE_B,
                                         EPWM_COMP_LOAD_ON_CNTR_ZERO);
    // 设置ePWM动作方式
    // 对于EPWM1A,当增计数==PRD时输出高,当增计数==CMPA时输出低
    // 对于EPWM1B,没开
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_A,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
#if 0
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_HIGH,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    EPWM_setActionQualifierAction(EPWM4_BASE,
                                  EPWM_AQ_OUTPUT_B,
                                  EPWM_AQ_OUTPUT_LOW,
                                  EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    // 设置触发中断的时刻,这里设置为计数器为0时触发。
    // 使能中断。
    // 设置每隔3次触发一次中断，上限15次。
    EPWM_setInterruptSource(EPWM4_BASE, EPWM_INT_TBCTR_ZERO);
    EPWM_enableInterrupt(EPWM4_BASE);
    EPWM_setInterruptEventCount(EPWM4_BASE, 3U);
#endif
}
