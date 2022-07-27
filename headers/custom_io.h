/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_io.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:58:20 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 03:43:44 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_IO_H
# define CUSTOM_IO_H
# include "tools.h"
# include "map.h"

char	*read_std_input( void );
int		open_file(t_string str);
int		read_file(t_string str, t_board *board);
#endif
