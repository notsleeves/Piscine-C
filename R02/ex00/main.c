/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msteak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:03:21 by msteak            #+#    #+#             */
/*   Updated: 2021/03/06 13:03:26 by msteak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

#include <stdio.h>

char	*g_dict[201];

void	ft_print_err(int type)
{
	if (type == 1)
		write(2, "Error", 5);
	else if (type == 2)
		write(2, "Dict Error", 10);
	write(2, "\n", 1);
	exit(1);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\v'
		|| c == '\t' || c == '\f')
		return (1);
	return (0);
}

int		ft_isalpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_str_trim_zero(char *str)
{
	int i;
	int pos;
	int length;

	length = ft_strlen(str);
	if (str[0] == '0' && length > 1)
	{
		i = 0;
		while(i < length - 1)
		{
			str[i] = str [i + 1];
			i++;
		}
		str[i] = '\0';
		ft_str_trim_zero(str);
	}
}

char	*ft_get_number(char *str)
{
	int		i;
	int		size;
	int		flag;
	int		length;
	char	*result;

	i = 0;
	size = 0;
	flag = 1;
	length = ft_strlen(str);
	result = (char*)malloc(sizeof(char) * length + 1);
	if (result != NULL)
	{
		while (str[i])
		{
			if (ft_isalpha(str[i]))
			{
				flag = 0;
				result[size] = str[i];
				size++;
			}
			else if (!(ft_isspace(str[i]) && flag))
				break;
			i++;
		}
		result[size + 1] = '\0';
	}
	if (size == 0)
	{
		free(result);
		ft_print_err(2);
	}
	ft_str_trim_zero(result);
	return (result);
}

char	*ft_get_digits(char *str)
{
	int i;

	i = 0;

	return (str);
}

int ft_isrank(char *str, int size)
{
	int i;

	if (size > 2)
	{
		i = 1;
		if (str[0] == '1')
		{
			while (i < size)
				if (str[i++] != '0')
					return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	ft_issign(char ch)
{
	if (ch == '+' || ch == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while (*(str + i))
	{
		if (!(ft_isspace(*(str + i)) || ft_issign(*(str + i))))
		{
			if (*(str + i) >= 48 && *(str + i) <= 57)
				result = result * 10 + *(str + i) - '0';
			else
				return (result);
		}
		i++;
	}
	return (result);
}

void	ft_add_dict(char *key, char *value)
{
	int size;

	// printf("Key = %s\n", key);
	// printf("Value = \"%s\"\n", value);
	size = ft_strlen(key);
	if (size <= 2)
		g_dict[ft_atoi(key)] = value;
	else if (ft_isrank(key, size))
		g_dict[100 + size] = value;

}
void	fr_parse_line(char *str, int length)
{
	int i;
	int pos;
	int flag;
	char *key;
	char *value;
	
	i = 0;
	pos = 0;
	flag = 1;
	key = ft_get_number(str);
	while (i < length)
	{
		if (str[i] == ':')
			break;
		i++;
	}
	pos = i;
	if (pos)
	{
		value = malloc(sizeof(char) * (length - pos));
		if (value != NULL)
		{
		// printf("Length value = %d\n", (length - pos));
			pos++;
			i = 0;
			while (pos < length)
			{
				value[i++] = str[pos++];
			}
			value[i] = '\0';
		}
		
	}
	else
		ft_print_err(2);
	ft_add_dict(key, value);
	// printf("Key = %s\n", key);
	// printf("Length = %d\n", length);
	// printf("Line: %s\n", str);
	// printf("Value = \"%s\"\n", value);
}

void	ft_parse_dict(char *filename)
{
 	int		i;
	int		fd;
	int		bytes;
	char	byte;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * LINE_MAX);
	fd = open(filename, O_RDONLY);
	while((bytes = read(fd, &byte, 1)))
	{
		if (byte == '\n')
		{
			str[i] = '\0';
			fr_parse_line(str, i);
			i = 0;
			//printf("%s\n", str);
		}
		else
		{
			str[i] = byte;
			i++;
		}
	}
	free(str);
}

void	ft_print_number_words(char *filename,char *str)
{
	int i;
	int length;
	int pos;
	char *number;
	int digit;
	int k;

	digit = 0;
	number = ft_get_number(str);
	length = ft_strlen(number);
	ft_parse_dict(filename);
	while (i < length)
	{	
		pos = (length - i) % 3;
		digit += number[i] - '0';
		if (pos == 0 && digit > 0)
		{
			printf("%s ", g_dict[digit]);
			digit = 0;
		}
		if (pos == 2 && digit > 1)
		{
			printf("%s ", g_dict[digit]);
			digit = 0;
		}
		if (pos == 1 && digit > 0)
		{

			printf("%s ", g_dict[digit]);
			digit = 0;
		}
		i++;
	}
	// i = 0;
	// while (i < 201)
	// {
	// 	printf("g_ditc[%d] = %s\n", i, g_dict[i]);
	// 	i++;
	// }
	//printf("\"%s\"\n", nmbr);
}

int		main(int argc, char ** argv)
{
	if (argc > 3)
		return (1);
	else if (argc == 2)
		ft_print_number_words("numbers.dict", argv[1]);
}

