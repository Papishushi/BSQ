/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:48:30 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 02:19:22 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"
#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(t_string str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int	ft_strlen(t_string str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(t_string str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] >= '0' && str[i] <= '9') && \
		(i < (ft_strlen(str) - 2)))
		j = (j * 10) + (str[i++] - '0');
	return (j);
}
