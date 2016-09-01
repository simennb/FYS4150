# makefile

CC= c++ -Wall
PROG = warmup

LIB = -lm

${PROG} :	${PROG}.o
		${CC} ${PROG}.o ${LIB} -o ${PROG}

${PROG}.o :	${PROG}.cpp
		${CC} -c ${PROG}.cpp