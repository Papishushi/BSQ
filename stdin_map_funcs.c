/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_map_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:58:38 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/26 22:03:08 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

static int	getl_in(char *str)
{
	int	i;
	int	temp;
	int	lenght;

	i = 0;
	temp = 0;
	lenght = 0;
	while (str[i] != '\n')
		i++;
	while (str[i++] != '\n')
		lenght++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (temp != lenght)
				return (0);
			temp = 0;
		}
		i++;
		temp++;
	}
	return (lenght);
}

static char *get_params_in(char *str)
{
	int 	i;
	int 	count_elems;
	char	*element_map;

	i = 0;
	count_elems = 0;
	while (str[count_elems] != '\0')
		if(str[count_elems++] == '\n')
			break ;
	element_map = malloc(sizeof(char) * count_elems + 1);
	while (str[i] != '\0' && i < count_elems)
	{
		element_map[i] =  str[i];
		if(str[i++] == '\n')
			break ;
	}
	element_map[i] = '\0';
	return (element_map);
}

int	check_maps_in(char *str, t_bsq *bsq)
{
	if (str == NULL || check_elem_map(get_params_in(str)) == 0)
	{
		ft_putstr(ERROR_MSG);
		return (0);
	}
	else
	{
		bsq->n_lines = ft_atoi(get_params_in(str)); // lineas
		bsq->n_columns = getl_in(str);
	}
	return (1);
}

void	create_map_in(char **map, char *str)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '\n')
			break ;
		i++;
	}
	while (str[i] != '\0')
	{
		map[x][y] = str[i];
		if(str[i] == '\n')
		{
			x++;
			y = -1;
		}
		i++;
		y++;
	}
}
