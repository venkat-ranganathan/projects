/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 3

systick driver controls the timing of the main loop, runs every 1000 ms
*/

#include "systick.h"

#ifndef NUM_CALLBACKS
#define NUM_CALLBACKS 5
#endif

#define SYSTICK_FREQ_HZ 1000
#define SYSTICK_TOP (SYS_CLOCK/SYSTICK_FREQ_HZ)

static void (*callback[NUM_CALLBACKS])();
static uint32_t num_callbacks;
static volatile _Bool systick_fired_flag=false;
static volatile _Bool isr_flag = false;

_Bool systick_register_callback(void (*p_fn)())
{
    if(NUM_CALLBACKS == num_callbacks)
        return false;
    callback[num_callbacks++]=p_fn;
    return true;
}

void configure_systick()
{
    // SET RVR to m0plus -> syst_rvr; systick reload value register
    m0plus->syst_rvr = SYSTICK_TOP;

    // WRITE 0 to CVR to force immediate reset; count value register
    m0plus->syst_cvr = 0;

    (( void (**) ()) m0plus->vtor )[15] = SystickHandler;
   
    m0plus->shpr3 = (m0plus->shpr3 & ~M0PLUS_SHPR3_PRI_15_MASK ) 
    | M0PLUS_SHPR3_PRI_15(0);

    // CONFIGURE CSR Clock Source and Enable; systick control & status register
    m0plus->syst_csr = M0PLUS_SYST_CSR_CLKSOURCE(1) 
    | M0PLUS_SYST_CSR_ENABLE_MASK 
    | M0PLUS_SYST_CSR_TICKINT_MASK;
}

_Bool get_isr_flag()
{
    return isr_flag;
}

_Bool clear_isr_flag()
{
    isr_flag=false;
}

_Bool get_and_clear_isr_flag()
{
    _Bool retval;
    uint32_t masking_state = __get_PRIMASK();
    __disable_irq();
    retval=isr_flag;
    isr_flag=false;
    __set_PRIMASK(masking_state);
    return retval;
}

_Bool systick_has_fired()
{
    uint32_t primask=get_primask();
    disable_irq();
    _Bool retval=systick_fired_flag;
    systick_fired_flag=false;
    set_primask(primask);

    return retval;
}

void __attribute__((isr)) SystickHandler()
{
    systick_fired_flag = true;
    for(uint32_t i=0; i<num_callbacks; i++)
        callback[i]();
}