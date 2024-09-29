/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>

int main(void)
{
	return 0;
}

static int calc_sum(const struct shell *sh, size_t argc, char **argv)
{
	double num1, num2;
	if (sscanf(argv[1], "%lf", &num1) == 0) {
		printf("Invalid first argument\n");
		return -1;
	}
	if (sscanf(argv[2], "%lf", &num2) == 0) {
		printf("Invalid second argument\n");
		return -1;
	}

	printf("%f + %f = %f\n", num1, num2, (num1 + num2));

	return 0;
}

static int calc_sub(const struct shell *sh, size_t argc, char **argv)
{
	double num1, num2;

	if (sscanf(argv[1], "%lf", &num1) == 0) {
		printf("Invalid first argument\n");
		return -1;
	}
	if (sscanf(argv[2], "%lf", &num2) == 0) {
		printf("Invalid second argument\n");
		return -1;
	}

	printf("%f - %f = %f\n", num1, num2, (num1 - num2));

	return 0;
}

static int calc_prod(const struct shell *sh, size_t argc, char **argv)
{
	double num1, num2;

	if (sscanf(argv[1], "%lf", &num1) == 0) {
		printf("Invalid first argument\n");
		return -1;
	}
	if (sscanf(argv[2], "%lf", &num2) == 0) {
		printf("Invalid second argument\n");
		return -1;
	}

	printf("%f * %f = %f\n", num1, num2, (num1 * num2));

	return 0;
}

static int calc_div(const struct shell *sh, size_t argc, char **argv)
{
	double num1, num2;

	if (sscanf(argv[1], "%lf", &num1) == 0) {
		printf("Invalid first argument\n");
		return -1;
	}
	if (sscanf(argv[2], "%lf", &num2) == 0) {
		printf("Invalid second argument\n");
		return -1;
	}

	printf("%f * %f = %f\n", num1, num2, (num1 / num2));

	return 0;
}
SHELL_STATIC_SUBCMD_SET_CREATE(
	sub_calc, SHELL_CMD_ARG(sum, NULL, "Sum of two numbers", calc_sum, 3, 0),
	SHELL_CMD_ARG(sub, NULL, "Subtraction of two numbers", calc_sub, 3, 0),
	SHELL_CMD_ARG(prod, NULL, "Product of two numbers", calc_prod, 3, 0),
	SHELL_CMD_ARG(div, NULL, "Division of two numbers", calc_div, 3, 0), SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(
	calculator, &sub_calc,
	"A calculator with operations for sum, subtraction, product and division of two numbers:\n"
	"Response syntax: num1 < + | - | * | / > num2 = result\n",
	NULL);
