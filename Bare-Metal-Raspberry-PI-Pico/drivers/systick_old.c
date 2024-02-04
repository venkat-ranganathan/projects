/*
Venkat Ranganathan
EECE 558 - Embedded Systems Design
Prof Summerville
Assignment 3

systick driver controls the timing of the main loop, runs every 1000 ms
*/

#include "systick.h"

#define SYSTICK_FREQ_HZ 1000
#define SYSTICK_TOP (SYS_CLOCK/SYSTICK_FREQ_HZ)

void configure_systick()
{
    // SET RVR to m0plus -> syst_rvr; systick reload value register
    m0plus->syst_rvr = SYSTICK_TOP;

    // WRITE 0 to CVR to force immediate reset; count value register
    m0plus->syst_cvr = 0;

    // CONFIGURE CSR Clock Source and Enable; systick control & status register
    m0plus->syst_csr = M0PLUS_SYST_CSR_CLKSOURCE(1) | M0PLUS_SYST_CSR_ENABLE(1);
}

_Bool systick_has_fired()
{
    return (m0plus->syst_csr & M0PLUS_SYST_CSR_COUNTFLAG_MASK);
}