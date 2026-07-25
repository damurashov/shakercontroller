/**
 * motor.h
 *
 * Created on: July 25, 2026
 *     Author: Dmitry Murashov
 */

#ifndef APPLICATION_MOTOR_H_
#define APPLICATION_MOTOR_H_

/****************************************************************************
* Included Files
****************************************************************************/

/****************************************************************************
* Pre-processor Definitions
****************************************************************************/

/****************************************************************************
* Public Types
****************************************************************************/

enum {
	DirEp1 = 0,
	DirEp2,
};

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

int motorIsEp1Contact(void);
int motorIsEp2Contact(void);
void motorSetDir(int dir);
void motorInit(void);

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#undef EXTERN
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* __ASSEMBLY__ */

#endif /* APPLICATION_MOTOR_H_ */
