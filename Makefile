#Basic setting for Makefile
CC = gcc
HOME_DIR = ${shell pwd}

#app directory includes our applications
#APP = app 

#directory for lib
vpath %.c   lib/driver
vpath %.h   lib/include
vpath %.inc lib/include

OPT=app/tee
LIB_INC=lib/include/
LIB_SRC=lib/driver/


SRC := $(wildcard $(LIB_SRC)*.c)
HDR := $(wildcard $(LIB_INC)*.h)
OBJ := $(patsubst %.c,%.o,$(SRC))
SRC := $(subst $(LIB_SRC)/,,$(SRC))
HDR := $(subst $(LIB_INC)/,,$(HDR))
INCLUDE := -I ${LIB_INC}  
CFLAG :=${INCLUDE} -Wall

.PHONY:all clean

all:${OPT}

${OPT}:${OPT}.o ${OBJ}
	${CC} ${CFLAG} $^ -o ${OPT}

${OPT}.o:${OPT}.c
	${CC} ${CFLAG} -c $< -o $@

${OBJ}:%.o:%.c 
	${CC} -c ${CFLAG} $< -o $@

clean:
	@rm -rf lib/include/*.h.gch  lib/driver/*.o app/*.o
