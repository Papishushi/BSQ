/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:18:10 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 15:59:53 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "tools.h"
# include "map.h"

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
