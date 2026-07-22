//
// appmain.c
//
// Created on: July 22, 2026
//     Author: Dmitry Murashov
//

#include "pinout.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_exti.h"
#include "stm32f0xx_ll_exti.h"
#include "stm32f0xx_ll_gpio.h"
#include <stdint.h>

enum {
	DirEp1,
	DirEp2,
};

static int sDir = DirEp1;

void ENDPOINT_1_ISR_FUNC_NAME()
{
	const volatile uint32_t pr = EXTI->PR;
	LL_EXTI_ClearFlag_0_31(ENDPOINT_1_EXTI_LINE | ENDPOINT_2_EXTI_LINE);
	__DSB();

	if (pr & ENDPOINT_1_EXTI_LINE)
	{
		sDir = DirEp2;
	}
	else if (pr & ENDPOINT_2_EXTI_LINE)
	{
		sDir = DirEp1;
	}
}

int isEp1Contact(void)
{
	return LL_GPIO_ReadInputPort(ENDPOINT_1_PORT) & ENDPOINT_1_PIN;
}

int isEp2Contact(void)
{
	return LL_GPIO_ReadInputPort(ENDPOINT_2_PORT) & ENDPOINT_2_PIN;
}

void setMotorDir(int dir)
{
	switch (dir)
	{
		case DirEp1:
		{
			LL_GPIO_SetOutputPin(MOTOR_DIR_1_PORT, MOTOR_DIR_1_PIN);
			LL_GPIO_ResetOutputPin(MOTOR_DIR_2_PORT, MOTOR_DIR_2_PIN);
			break;
		}
		case DirEp2:
		default:
		{
			LL_GPIO_ResetOutputPin(MOTOR_DIR_1_PORT, MOTOR_DIR_1_PIN);
			LL_GPIO_SetOutputPin(MOTOR_DIR_2_PORT, MOTOR_DIR_2_PIN);
			break;
		}
	}
}

void init(void)
{
	GPIO_InitTypeDef init;

	init.Pin = MOTOR_DIR_1_PIN;
	init.Mode = GPIO_MODE_OUTPUT_PP;
	init.Pull = GPIO_NOPULL;
	init.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(MOTOR_DIR_1_PORT, &init);

	init.Pin = MOTOR_DIR_2_PIN;
	init.Mode = GPIO_MODE_OUTPUT_PP;
	init.Pull = GPIO_NOPULL;
	init.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(MOTOR_DIR_2_PORT, &init);

	init.Pin = ENDPOINT_1_PIN;
	init.Mode = GPIO_MODE_IT_FALLING;
	init.Speed = GPIO_SPEED_FREQ_LOW;
	init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(ENDPOINT_1_PORT, &init);
	HAL_NVIC_EnableIRQ(ENDPOINT_1_IRQN);

	init.Pin = ENDPOINT_2_PIN;
	init.Mode = GPIO_MODE_IT_FALLING;
	init.Speed = GPIO_SPEED_FREQ_LOW;
	init.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(ENDPOINT_2_PORT, &init);
	HAL_NVIC_EnableIRQ(ENDPOINT_2_IRQN);
}

void applicationMain(void)
{
	init();

	while (1)
	{
		setMotorDir(sDir);
	}
}
