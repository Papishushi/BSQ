#ifndef BSQ_H
# define BSQ_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define ERROR_MSG "map error\n"

typedef struct s_bsq
{
	int		n_lines;
	int		n_columns;
	char	c_empty;
	char	c_obstacle;
	char	c_fill;
	char	**map;
	char	**aux_map;
}	t_bsq;

int		check_mapas(char *str, t_bsq *bsq);
void	put_ones(t_bsq *bsq);
void	put_obstacles(t_bsq *bsq);
char *get_params_map(char *str, t_bsq *bsq);
int		read_file(char *str,t_bsq *bsq);
void	ft_putstr(char *str);
void	ft_print_mat(char **mat, int lines , int counter);
void	create_map(char **map, char *str);
int		check_elem_map(char *element_map);
void	create_aux_mat(char **map, char **map_aux, int lines, int counter);
void	ft_putchar(char c);

#endif