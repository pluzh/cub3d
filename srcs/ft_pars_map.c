/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:17:46 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 08:09:58 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* высота карты и самая длинная строка в карте */
void	ft_count_max_map_stlen_and_size(t_vars *vars)
{
	int	i;
	int	last_ful_string;
	int	max;

	i = 0;
	max = 0;
	last_ful_string = 0;
	while (vars->map[i])
	{
		if (!ft_str_is_empty(vars->map[i]))
			last_ful_string = i;
		i++;
	}
	vars->count_max_map_str = last_ful_string + 1;
	i = 0;
	while (vars->map[i])
	{
		max = ft_max_int(max, ft_strlen(vars->map[i]));
		i++;
	}
	vars->count_max_map_len = max;
}

/* создание сетки карты */
int	ft_malloc_map_grid(t_vars	*vars)
{
	vars->map_grid = ft_calloc(vars->count_max_map_str + 1, sizeof(char *));
	if (!vars->map_grid)
		return (error_msg_main(2, 0));
	return (0);
}

/* создание и инициализация сетки карты символом ' ' */
int	ft_record_map_grid(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->count_max_map_str)
	{
		vars->map_grid[i] = ft_calloc(vars->count_max_map_len + 1,
				sizeof(char));
		if (!vars->map_grid[i])
			return (1);
		j = 0;
		while (j < vars->count_max_map_len)
		{
			vars->map_grid[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (0);
}

/* копирование vars->map  в vars->map_grid */
void	ft_copy_map_to_mapgrid(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->count_max_map_str)
	{
		j = 0;
		while (vars->map[i][j])
		{
			vars->map_grid[i][j] = vars->map[i][j];
			j++;
		}
		i++;
	}
}

/* вызов функция парсинга карты*/
int	ft_parsing_map(t_vars *vars)
{
	ft_count_max_map_stlen_and_size(vars);
	if (ft_malloc_map_grid(vars) || ft_record_map_grid(vars))
		return (1);
	ft_copy_map_to_mapgrid(vars);
	if (check_horizontal_empty_line(vars)
		|| check_vertical_empty_line(vars)
		|| check_forbidden_sign(vars)
		|| check_player_count(vars)
		|| ft_check_wall_closed_horizontal(vars)
		|| ft_check_wall_closed_vertical(vars))
		return (1);
	if (validate_map(vars))
		return (1);
	return (0);
}
