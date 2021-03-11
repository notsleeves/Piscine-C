/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:28:58 by ggoofbal          #+#    #+#             */
/*   Updated: 2021/03/09 11:32:54 by ggoofbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

extern char	g_full;
extern char	g_obstacle;
extern char	g_empty;
extern int	g_n;
extern int	g_m;
extern char	**g_map;
int			g_error;

int		ft_open_map(char *filename)
{
	int fd;

	g_error = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		g_error = -1;
	return (fd);
}

int		ft_read_bytes(int fd, char **buffer)
{
	int		i;
	int		bytes;
	int		nl;
	char	byte;

	nl = 0;
	i = 0;
	while ((bytes = read(fd, &byte, 1)) > 0)
	{
		(*buffer)[i] = byte;
		if (byte == '\n')
		{
			if (nl == 0)
				ft_set_param_map(*buffer, i);
			else
				ft_set_map(g_n, i, nl - 1, *buffer);
			nl++;
			i = -1;
		}
		i++;
	}
	if (g_n != nl - 1)
		g_error = -1;
	return (bytes);
}

void	ft_read_lines(int fd)
{
	char	*buffer;

	if ((buffer = malloc(sizeof(char) * 100000)) != NULL)
	{
		if (ft_read_bytes(fd, &buffer) == -1)
			g_error = -1;
		free(buffer);
	}
}

int		ft_read_map(int fd)
{
	if (!g_error)
	{
		ft_read_lines(fd);
		if (close(fd))
			return (-1);
	}
	return (g_error);
}
