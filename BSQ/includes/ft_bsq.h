/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:02:57 by msteak            #+#    #+#             */
/*   Updated: 2021/03/09 19:03:12 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_atoi(char *str);
int		ft_open_map(char *filename);
int		ft_read_map(int fd);
void	ft_print_map();
void	ft_find_map();
void	ft_clear_map();
void	ft_vector_d(int **d, int i);
void	ft_vector_d1(int **d, int **d1);
void	ft_vector_d2(int **d, int **d2);
void	ft_set_param_map(char *line, int size);
void	ft_update_map(int m, int row, char *line);
void	ft_set_map(int n, int m, int row, char *line);
#endif
