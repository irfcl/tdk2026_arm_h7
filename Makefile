######################################
# target
######################################
TARGET = h7_test

#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m7

# fpu
# 將原本的 fpv5-d16 改為 fpv5-dp-d16 (代表 Double Precision 雙精度)
FPU = -mfpu=fpv5-dp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32H723xx

# C includes
C_INCLUDES =  \
-ICore/Inc