/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:57:02 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 17:12:55 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE1_H
# define SOLVE1_H
# include "tools.h"
# include "map.h"

int		min_value(t_point point, t_board *board);
void	joga_bonito(t_board *board);
t_point	final_fucking_result(t_board *board);
void	final_change(t_board *board);
void	put_obstacles(t_board *board);
#endif
