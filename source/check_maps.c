/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:32:27 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 18:13:48 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/custom_io.h"
#include "../headers/errors.h"

static void	chk_gb_val(t_board *board, t_string element_map, \
						int count_elems)
{
	if (count_elems - 3 >= 0)
		board->c_empty = element_map[count_elems - 3];
	if (count_elems - 2 >= 0)
		board->c_obstacle = element_map[count_elems - 2];
	if (count_elems - 1 >= 0)
		board->c_fill = element_map[count_elems - 1];
	free(element_map);
}

static int	count_elems(t_string str)
{
	int			fd;
	int			count;
	char		buffer[1];

	count = 0;
	fd = open_file(str);
	while (read(fd, &buffer, 1) > 0)
	{
		if (*buffer == '\n')
			break ;
		count++;
	}
	close(fd);
	return (count);
}

t_string	get_params_map(t_string str, t_board *board)
{
	int			fd;
	char		buffer[1];
	int			i;
	int			count;
	t_string	element_map;

	i = 0;
	count = count_elems(str);
	element_map = malloc(sizeof(char) * count + 1);
	fd = open_file(str);
	while (read(fd, buffer, 1) > 0 && i < count)
	{
		if (*buffer == '\n')
			break ;
		element_map[i++] = *buffer;
	}
	element_map[i] = '\0';
	chk_gb_val(board, element_map, count);
	return (element_map);
}

int	check_elem_map(t_string element_map)
{
	int	k;

	k = ft_strlen(element_map) - 3;
	while (k < ft_strlen(element_map))
	{
		if (!(element_map[k] >= 32 && element_map[k] <= 126))
			return (0);
		k++;
	}
	k = 0;
	if (element_map[k] == element_map[k + 1] && \
		element_map[k + 1] == element_map[k + 2] && \
		element_map[k] == element_map[k + 2])
		return (0);
	return (1);
}

int	check_maps(t_string str, t_board *board)
{
	if (read_file(str, board) == 0 || \
		check_elem_map(get_params_map(str, board)) == 0)
		return (ft_puterr_o(MAP_ERROR_MSG));
	else
	{
		board->n_lines = ft_atoi(get_params_map(str, board));
		board->n_columns = read_file(str, board);
	}
	return (1);
}
