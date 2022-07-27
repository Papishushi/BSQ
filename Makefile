###############################################################################
CC = cc
CFLAGS = -Wall -Wextra -Werror
SAN = -fsanitize=address
CFILES = check_maps.c custom_io.c errors.c map.c solve.c solve1.c stdin_map_funcs.c tools.c
MAIN = main.o
SRCS = ${addprefix source/,${CFILES}}
OBJS = ${SRCS:.c=.o}
HFILES = check_maps.h custom_io.h errors.h map.h solve.h tools.h
HDRS = ${addprefix headers/,${HFILES}}
NAME = bsq
###############################################################################
MAPGEN = map_generator.pl
MAPNAME = map
ROWS = 100
COLS = 100
DENSITY = 2
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean fclean all test
###############################################################################
all:		fclean ${MAPNAME} ${NAME} test

test:
		./${NAME} ${MAPNAME}

${NAME}:	${OBJS} ${MAIN}
		@${CC} -o ${NAME} ${OBJS} ${MAIN}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I HEA

${MAPNAME}:
		@chmod +x ${MAPGEN}
		@./${MAPGEN} ${COLS} ${ROWS} ${DENSITY} > ${MAPNAME}
#		@cat ${MAPNAME}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${NAME} ${MAPNAME}
