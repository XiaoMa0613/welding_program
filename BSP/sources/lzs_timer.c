#include "F28x_Project.h"
#include "lzs_timer.h"

void Init_Timer0(void){

#if 0
    //2808�����ϵĴ������@lzs 2024.6.21
    //��ʱ�����ڼĴ�������λ+��λ��
    CpuTimer0Regs.TIM.all=0;//
    CpuTimer0Regs.PRD.all=10000;//ÿ10000��TIMCLK����һ����ʱ������
    //��ʱ��Ԥ�������������λ+��λ��
    CpuTimer0Regs.TPR.all=0;//ÿ��һ��SYSCLKOUT����һ��TIMCLK
    CpuTimer0Regs.TPRH.all=0;//����ÿ10000��SYSCLKOUT����һ����ʱ������
    //��ʱ�����ƼĴ���TCR
    CpuTimer0Regs.TCR.bit.TIE=0;//�ж�ʹ��λ�����TIMH:TIM=0����λ�Զ���1����ʱ����CPU�����ж�
    CpuTimer0Regs.TCR.bit.TIF=0;//�жϱ�־λ��д1�����д0��Ч
    CpuTimer0Regs.TCR.bit.SOFT=1;//
    CpuTimer0Regs.TCR.bit.FREE=0;//FREE��SOFTΪ���䣬TIMH:TIM=0��ʱ��ʱ��ֹͣ����ֹͣ��
    CpuTimer0Regs.TCR.bit.TSS=1;//��1ֹͣ��ʱ��
#endif

    // CPU Timer 0
    // Initialize address pointers to respective timer registers
    CpuTimer01.RegsAddr = &CpuTimer0Regs;

    //
    // Initialize timer period to maximum
    //
    CpuTimer0Regs.PRD.all  = 10000;

    //
    // Initialize pre-scale counter to divide by 1 (SYSCLKOUT)
    //
    CpuTimer0Regs.TPR.all  = 0;
    CpuTimer0Regs.TPRH.all = 0;

    //
    // Make sure timer is stopped
    //
    CpuTimer0Regs.TCR.bit.TSS = 1;

    //
    // Reload all counter register with period value
    //
    CpuTimer0Regs.TCR.bit.TRB = 1;

    CpuTimer0Regs.TCR.bit.TIE=0;//�ж�ʹ��λ�����TIMH:TIM=0����λ�Զ���1����ʱ����CPU�����ж�
    CpuTimer0Regs.TCR.bit.TIF=0;
    CpuTimer0Regs.TCR.bit.FREE = 0;
    CpuTimer0Regs.TCR.bit.SOFT = 1;
    //
    // Reset interrupt counters
    //
    CpuTimer01.InterruptCount = 0;

}