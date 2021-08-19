// SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
/* Copyright 2020 IBM Corp. */

#ifndef __SECVAR_EDK2_COMPAT__
#define __SECVAR_EDK2_COMPAT__
#include "../secvar.h"
bool setup_mode;


int update_variable_in_bank(struct secvar *update_var, const char *data,
                const uint64_t dsize, struct list_head *bank);

#endif