#ifndef SD_STM32_HEADER
#define SD_STM32_HEADER

/*-----------------------------------------------------------------------*/
/* Device Timer Interrupt Procedure  (Platform dependent)                */
/*-----------------------------------------------------------------------*/
/* This function must be called in period of 10ms                        */

void sdcard_systick_timerproc(void);

#endif
