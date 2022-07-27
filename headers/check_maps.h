/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:37:57 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 02:46:42 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAPS_H
# define CHECK_MAPS_H
# include "map.h"

int			check_elem_map(t_string element_map);
t_string	get_params_map(t_string str, t_board *board);
int			check_maps(t_string str, t_board *board);
#endif
