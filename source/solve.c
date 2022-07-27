/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:31:41 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 16:11:36 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/solve.h"
#include "../headers/tools.h"

void	create_aux_map(t_matrix map, t_mat_aux map_aux, int lines, int counter, t_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < counter)
		{
			if(map[i][j] == board->c_empty)
				map_aux[i][j] = -1;
			if(map[i][j] == board->c_obstacle)
				map_aux[i][j] = 0;
			
			//printf("i - %d\n j - %d\n value - %d\n",i,j,map_aux[i][j]);
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
///// ONLY DEBUG
void	ft_print_map_aux(t_mat_aux mat, int lines, int counter)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < counter)
		{
			printf("%d",mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
//////////

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
	ft_print_map_aux(board->aux_map, board->n_lines, board->n_columns);
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
	ft_print_map_aux(board->aux_map, board->n_lines, board->n_columns);
}

int	min_value(t_point point, t_board *board)
{
	int	min;

	if (board->n_columns >= board->n_lines)
		min = board->n_lines;
	else
		min = board->n_columns;
		
	if (board->aux_map[point.x - 1][point.y - 1] < min)
		min = board->aux_map[point.x - 1][point.y - 1] ;
	if (board->aux_map[point.x][point.y - 1] < min)
		min = board->aux_map[point.x][point.y - 1];
	if (board->aux_map[point.x - 1][point.y] < min)
		min = board->aux_map[point.x - 1][point.y];
	return (min);
}

void joga_bonito(t_board *board)
{
	int i;
	int j;
	t_point point;

	i = 1;
	while(i < board->n_lines)
	{
		j = 1;
		while(j < board->n_columns)
		{
			point.x = i;
			point.y = j;
			point.value = board->aux_map[i][j];
			if(board->aux_map[i][j] != 0)
				board->aux_map[i][j] = (min_value(point, board) + 1);
			j++;
		}
		i++;
	}
	final_change(board);
}
t_point final_fucking_result(t_board *board)
{	int	i;
	int j;
	int	max;
	t_point point;
	
	i = 0;
	max = 0;
	while(i < board->n_lines)
	{
		j = 0;
		while(j < board->n_columns)
		{
			if(board->aux_map[i][j] > max)
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
	//printf("x: %d\ny: %d\nval: %d\n",point.x, point.y, point.value);

	return (point);
}

void final_change(t_board *board)
{
	t_point point;
	int i;
	int	j;

	i = 0;
	point = final_fucking_result(board);
	while(i < point.value)
	{
		j = 0;
		while(j < point.value)
		{
			board->map[point.x - i][point.y - j] = board->c_fill;
			j++;	
		}
		i++;
	}
	printf("x: %d\ny: %d\nval: %d\n",point.x, point.y, point.value);
	//ft_print_map(board->map, board->n_lines, board->n_columns);
}

