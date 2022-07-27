/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:20:54 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 15:47:25 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/custom_io.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	create_board(t_board *board)
{
	int	i;

	i = 0;
	board->map = malloc(sizeof(t_string) * board->n_lines);
	board->aux_map = malloc(sizeof(t_mat_aux) * board->n_lines);
	while (i < board->n_lines)
	{
		board->map[i] = malloc(sizeof(char) * board->n_columns);
		board->aux_map[i] = malloc(sizeof(int) * board->n_columns);
		i++;
	}
}

void	create_map(t_matrix map, t_string str)
{
	int		fd1;
	int		i;
	int		j;
	char	buffer[1];

	i = 0;
	j = 0;
	fd1 = open_file(str);
	while (read(fd1, &buffer, 1) > 0)
		if (*buffer == '\n')
			break ;
	while (read(fd1, &buffer, 1) > 0)
	{
		if (*buffer != '\n')
			map[i][j] = *buffer;
		if (*buffer == '\n')
		{
			i++;
			j = -1;
		}
		j++;
	}
}
