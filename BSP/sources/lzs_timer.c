#include "F28x_Project.h"
#include "lzs_timer.h"

void Init_Timer0(void){

#if 0
    //2808程序上的代码解释@lzs 2024.6.21
    //定时器周期寄存器（低位+高位）
    CpuTimer0Regs.TIM.all=0;//
    CpuTimer0Regs.PRD.all=10000;//每10000个TIMCLK就是一个定时器周期
    //定时器预定标计数器（低位+高位）
    CpuTimer0Regs.TPR.all=0;//每来一个SYSCLKOUT就是一个TIMCLK
    CpuTimer0Regs.TPRH.all=0;//即：每10000个SYSCLKOUT就是一个定时器周期
    //定时器控制寄存器TCR
    CpuTimer0Regs.TCR.bit.TIE=0;//中断使能位，如果TIMH:TIM=0，该位自动置1，定时器向CPU发出中断
    CpuTimer0Regs.TCR.bit.TIF=0;//中断标志位，写1清除，写0无效
    CpuTimer0Regs.TCR.bit.SOFT=1;//
    CpuTimer0Regs.TCR.bit.FREE=0;//FREE和SOFT为搭配，TIMH:TIM=0的时候定时器停止（软停止）
    CpuTimer0Regs.TCR.bit.TSS=1;//置1停止计时器
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

    CpuTimer0Regs.TCR.bit.TIE=0;//中断使能位，如果TIMH:TIM=0，该位自动置1，定时器向CPU发出中断
    CpuTimer0Regs.TCR.bit.TIF=0;
    CpuTimer0Regs.TCR.bit.FREE = 0;
    CpuTimer0Regs.TCR.bit.SOFT = 1;
    //
    // Reset interrupt counters
    //
    CpuTimer01.InterruptCount = 0;

}