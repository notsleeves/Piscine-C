/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sub_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:57:25 by msteak            #+#    #+#             */
/*   Updated: 2021/03/09 16:57:28 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

extern int	g_n;
extern int	g_m;
extern char	g_full;
extern char	g_obstacle;
extern char	g_empty;
extern char	**g_map;
extern int	g_limits_sub_map[5];

void	ft_clear_map(void)
{
	int i;

	i = 0;
	g_n = 0;
	g_m = 0;
	g_full = 0;
	g_obstacle = 0;
	g_empty = 0;
	free(g_map);
	while (i < 5)
	{
		g_limits_sub_map[i] = 0;
		i++;
	}
}

void	ft_print_map(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_n)
	{
		j = 0;
		while (j < g_m)
		{
			if (i >= g_limits_sub_map[1] && i <= g_limits_sub_map[2] &&
				j >= g_limits_sub_map[3] && j <= g_limits_sub_map[4] &&
				g_limits_sub_map[0] > 0)
				write(1, &g_full, 1);
			else
				write(1, &g_map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_limits_sub_map(int top, int bottom, int left, int rigth)
{
	int max;

	if ((bottom - top) > (rigth - left))
		bottom = top + (rigth - left);
	else if ((bottom - top) < (rigth - left))
		rigth = left + (bottom - top);
	max = (bottom - top + 1) * (rigth - left + 1);
	if (max > g_limits_sub_map[0])
	{
		g_limits_sub_map[0] = max;
		g_limits_sub_map[1] = top;
		g_limits_sub_map[2] = bottom;
		g_limits_sub_map[3] = left;
		g_limits_sub_map[4] = rigth;
	}
}

void	ft_find_map(void)
{
	int	i;
	int	j;
	int	*d;
	int	*d1;
	int	*d2;

	d = malloc(sizeof(int) * g_m);
	d1 = malloc(sizeof(int) * g_m);
	d2 = malloc(sizeof(int) * g_m);
	i = 0;
	ft_vector_d(&d, -1);
	while (i < g_n)
	{
		ft_vector_d(&d, i);
		ft_vector_d1(&d, &d1);
		ft_vector_d2(&d, &d2);
		j = 0;
		while (j < g_m)
		{
			ft_limits_sub_map(d[j] + 1, i, d1[j] + 1, d2[j] - 1);
			j++;
		}
		i++;
	}
}
