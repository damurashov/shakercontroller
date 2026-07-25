/**
 * pinout.h
 *
 * Created on: July 22, 2026
 *     Author: Dmitry Murashov
 */

#ifndef APPLICATION_PINOUT_H_
#define APPLICATION_PINOUT_H_

/****************************************************************************
* Included Files
****************************************************************************/

/****************************************************************************
* Pre-processor Definitions
****************************************************************************/

#define MOTOR_DIR_1_PIN (LL_GPIO_PIN_0)
#define MOTOR_DIR_1_PORT (GPIOA)
#define MOTOR_DIR_2_PIN (LL_GPIO_PIN_1)
#define MOTOR_DIR_2_PORT (GPIOA)
#define MOTOR_HALL_EP_ADC_HANDLER ADC1_IRQHandler

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

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#undef EXTERN
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __ASSEMBLY__ */

#endif /* APPLICATION_PINOUT_H_ */
