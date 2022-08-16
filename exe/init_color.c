/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_atoh(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + str[i] - '0';
		else
			res = res * 16 + str[i] - 'A' + 10;
		i++;
	}
	return (res);
}

void	init_color(t_rgb *rgb)
{
	char	*str;
	char	*res;
	char	*tmp;

	str = ft_itoa_base(rgb->r, 16);
	res = ft_strjoin("", str);
	free(str);
	str = ft_itoa_base(rgb->g, 16);
	tmp = res;
	res = ft_strjoin(res, str);
	free(tmp);
	free(str);
	str = ft_itoa_base(rgb->b, 16);
	tmp = res;
	res = ft_strjoin(res, str);
	free(tmp);
	free(str);
	rgb->rgb = ft_atoh(res);
	free(res);
}
