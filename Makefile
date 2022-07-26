###############################################################################
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = check_mapa.c main.c solve.c
OBJS = ${CFILES:.c=.o}
NAME = bsq
###############################################################################
MAPGEN = map_generator.pl
MAPNAME = map
ROWS = 10
COLS = 20
DENSITY = 2
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean fclean all test
###############################################################################
all:		fclean ${MAPNAME} ${NAME} test

test:
		./${NAME} ${MAPNAME}

${NAME}:	${OBJS}
		@${CC} -o ${NAME} ${OBJS}

${MAPNAME}:
		@chmod +x ${MAPGEN}
		@./${MAPGEN} ${COLS} ${ROWS} ${DENSITY} > ${MAPNAME}
		@cat ${MAPNAME}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${NAME} ${MAPNAME}