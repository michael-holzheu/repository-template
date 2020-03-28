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

#include "lib/util_opt.h"
#include "lib/util_prg.h"

#include "opts.h"

/*
 * Program configuration
 */
struct util_prg prg = {
	.desc	= "Show an example",
	.copyright_vec = {
		{
			.owner = "Michael Holzheu",
			.pub_first = 2020,
			.pub_last = 2020,
		},
		UTIL_PRG_COPYRIGHT_END
	}
};

/*
 * Options with defaults
 */
struct opts opts = {
	.bool_test = true,
	.int_test = 0,
};

/*
 * Command line options
 */
static struct util_opt opt_vec[] = {
	UTIL_OPT_SECTION("OPTIONS"),
	{
		.option = { "int-test", required_argument, NULL, 'i'},
		.argument = "INTEGER",
		.desc = "Hold an integer"
	},
	{
		.option = { "bool-test", no_argument, NULL, 'b'},
		.desc = "Boolean option",
	},
	UTIL_OPT_HELP,
	UTIL_OPT_VERSION,
	UTIL_OPT_END
};

/*
 * Parse command line options
 */
void opts_parse(int argc, char *argv[])
{
	int c;

	util_prg_init(&prg);
	util_opt_init(opt_vec, NULL);

	while (1) {
		c = util_opt_getopt_long(argc, argv);
		if (c == -1)
			break;
		switch (c) {
		case 'h':
			util_prg_print_help();
			util_opt_print_help();
			exit(EXIT_SUCCESS);
		case 'v':
			util_prg_print_version();
			exit(EXIT_SUCCESS);
		case 'b':
			opts.bool_test = true;
			break;
		case 'i':
			if (sscanf(optarg, "%d", &opts.int_test) != 1)
				errx(EXIT_FAILURE, "Invalid int specified: %s", optarg);
			break;
		default:
			util_opt_print_parse_error(c, argv);
			exit(EXIT_FAILURE);
		}
	}
}
