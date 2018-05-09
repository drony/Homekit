#
# Main component makefile.
#
# This Makefile can be left empty. By default, it will take the sources in the 
# src/ directory, compile them and link them into lib(subdirectory_name).a 
# in the build directory. This behaviour is entirely configurable,
# please read the ESP-IDF documents if you need to do this.
#


#
# Feather32 Variant
# 
CFLAGS += -I$(PROJECT_PATH)/components/arduino/variants/feather_esp32/
CFLAGS += -DARDUINO_FEATHER_ESP32 -DESP32


#
# WOLFSSL
# 
WOLFSSL_SETTINGS =        \
    -DSIZEOF_LONG_LONG=8  \
    -DSMALL_SESSION_CACHE \
    -DWOLFSSL_SMALL_STACK \
	-DWOLFCRYPT_HAVE_SRP  \
	-DWOLFSSL_SHA512      \
    -DHAVE_CHACHA         \
	-DHAVE_HKDF			  \
    -DHAVE_ONE_TIME_AUTH  \
    -DHAVE_ED25519        \
	-DHAVE_ED25519_KEY_EXPORT\
	-DHAVE_ED25519_KEY_IMPORT\
    -DHAVE_OCSP           \
    -DHAVE_CURVE25519     \
	-DHAVE_POLY1305       \
    -DHAVE_SNI            \
    -DHAVE_TLS_EXTENSIONS \
    -DTIME_OVERRIDES      \
    -DNO_DES              \
    -DNO_DES3             \
    -DNO_DSA              \
    -DNO_ERROR_STRINGS    \
    -DNO_HC128            \
    -DNO_MD4              \
    -DNO_OLD_TLS          \
    -DNO_PSK              \
    -DNO_PWDBASED         \
    -DNO_RC4              \
    -DNO_RABBIT           \
    -DNO_STDIO_FILESYSTEM \
    -DNO_WOLFSSL_DIR      \
    -DNO_DH               \
    -DWOLFSSL_STATIC_RSA  \
    -DWOLFSSL_IAR_ARM     \
    -DNDEBUG              \
    -DHAVE_CERTIFICATE_STATUS_REQUEST \
    -DCUSTOM_RAND_GENERATE_SEED=os_get_random

CFLAGS += -I$(PROJECT_PATH)/components/wolfssl/
CFLAGS += -I$(PROJECT_PATH)/components/
CFLAGS += $(WOLFSSL_SETTINGS) -DFREERTOS -DESP32 -DED25519_ENABLED -DMBEDTLS_ED25519_C



#
# Homekit
#
COMPONENT_SRCDIRS += HAP 
COMPONENT_ADD_INCLUDEDIRS += HAP

#
# Crypto
#
COMPONENT_SRCDIRS += Crypto
COMPONENT_ADD_INCLUDEDIRS += Crypto

#
# ArduinoJson
#
COMPONENT_SRCDIRS += ArduinoJson
COMPONENT_ADD_INCLUDEDIRS += ArduinoJson

#
# Plugins
#
COMPONENT_SRCDIRS += HAP/plugins 
COMPONENT_ADD_INCLUDEDIRS += HAP/plugins 
