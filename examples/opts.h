/*
 * example - Template for a program
 *
 * Option parsing
 *
 * Copyright Michael Holzheu 2020
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#ifndef OPTS_H
#define OPTS_H

#include <stdbool.h>

/*
 * Options
 */
struct opts {
	int int_test;		/* For testing integer options */
	bool bool_test;		/* For testing boolean options */
};

extern struct opts opts;

void opts_parse(int argc, char *argv[]);

#endif /* OPTS_H */
