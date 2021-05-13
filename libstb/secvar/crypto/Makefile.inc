# SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
# -*-Makefile-*-

SECVAR_CRYPTO_DIR = libstb/secvar/crypto
SUBDIRS += $(SECVAR_CRYPTO_DIR)


ifeq ($(SECVAR_CRYPTO_OPENSSL),1)
	# throw error, skiboot should not be built with openssl
    $(error Found SECVAR_CRYPTO_OPENSSL=1, Skiboot cannot be built with OpenSSL)

else
	SECVAR_CRYPTO_OBJS = crypto-mbedtls.o
        CFLAGS_$(SECVAR_CRYPTO_DIR)/ = -DSECVAR_CRYPTO_MBEDTLS

endif


SECVAR_CRYPTO = $(SECVAR_CRYPTO_DIR)/built-in.a

$(SECVAR_CRYPTO): $(SECVAR_CRYPTO_OBJS:%=$(SECVAR_CRYPTO_DIR)/%)
