/*
 * example - Template for a program
 *
 * Example: Show how to program
 *
 * Copyright Michael Holzheu 2020
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "lib/example.h"
#include "lib/util_base.h"

#include "opts.h"

int main(int argc, char *argv[])
{
	opts_parse(argc, argv);
	printf("bool: %d\n", opts.bool_test);
	printf("int.: %d\n", opts.int_test);
	libexample_test();
	return 0;
}
