/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:49:33 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 16:05:56 by vquiroga         ###   ########.fr       */
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
typedef int **  t_mat_aux;
typedef struct s_point
{
    int x;
    int y;
    int value;
} t_point;

void	ft_putchar(char c);
void	ft_putstr(t_string str);
int		ft_puterr(t_string str);
int		ft_strlen(t_string str);
int		ft_atoi(t_string str);
#endif
