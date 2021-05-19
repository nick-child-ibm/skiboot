// SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
/* Copyright 2021 IBM Corp.*/
#ifndef SECVAR_CRYPTO_ERR_H
#define SECVAR_CRYPTO_ERR_H
enum errors {
	SUCCESS = 0,
	AUTH_FAIL = -1,
	PKCS7_FAIL = -2,
	ESL_FAIL = -3,
	CERT_FAIL = -4,
	ARG_PARSE_FAIL = -5,
	INVALID_VAR_NAME = -6,
	INVALID_FILE = -7,
	FILE_WRITE_FAIL = -8,
	INVALID_TIMESTAMP = -9,
	HASH_FAIL = -10,
	ALLOC_FAIL = -11,
	UNKNOWN_COMMAND = -12
};
#endif
