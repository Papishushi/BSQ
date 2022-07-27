/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_map_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:58:38 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 17:18:59 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/check_maps.h"
#include "../headers/errors.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

static int	getl_in(t_string str)
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

static t_string	get_params_in(t_string str)
{
	int			i;
	int			count_elems;
	t_string	element_map;

	i = 0;
	count_elems = 0;
	while (str[count_elems] != '\0')
		if (str[count_elems++] == '\n')
			break ;
	element_map = malloc(sizeof(char) * count_elems + 1);
	while (str[i] != '\0' && i < count_elems)
	{
		element_map[i] = str[i];
		if (str[i++] == '\n')
			break ;
	}
	element_map[i] = '\0';
	return (element_map);
}

int	check_maps_in(t_string str, t_board *board)
{
	if (str == NULL || check_elem_map(get_params_in(str)) == 0)
		return (ft_puterr_z(MAP_ERROR_MSG));
	else
	{
		board->n_lines = ft_atoi(get_params_in(str));
		board->n_columns = getl_in(str);
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
		if (str[i] == '\n')
			break ;
		i++;
	}
	while (str[i] != '\0')
	{
		map[x][y] = str[i];
		if (str[i] == '\n')
		{
			x++;
			y = -1;
		}
		i++;
		y++;
	}
}
