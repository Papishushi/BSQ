/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:31:41 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 17:10:30 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solve.h"
#include "../headers/solve1.h"

void	create_aux_map(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < board->n_lines)
	{
		j = 0;
		while (j < board->n_columns)
		{
			if (board->map[i][j] == board->c_empty)
				board->aux_map[i][j] = -1;
			if (board->map[i][j] == board->c_obstacle)
				board->aux_map[i][j] = 0;
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
				if (board->aux_map[i][j] == -1)
					board->aux_map[i][j] = 1;
			j++;
		}
		i++;
	}
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
			if (board->aux_map[i][j] == 0)
				board->aux_map[i][j] = 0;
			j++;
		}
		i++;
	}
	joga_bonito(board);
}
