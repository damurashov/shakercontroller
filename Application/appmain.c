//
// appmain.c
//
// Created on: July 22, 2026
//     Author: Dmitry Murashov
//

#include "config.h"
#include "motor.h"
#include <stdint.h>

void applicationMain(void)
{
	motorInit();

	while (1)
	{
		if (motorIsEp1Contact())
		{
			motorSetDir(DirEp2);
		}
		else if (motorIsEp2Contact())
		{
			motorSetDir(DirEp1);
		}
	}
}
