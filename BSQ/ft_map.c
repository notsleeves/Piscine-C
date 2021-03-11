/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:07:42 by msteak            #+#    #+#             */
/*   Updated: 2021/03/10 20:07:44 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

extern char	g_full;
extern char	g_obstacle;
extern char	g_empty;
extern int	g_n;
extern int	g_m;
extern char	**g_map;
extern int	g_error;

void	ft_set_param_map(char *line, int size)
{
	if (size >= 4)
	{
		g_full = line[size - 1];
		g_obstacle = line[size - 2];
		g_empty = line[size - 3];
		line[size - 3] = '\0';
		g_n = ft_atoi(line);
		if (g_n <= 0 && g_full > 31 && g_full < 127 &&
		g_obstacle > 31 && g_obstacle < 127 &&
		g_empty > 31 && g_empty < 127)
			g_error = -1;
	}
	else
		g_error = -1;
}

void	ft_update_map(int m, int row, char *line)
{
	int i;

	i = 0;
	if (m != g_m || row >= g_n)
		g_error = -1;
	else
	{
		while (i < g_m)
		{
			if (line[i] == g_empty || line[i] == g_obstacle)
				g_map[row][i] = line[i];
			else
			{
				g_error = -1;
				break ;
			}
			i++;
		}
	}
}

void	ft_set_map(int n, int m, int row, char *line)
{
	int i;

	i = 0;
	if (!g_error)
	{
		if (!row)
		{
			if (m > 0)
			{
				g_m = m;
				g_map = (char**)malloc(n * sizeof(char*)
				+ n * m * sizeof(char));
				g_map[0] = (char*)(g_map + n);
				while (i < n)
				{
					g_map[i] = g_map[0] + i * m;
					i++;
				}
			}
		}
		ft_update_map(m, row, line);
	}
}
