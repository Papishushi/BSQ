/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:59:21 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 17:07:39 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "map.h"

void	create_aux_map(t_board *board);
void	ft_print_map(t_matrix mat, int lines, int counter);
void	put_ones(t_board *board);
void	put_obstacles(t_board *board);
int		min_value(t_point point, t_board *board);
t_point	final_fucking_result(t_board *board);
void	final_change(t_board *board);

#endif
