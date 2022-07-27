/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:55:32 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 17:43:41 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solve1.h"

int	min_value(t_point point, t_board *board)
{
	int	min;

	if (board->n_columns >= board->n_lines)
		min = board->n_lines;
	else
		min = board->n_columns;
	if (board->aux_map[point.x - 1][point.y - 1] < min)
		min = board->aux_map[point.x - 1][point.y - 1];
	if (board->aux_map[point.x][point.y - 1] < min)
		min = board->aux_map[point.x][point.y - 1];
	if (board->aux_map[point.x - 1][point.y] < min)
		min = board->aux_map[point.x - 1][point.y];
	return (min);
}

void	joga_bonito(t_board *board)
{
	int		i;
	int		j;
	t_point	point;

	i = 1;
	while (i < board->n_lines)
	{
		j = 1;
		while (j < board->n_columns)
		{
			point.x = i;
			point.y = j;
			point.value = board->aux_map[i][j];
			if (board->aux_map[i][j] != 0)
				board->aux_map[i][j] = (min_value(point, board) + 1);
			j++;
		}
		i++;
	}
	final_change(board);
}

t_point	final_fucking_result(t_board *board)
{
	int		i;
	int		j;
	int		max;
	t_point	point;

	i = 0;
	max = 0;
	while (i < board->n_lines)
	{
		j = 0;
		while (j < board->n_columns)
		{
			if (board->aux_map[i][j] > max)
			{
				point.x = i;
				point.y = j;
				point.value = board->aux_map[i][j];
				max = point.value;
			}
			j++;
		}
		i++;
	}
	return (point);
}

void	final_change(t_board *board)
{
	t_point	point;
	int		i;
	int		j;

	i = 0;
	point = final_fucking_result(board);
	while (i < point.value)
	{
		j = 0;
		while (j < point.value)
		{
			board->map[point.x - i][point.y - j] = board->c_fill;
			j++;
		}
		i++;
	}
}
