#include "bsq.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	return (fd);
}

char	*get_params_map(char *str)
{
	int		fd1;
	char	buffer[1];
	int		i;
	int		count_elems;
	char	*element_map;

	i = 0;
	count_elems = 0;
	fd1 = open_file(str);
	while (read(fd1, &buffer, sizeof(char)) > 0)
	{
		if(*buffer == '\n')
			break ;
		count_elems++;
	}
	close(fd1);
	element_map = (char*)malloc(sizeof(char) * count_elems+1);
	fd1 = open_file(str);
	while (read(fd1, &buffer, sizeof(char)) > 0 && i < count_elems)
	{
		if(i < count_elems)
			element_map[i] =  *buffer;
		if(*buffer == '\n')
			break ;
		i++;
	}
	element_map[i] = '\0';
	return (element_map);
/*
	if ((element_map[0] - '0') != lines)
		return (0);*/
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] >= '0' && str[i] <= '9') && (i < (ft_strlen(str) - 2)))
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	return (j);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}


int	read_file(char *str)
{
	int		fd1;
	char	buffer[1];
	int		counter = 0;
	int		lines = 1;
	int		check = 0;


	fd1 = open_file(str);
	while (read(fd1, &buffer, sizeof(char)) > 0)
		if(*buffer == '\n')
			break ;
	while (read(fd1, &buffer, sizeof(char)) > 0)
	{
		check++;
		if(*buffer == '\n')
		{
			if (check == 1)
				return (0); //MAP ERROR
			break ;
		}
	}
	while (read(fd1, &buffer, sizeof(char)) > 0)
	{
		counter++;
		if(*buffer == '\n')
		{
			if (counter == check)
			{
				check = counter;
				counter = 0;
			}
			else
				return (0);//MAP ERROR
		lines++;
		}
	}
	if (ft_atoi(get_params_map(str)) != lines)
	{
		return(0);
	}
	close(fd1);
	return (check);
}

void	create_map(char **map, char *str)
{
	int		fd1;
	int		i;
	int		j;
	char	buffer[1];

	i = 0;
	j = 0;
	fd1 = open_file(str);
	while (read(fd1, &buffer, sizeof(char)) > 0)
		if(*buffer == '\n')
			break ;
	while (read(fd1, &buffer, sizeof(char)) > 0)
	{
		map[i][j] = *buffer;
		if(*buffer == '\n')
		{
			i++;
			j = -1;
		}
		j++;
	}
}

int	check_elem_map(char *element_map)
{
	int k;
	k = 0;
	while (k < 4)
	{
		if(!(element_map[k] >= 32 && element_map[k] <= 126))
			return (0); // MAP ERROR
		if(element_map[k] == element_map[k+1])
			return (0);
			// MAP ERROR
		k++;
	}
	return (1);
}

int	check_mapas(char *str, t_bsq *bsq)
{
	if (read_file(str) == 0 || check_elem_map(get_params_map(str)) == 0)
	{
		ft_putstr(ERROR_MSG);
		return (0);
	}
	else
	{
		bsq->n_lines = ft_atoi(get_params_map(str)); // lineas
		bsq->n_columns = read_file(str);
	}
	return (1);
}
