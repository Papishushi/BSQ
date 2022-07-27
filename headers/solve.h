/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:59:21 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 02:02:23 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "map.h"

void	create_aux_map(t_matrix map, t_matrix map_aux, int lines, int counter);
void	ft_print_map(t_matrix mat, int lines, int counter);
void	put_ones(t_board *board);
void	put_obstacles(t_board *board);
#endif
