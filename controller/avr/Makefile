##
## Makefile
## Login : <Amoriello>
## Started on  Thu Jun  9 14:01:05 2011
##
## Author(s):
##  - Amoriello Hutti <amoriello.hutti@gmail.com>
##
## Copyright (C) 2011 Amoriello Hutti
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
##


SRC		= main.cpp pwm_manager.cpp
VPATH		= src/
INCL		=
TARGET		= main

##################
# Target Options #
##################
MCU		= atmega328p
TARGET_ARCH	= -mmcu=$(MCU)
F_CPU		= F_CPU=16000000

################
# Optional add #
################
IPATH		= -I. -I./include/
DEBUG		= -g
# Allocate to an enum type only as many bytes as it needs for the declared range of possible values. Specifically, the enum type will be equivalent to the smallest integer type which has enough room.
# Pack all structure members together without holes.
# @see http://www.nongnu.org/avr-libc/user-manual/using_tools.html
OBJOPT		= -Os -Wall -Werror -fshort-enums -fpack-struct
LDOPT		= -lm -Wl,-Map=$(TARGET).map,--gc-sections -Os

################
# TOOLS        #
################
CC		= avr-gcc -std=c99
CXX		= avr-g++
AVRDUDE		= avrdude -V -p $(MCU)
AVROBJCOPY	= avr-objcopy
AVRSIZE		= avr-size
AVRDUDE		= avrdude

################
# TOOLS  FLAGS #
################
AVRDUDE_PGMER	= -c arduino -b 115200 -P /dev/ttyACM0 #ttyUSB0
AVRDUDE_PGMERISP= -c avrispv2 -P /dev/ttyACM0
AVRDUDE_FLASH	= -U flash:w:$(TARGET).hex
AVRDUDE_FLAGS	= -V -p $(MCU) $(AVRDUDE_PGMER) $(AVRDUDE_FLASH)

CFLAGS		= $(DEBUG) $(TARGET_ARCH) $(OBJOPT) $(IPATH) -D$(F_CPU)
LDFLAGS		= $(DEBUG) $(TARGET_ARCH) $(LDOPT)

# WARNING!!! Be careful of file extensions.
OBJS		= $(SRC:.cpp=.o)

all: $(TARGET).hex size


$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@


$(TARGET).hex: $(TARGET).elf
	$(AVROBJCOPY) -j .text -j .data -O ihex $(TARGET).elf $(TARGET).hex
	$(AVROBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 -O ihex $(TARGET).elf eeprom.hex


upload: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS)


size: $(TARGET).elf
	avr-size --format=avr --mcu=$(MCU) $(TARGET).elf


clean:
	rm -rf $(TARGET).elf *.o *.hex *.map


.cpp.o:
	$(CXX) $(CFLAGS) -c $< -o $@


