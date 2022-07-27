/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:31:41 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 02:02:16 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solve.h"

void	create_aux_map(t_matrix map, t_matrix map_aux, int lines, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < counter)
		{
			map_aux[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

void	ft_print_map(t_matrix mat, int lines, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < counter)
		{
			ft_putchar(mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	put_ones(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board->n_lines)
	{
		j = 0;
		while (j < board->n_columns)
		{
			if ((i == 0 || j == 0) && board->aux_map[i][j] != '\n')
				board->aux_map[i][j] = '1';
			j++;
		}
		i++;
	}
	ft_print_map(board->aux_map, board->n_lines, board->n_columns);
}

void	put_obstacles(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board->n_lines)
	{
		j = 0;
		while (j < board->n_columns)
		{
			if (board->aux_map[i][j] == board->c_obstacle)
				board->aux_map[i][j] = '0';
			j++;
		}
		i++;
	}
	ft_print_map(board->aux_map, board->n_lines, board->n_columns);
}
