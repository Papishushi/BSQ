/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:18:10 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 17:10:05 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "tools.h"

typedef struct s_board
{
	int			n_lines;
	int			n_columns;
	char		c_empty;
	char		c_obstacle;
	char		c_fill;
	t_matrix	map;
	t_mat_aux	aux_map;
}	t_board;

void	create_board(t_board *board);
void	create_map(t_matrix map, t_string str);
#endif
