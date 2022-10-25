CC = gcc
HOME_DIR = ${shell pwd}
APP = app

HEADER_TOP=lib/include/tlpi_hdr.h

vpath %.c   lib/driver
vpath %.h   lib/include
vpath %.inc lib/include

OPT=${APP}/tee
LIB_INC=lib/include
LIB_SRC=lib/driver

INCLUDE := -I ${LIB_INC} ${HEADER_TOP} 
CFLAG :=${INCLUDE} -Wall 

SRC := $(wildcard $(LIB_SRC)/*.c)
HDR := $(wildcard $(LIB_INC)/*.h)
SRC := $(subst $(LIB_SRC)/,,$(SRC))
HDR := $(subst $(LIB_INC)/,,$(HDR))
OBJ := $(patsubst %.c,%.o,$(SRC))

.PHONY:all clean

all:${OPT}
	echo -e "${HOME_DIR}\n"

${OPT}:${OPT}.o ${OBJ}
	${CC} ${CFLAG} $^ -o ${OPT}

${OPT}.o:${OPT}.c
	${CC} -c $<

${OBJ}:%.o:%.c 
	${CC} -c ${CFLAG} $< -o $@

clean:
	@rm -f *.o *.i
