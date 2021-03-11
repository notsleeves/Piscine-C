/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:52:52 by msteak            #+#    #+#             */
/*   Updated: 2021/03/09 12:52:58 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		g_n;
int		g_m;
char	g_full;
char	g_obstacle;
char	g_empty;
char	**g_map;
int		g_limits_sub_map[5];

void	ft_map_error(void)
{
	if (g_n > 0 && g_m > 0)
		ft_clear_map();
	write(2, "map error\n", 10);
}

void	ft_newline(void)
{
	write(1, "\n", 1);
}

void	ft_read_srdin(void)
{
	if (!ft_read_map(STDIN_FILENO))
	{
		ft_find_map();
		ft_print_map();
		ft_clear_map();
	}
	else
		ft_map_error();
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		ft_read_srdin();
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_read_map(ft_open_map(argv[i])))
		{
			ft_find_map();
			ft_print_map();
			ft_clear_map();
		}
		else
			ft_map_error();
		if (argc > 2)
			ft_newline();
		i++;
	}
}
