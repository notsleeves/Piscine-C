/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:01:20 by msteak            #+#    #+#             */
/*   Updated: 2021/03/09 12:01:22 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		g_n;
int		g_m;
char	g_full;
char	g_obstacle;
char	g_empty;
char	**g_map;

void	ft_vector_d(int **d, int i)
{
	int j;

	j = 0;
	if (i == -1)
	{
		while (i < g_m)
		{
			(*d)[i] = -1;
			i++;
		}
	}
	else
	{
		while (j < g_m)
		{
			if (g_map[i][j] == g_obstacle)
				(*d)[j] = i;
			j++;
		}
	}
}

void	ft_vector_d1(int **d, int **d1)
{
	int j;
	int top;
	int	*st;

	j = 0;
	top = -1;
	st = malloc(sizeof(int) * g_m);
	while (j < g_m)
	{
		while (top != -1 && (*d)[st[top]] <= (*d)[j])
			top--;
		(*d1)[j] = top == -1 ? -1 : st[top];
		st[++top] = j;
		j++;
	}
	free(st);
}

void	ft_vector_d2(int **d, int **d2)
{
	int j;
	int top;
	int	*st;

	top = -1;
	j = g_m - 1;
	st = malloc(sizeof(int) * g_m);
	while (j >= 0)
	{
		while (top != -1 && (*d)[st[top]] <= (*d)[j])
			top--;
		(*d2)[j] = top == -1 ? g_m : st[top];
		st[++top] = j;
		j--;
	}
	free(st);
}
