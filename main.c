/*********************************/
#include "bsq.h"
#include "stdin_map_funcs.c"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*read_std_input()
{
	int				fd;
	char			buffer[1];
	char			*result;
	unsigned int	lenght;
	unsigned int	index;

	lenght = 0;
	fd = open(0, O_RDONLY);
	while (read(fd, buffer, 1) > 0)
			lenght++;
	result = malloc(sizeof(char *) + sizeof(char) * lenght +1);
	index = 0;
	while (read(0, buffer, 1) > 0)
	{
			result[index] = buffer[0];
			index++;
	}
	result[index] = '\0';
	close(fd);
	return (result);
}

int main(int argc, char *argv[])
{
	int		m;
	int		i;
	char	*input;
	t_bsq	bsq;

	m = 1;
	i = 0;
	input = NULL;
	if(argc == 1)
		input = read_std_input();
	if(input != NULL)
		check_maps_in(input, &bsq);
	else
		check_mapas(argv[m], &bsq);

	printf("FILAS => %d\n", bsq.n_lines);
	printf("COL => %d\n", bsq.n_columns);

	bsq.map = (char **)malloc(sizeof(char *) * bsq.n_lines);
	bsq.aux_map = (char **)malloc(sizeof(char*) * bsq.n_lines);
	while (i < bsq.n_lines)
	{
		bsq.map[i]=(char *)malloc(sizeof(char) * bsq.n_columns);
		bsq.aux_map[i]=(char *)malloc(sizeof(char) * bsq.n_columns);
		i++;
	}
	if (bsq.map == 0 || bsq.aux_map == 0)
	{
		ft_putstr(ERROR_MSG);
		return (1);
	}
	if(input != NULL)
		create_map_in(bsq.map, input);
	else
		create_map(bsq.map, argv[m]);
	ft_print_mat(bsq.map, bsq.n_lines, bsq.n_columns);
	create_aux_mat(bsq.map, bsq.aux_map, bsq.n_lines, bsq.n_columns);
	ft_putchar('\n');
	ft_print_mat(bsq.aux_map, bsq.n_lines, bsq.n_columns);
	return (0);
}
