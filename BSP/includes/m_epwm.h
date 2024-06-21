/*
 * m_epwm.h
 *
 *  Created on: 2024年6月19日
 *      Author: durant35
 */

#ifndef BSP_INCLUDES_M_EPWM_H_
#define BSP_INCLUDES_M_EPWM_H_

//按需修改MIN_CMPA和MAX_CMPB，测试已能输出正常波形
//epmw1
#define EPWM1_TIMER_TBPRD           5000U
#define EPWM1_MAX_CMPA              2500U
#define EPWM1_MIN_CMPA              2500U
#define EPWM1_MAX_CMPB              2500U
#define EPWM1_MIN_CMPB              2500U

//epmw2
#define EPWM2_TIMER_TBPRD           5000U
#define EPWM2_MAX_CMPA              2500U
#define EPWM2_MIN_CMPA              2500U
#define EPWM2_MAX_CMPB              2500U
#define EPWM2_MIN_CMPB              2500U

//epmw3
#define EPWM3_TIMER_TBPRD           1000U
#define EPWM3_MAX_CMPA              500U
#define EPWM3_MIN_CMPA              500U
#define EPWM3_MAX_CMPB              500U
#define EPWM3_MIN_CMPB              500U

//epmw4
#define EPWM4_TIMER_TBPRD           1000U
#define EPWM4_MAX_CMPA              500U
#define EPWM4_MIN_CMPA              500U
#define EPWM4_MAX_CMPB              500U
#define EPWM4_MIN_CMPB              500U

#define EPWM_CMP_UP                 1U
#define EPWM_CMP_DOWN               0U

void initEPWM1(void);
void initEPWM2(void);
void initEPWM3(void);
void initEPWM4(void);
void init_All_EPWM(void);
#endif /* BSP_INCLUDES_M_EPWM_H_ */
