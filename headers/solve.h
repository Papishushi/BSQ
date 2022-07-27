/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:59:21 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 15:59:35 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "map.h"

void	create_aux_map(t_matrix map, t_mat_aux map_aux, int lines, \
        int counter, t_board *board);
void	ft_print_map(t_matrix mat, int lines, int counter);
void	put_ones(t_board *board);
void	put_obstacles(t_board *board);
int     min_value(t_point point, t_board *board);
void    joga_bonito(t_board *board);
t_point    final_fucking_result(t_board *board);
void    final_change(t_board *board);

/// DEBUG
void	ft_print_map_aux(t_mat_aux mat, int lines, int counter);

#endif
