/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ElTeam <elTeam@bsq.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:19:54 by ElTeam            #+#    #+#             */
/*   Updated: 2022/07/27 03:03:16 by ElTeam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/errors.h"

int	ft_puterr_z(t_string str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (0);
}

int	ft_puterr_o(t_string str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (0);
}
