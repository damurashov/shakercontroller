//
// appmain.c
//
// Created on: July 22, 2026
//     Author: Dmitry Murashov
//

#include "config.h"
#include "hmi.h"
#include "motor.h"
#include <stdint.h>

void applicationMain(void)
{
	motorInit();
	hmiInit();

	while (1)
	{
		if (motorIsEp1Contact())
		{
			motorSetDir(DirEp2);
			hmiSetMotorLed(1);
		}
		else if (motorIsEp2Contact())
		{
			motorSetDir(DirEp1);
			hmiSetMotorLed(1);
		}
		else
		{
			hmiSetMotorLed(0);
		}
	}
}
