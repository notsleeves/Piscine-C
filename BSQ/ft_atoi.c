/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:32:33 by msteak            #+#    #+#             */
/*   Updated: 2021/03/09 19:32:35 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			result = result * 10 + *(str + i) - '0';
		else
			return (0);
		i++;
	}
	return (result);
}
