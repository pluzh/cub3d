/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:17:46 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 08:09:58 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* инициализация F и C */
void	ft_rgb_val(char	*date, t_rgb	*color)
{
	int	count;

	count = 0;
	while (count < 3)
	{
		while (*date == ' ' || *date == ',')
			date++;
		if (count == 0)
			color->r = ft_atoi(date);
		else if (count == 1)
			color->g = ft_atoi(date);
		else if (count == 2)
			color->b = ft_atoi(date);
		while (ft_isdigit(*date))
			date++;
		count++;
	}
}

/* проверка корректности данных строки */
int	ft_rb_format(char	*line)
{
	int	count;
	int	number;

	count = 0;
	number = 0;
	while (*line != '\0' && count < 2)
	{
		if (ft_isdigit(*line))
		{
			if (number >= 2 || ft_atoi(line) < 0 || ft_atoi(line) > 255)
				return (1);
			while (ft_isdigit(*line))
				line++;
			number++;
		}
		if (*line == ',')
			count++;
		if (*line != ',' && ft_isdigit(*line) != 1 && *line != ' ')
			return (1);
		line++;
	}
	if (*line != '\0' && count == 2 && number == 2)
		return (0);
	return (1);
}

/* проверка корректности данных строки RGB */
int	ft_b_format(char *line)
{
	int	tmp;

	while (*line == ' ' && *line != '\0')
		line++;
	if (*line == '\0' || !ft_isdigit(*line))
		return (1);
	tmp = ft_atoi(line);
	if (tmp < 0 || tmp > 255)
		return (1);
	while (ft_isdigit(*line))
		line++;
	while (*line != '\0')
	{
		if (*line != ' ')
			return (1);
		line++;
	}
	return (0);
}

int	ft_check_rgb_format(char *line)
{
	int	count;

	count = 0;
	if (ft_rb_format(line))
		return (1);
	while (count < 2)
	{
		if (*line == ',')
			count++;
		line++;
	}
	if (ft_b_format(line))
		return (1);
	return (0);
}

/* проверка и инициализация переменных RGB*/
int	ft_rgb_assign(char	*date, t_rgb	*color)
{
	if (ft_check_rgb_format(date))
		return (error_msg_main(2, 2));
	ft_rgb_val(date, color);
	color->init_flag = 1;
	return (0);
}
