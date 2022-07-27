/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:03:29 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 17:18:15 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/custom_io.h"
#include "headers/check_maps.h"
#include "headers/stdin_map_funcs.h"
#include "headers/solve.h"
#include "headers/errors.h"

static int	check_empty_board(t_board *board)
{
	if (board->map == 0 || board->aux_map == 0)
	{
		free(board->aux_map);
		free(board->map);
		return (ft_puterr_o(MAP_ERROR_MSG));
	}
	return (0);
}

static int	stdin_mode_calls(t_board *board, t_string input)
{
	check_maps_in(input, board);
	create_board(board);
	if (check_empty_board(board))
		return (ft_puterr_o(MAP_ERROR_MSG));
	if (board->map != NULL && board->aux_map != NULL)
	{
		create_map_in(board->map, input);
		ft_print_map(board->map, board->n_lines, board->n_columns);
		create_aux_map(board);
		ft_putchar('\n');
		put_ones(board);
		put_obstacles(board);
		free(board->aux_map);
		free(board->map);
		free(input);
		return (0);
	}
	free(input);
	return (ft_puterr_o(MAP_ERROR_MSG));
}

static int	arg_mode_calls(t_board *board, t_string argv[])
{
	check_maps(argv[1], board);
	create_board(board);
	if (check_empty_board(board))
		return (ft_puterr_o(MAP_ERROR_MSG));
	if (board->map != NULL && board->aux_map != NULL)
	{
		create_map(board->map, argv[1]);
		create_aux_map(board);
		ft_putchar('\n');
		put_ones(board);
		put_obstacles(board);
		ft_print_map(board->map, board->n_lines, board->n_columns);
		free(board->aux_map);
		free(board->map);
		return (0);
	}
	return (ft_puterr_o(MAP_ERROR_MSG));
}

int	main(int argc, char *argv[])
{
	t_board		board;
	t_string	input;

	input = NULL;
	if (argc == 1)
	{
		input = read_std_input();
		return (stdin_mode_calls(&board, input));
	}
	else
		return (arg_mode_calls(&board, argv));
}
