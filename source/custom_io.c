/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:56:29 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 17:42:25 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/custom_io.h"
#include "../headers/check_maps.h"

t_string	read_std_input( void )
{
	int				fd;
	char			buffer[1];
	t_string		result;
	unsigned int	lenght;
	unsigned int	index;

	lenght = 0;
	fd = open(0, O_RDONLY);
	while (read(fd, buffer, 1) > 0)
			lenght++;
	result = (char *)malloc(sizeof(char) * (lenght +1));
	index = 0;
	while (read(0, buffer, 1) > 0)
	{
			result[index] = buffer[0];
			index++;
	}
	result[index] = '\0';
	close(fd);
	return (result);
}

int	open_file(t_string str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	return (fd);
}

static int	get_check(t_string str, int *fd1)
{
	char	buffer[1];
	int		check;

	check = 0;
	*fd1 = open_file(str);
	while (read(*fd1, &buffer, 1) > 0)
		if (*buffer == '\n')
			break ;
	while (read(*fd1, &buffer, 1) > 0)
	{
		check++;
		if (*buffer == '\n')
		{
			if (check == 1)
				return (0);
			break ;
		}
	}
	return (check);
}

static int	sus(int *fd1, int *check, int *lines)
{
	char	buffer[1];
	int		counter;

	counter = 0;
	while (read(*fd1, &buffer, 1) > 0)
	{
		counter++;
		if (*buffer == '\n')
		{
			if (counter == *check)
			{
				*check = counter;
				counter = 0;
			}
			else
				return (0);
		(*lines)++;
		}
	}
	return (1);
}

int	read_file(t_string str, t_board *board)
{
	int		fd1;
	int		lines;
	int		check;
	int		is_not_err;

	lines = 1;
	check = get_check(str, &fd1);
	if (!check)
		return (0);
	is_not_err = sus(&fd1, &check, &lines);
	if (ft_atoi(get_params_map(str, board)) != lines)
		return (0);
	close(fd1);
	return (check - 1);
}
