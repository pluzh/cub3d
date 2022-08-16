/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:19:11 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:25:24 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* возвращает максимум из двух int */
int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/* возвращает 0 если сторока пустая (непечатаемые символы), иначе 1 */
int	ft_str_is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/* Возвращает 1 если символ "c" содежится в строке "base" */
int	ft_isbase(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

/* Смещает указатель до первого печатаемого символа */
char	*skipping_spaces(char **str)
{
	int	i;

	i = 0;
	while (*(*str + i) == ' ' || *(*str + i) == '	')
		i++;
	*str = *str + i;
	return (*str);
}

int	ft_str_is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isbase(str[i], "10 "))
			return (0);
		i++;
	}
	return (1);
}
