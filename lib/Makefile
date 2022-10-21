CC = gcc
HOME_DIR = ${shell pwd}
CFLAG= -O1
HEADER_TOP=lib/driver/tlpi_hdr.h

vpath %.c ./lib/driver
vpath %.h ./lib/include
vpath %.inc ./lib
OPT=copy
LIB_INC=lib/include
LIB_SRC=lib/driver

SRC := $(wildcard $(LIB_SRC/*.c))
HDR := $(wildcard $(LIB_INC/*.h))
SRC := $(subst,$(LIB_SRC/,,${SRC}))
HRD := $(subst,$(LIB_INC/,,${HDR}))


all:cp clean

cp:${OPT}.o ${OBJ} 
	${CC} -o $@ $^ 

${OPT}.o:${OPT}.c  
	${CC} ${CFLAG} -c $^

${OBJ}:%.o:%.c ${HDR}
	${CC} -c ${CFLAG} $< -o $@

clean:
	@rm -f *.o
