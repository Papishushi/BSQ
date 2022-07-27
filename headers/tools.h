/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:49:33 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 03:02:09 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//DEBUG ONLY
# include <stdio.h>

typedef char*	t_string;
typedef char**	t_matrix;

void	ft_putchar(char c);
void	ft_putstr(t_string str);
int		ft_puterr(t_string str);
int		ft_strlen(t_string str);
int		ft_atoi(t_string str);
#endif
