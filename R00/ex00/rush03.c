/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:54:58 by msteak            #+#    #+#             */
/*   Updated: 2021/02/21 09:54:59 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	ft_symbol(int col, int row, int x, int y)
{
	if (col == 1 && (row == 1 || row == y))
		return ('A');
	else if (col == x && (row == 1 || row == y))
		return ('C');
	else if ((col > 1 && (row == 1 || row == y))
			|| (row > 1 && (col == 1 || col == x)))
		return ('B');
	return (' ');
}

void	rush(int x, int y)
{
	int		col;
	int		row;

	row = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			ft_putchar(ft_symbol(col, row, x, y));
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}
