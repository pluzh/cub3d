/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_check_mapgrid_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:15:29 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/12 13:01:35 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* проверка горизоньальной пустой линии на карте */
int	check_horizontal_empty_line(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_grid[i])
	{
		if (ft_str_is_empty(vars->map_grid[i]))
			return (error_msg_main(3, 2));
		i++;
	}
	return (0);
}

/* проверка наличия не допустимых символов на карте NESW */
int	check_forbidden_sign(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_grid[i])
	{
		j = 0;
		while (j < vars->count_max_map_len)
		{
			if (!ft_isbase(vars->map_grid[i][j], PERMITED_SRTING))
				return (error_msg_main(3, 0));
			j++;
		}
		i++;
	}
	return (0);
}
