/**
 * hmi.h
 *
 * Created on: July 25, 2026
 *     Author: Dmitry Murashov
 *
 * HMI - Human-Machine Inteface (LED indication)
 */

#ifndef APPLICATION_HMI_H_
#define APPLICATION_HMI_H_

/****************************************************************************
* Included Files
****************************************************************************/

/****************************************************************************
* Pre-processor Definitions
****************************************************************************/

/****************************************************************************
* Public Types
****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
* Public Data
****************************************************************************/

#ifdef EXTERN
#error EXTERN is defined
#endif

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
* Public Function Prototypes
****************************************************************************/

void hmiInit(void);
void hmiSetMotorLed(int aOn);

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#undef EXTERN
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __ASSEMBLY__ */

#endif /* APPLICATION_HMI_H_ */

