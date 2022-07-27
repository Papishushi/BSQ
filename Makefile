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
ROWS = 50
COLS = 50
DENSITY = 2
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean fclean all test
###############################################################################
all:		fclean ${MAPNAME} ${NAME} exec

exec:
		./${NAME} ${MAPNAME}

${NAME}:	${OBJS} ${MAIN}
		@${CC} -o ${NAME} ${OBJS} ${MAIN}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${MAPNAME}:
		@chmod +x ${MAPGEN}
		@./${MAPGEN} ${COLS} ${ROWS} ${DENSITY} > ${MAPNAME}

clean:
		@${RM} ${OBJS} ${MAIN}

fclean:		clean
		@${RM} ${NAME} ${MAPNAME}
