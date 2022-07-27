/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:56:29 by dmoliner          #+#    #+#             */
/*   Updated: 2022/07/27 15:53:32 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/custom_io.h"
#include "../headers/check_maps.h"

t_string read_std_input( void )
{
	int				fd;
	char			buffer[1];
	t_string		result;
	unsigned int	lenght;
	unsigned int	index;

	lenght = 0;
	fd = open(0, O_RDONLY); //ESTO TIRA UN ERROR POR EL WALL NO QUIERE QUE LE PASEMOS UN 0
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

int	read_file(t_string str, t_board *board) //ESTO HAY QUE REDUCIRLO DE TAMAÑO
{
	int		fd1;
	char	buffer[1];
	int		counter;
	int		lines;
	int		check;

	counter = 0;
	lines = 1;
	check = 0;
	fd1 = open_file(str);
	while (read(fd1, &buffer, 1) > 0)
		if (*buffer == '\n')
			break ;
	while (read(fd1, &buffer, 1) > 0)
	{
		check++;
		if (*buffer == '\n')
		{
			if (check == 1)
				{printf("aquii\n");
				return (0);}
			break ;
		}
	}
	while (read(fd1, &buffer, 1) > 0)
	{
		counter++;
		if (*buffer == '\n')
		{
			if (counter == check)
			{
				check = counter;
				counter = 0;
			}
			else
			{printf("aquii\n");
				return (0);}
		lines++;
		}
	}
	if (ft_atoi(get_params_map(str, board)) != lines)
	{printf("aquii\n");
		return (0);
	}
	close(fd1);
	return (check - 1);
}
