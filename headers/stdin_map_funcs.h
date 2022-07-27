/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_map_funcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:56:51 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 02:49:44 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_MAP_FUNCS_H
# define STDIN_MAP_FUNCS_H
# include "map.h"

int		check_maps_in(t_string str, t_board *s_board);
void	create_map_in(char **map, char *str);
#endif
