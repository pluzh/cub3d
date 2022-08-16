/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_check_mapgrid_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:15:29 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/12 13:01:35 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* проверка количества игроков на карте */
int	check_player_count(t_vars *vars)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	j = 0;
	count_player = 0;
	while (vars->map_grid[i])
	{
		j = 0;
		while (j < vars->count_max_map_len)
		{
			if (ft_isbase(vars->map_grid[i][j], PLAYER_CHARS))
				count_player++;
			j++;
		}
		i++;
	}
	if (count_player == 0)
		return (error_msg_main(3, 5));
	if (count_player > 1)
		return (error_msg_main(3, 1));
	return (0);
}

/* проверка вертикальной пустой линии на карте */
int	check_vertical_empty_line(t_vars *vars)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = 0;
	flag = 0;
	while (i++ < vars->count_max_map_len)
	{
		j = 0;
		while (j < vars->count_max_map_str)
		{
			if (vars->map_grid[j][i] == ' ')
				flag = 1;
			else
			{
				flag = 0;
				break ;
			}
			j++;
		}
		if (flag && i)
			return (error_msg_main(3, 3));
	}
	return (0);
}

/* проверка закрытых границ по горизонтали */
int	ft_check_wall_closed_horizontal(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (vars->map_grid[i] != NULL)
	{
		k = vars->count_max_map_len - 1;
		j = 0;
		while (vars->map_grid[i][j] != '\0' && vars->map_grid[i][j] == ' ')
			j++;
		if (vars->map_grid[i][j] == '\0' || vars->map_grid[i][j] != '1')
			return (error_msg_main(3, 4));
		while (k >= 0 && vars->map_grid[i][k] == ' ')
			k--;
		if (k < 0 || vars->map_grid[i][k] != '1')
			return (error_msg_main(3, 4));
		i++;
	}
	return (0);
}

/* проверка закрытых границ по вертикали */
int	ft_check_wall_closed_vertical(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (vars->map_grid[0][i] != '\0')
	{
		k = vars->count_max_map_str - 1;
		j = 0;
		while (vars->map_grid[j] != NULL && vars->map_grid[j][i] == ' ')
			j++;
		if (vars->map_grid[j] == NULL || vars->map_grid[j][i] != '1')
			return (error_msg_main(3, 4));
		while (k >= 0 && vars->map_grid[k][i] == ' ')
			k--;
		if (k < 0 || vars->map_grid[k][i] != '1')
			return (error_msg_main(3, 4));
		i++;
	}
	return (0);
}
