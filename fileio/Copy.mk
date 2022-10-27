CC = gcc
HOME_DIR = ${shell pwd}

HEADER_TOP=lib/driver/tlpi_hdr.h

vpath %.c ./lib/driver
vpath %.h ./lib/include
vpath %.inc ./lib

OPT=copy
LIB_INC=lib/include
LIB_SRC=lib/driver

INCLUDE := -I ${LIB_INC} 
CFLAG :=${INCLUDE} -Wall 

SRC := $(wildcard $(LIB_SRC)/*.c)
HDR := $(wildcard $(LIB_INC)/*.h)
SRC := $(subst $(LIB_SRC)/,,$(SRC))
HDR := $(subst $(LIB_INC)/,,$(HDR))
OBJ := $(patsubst %.c,%.o,$(SRC))

.PHONY:all clean

all: cp

cp:${OPT}.o ${OBJ}
	${CC} ${CFLAG} $^ -o cp

${OPT}.o:${OPT}.c
	${CC} -c $<

${OBJ}:%.o:%.c 
	${CC} -c ${CFLAG} $< -o $@

clean:
	@rm -f *.o
