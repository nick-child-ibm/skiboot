# SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
# -*-Makefile-*-

SECVAR_BACKEND_DIR = libstb/secvar/backend

SUBDIRS += $(SECVAR_BACKEND_DIR)

ifeq ($(SECVAR_CRYPTO_OPENSSL),1)
    SECVAR_CRYPTO_OBJS = crypto-openssl.o
    CFLAGS += -DSECVAR_CRYPTO_OPENSSL
else
ifeq ($(SECVAR_GNU_TLS),1)
    SECVAR_CRYPTO_OBJS = crypto-gnutls.o
    CFLAGS += -DSECVAR_CRYPTO_GNUTLS
else
    SECVAR_CRYPTO_OBJS = crypto-mbedtls.o
    CFLAGS += -DSECVAR_CRYPTO_MBEDTLS
endif
endif

CFLAGS += -Ilibstb/secvar/backend/libstb-secvar/ -Ilibstb/secvar/backend/libstb-secvar/src -Ilibstb/secvar/backend/libstb-secvar/sample -I./libstb/crypto/pkcs7/

SECVAR_BACKEND_OBJS = edk2-compat.o libstb-secvar/src/edk2-compat-process.o edk2-compat-reset.o libstb-secvar/crypto/$(SECVAR_CRYPTO_OBJS)
SECVAR_BACKEND = $(SECVAR_BACKEND_DIR)/built-in.a

$(SECVAR_BACKEND): $(SECVAR_BACKEND_OBJS:%=$(SECVAR_BACKEND_DIR)/%)
