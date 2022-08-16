/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_init_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:39:00 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 09:48:40 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	ft_first_init(t_vars *vars)
{
	vars->win_height = 600;
	vars->win_width = 900;
	vars->north = 0;
	vars->south = 0;
	vars->west = 0;
	vars->east = 0;
	vars->all_map_size = 0;
	vars->C.init_flag = 0;
	vars->F.init_flag = 0;
	vars->count_max_map_len = 0;
	vars->count_max_map_str = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->player_count = 0;
	vars->dir_x = 0;
	vars->dir_y = 0;
	vars->plane_x = 0;
	vars->plane_y = 0;
	vars->map_grid = NULL;
	vars->all_date = NULL;
	vars->map = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
}

void	free_mass_str(t_vars	*vars)
{
	int	i;

	i = 0;
	if (vars->all_date)
	{
		while (vars->all_date[i])
		{
			if (vars->all_date[i])
				free(vars->all_date[i]);
			i++;
		}
		free(vars->all_date);
	}
	i = 0;
	if (vars->map_grid)
	{
		while (vars->map_grid[i])
		{
			if (vars->map_grid[i])
				free(vars->map_grid[i]);
			i++;
		}
		free(vars->map_grid);
	}	
}

void	ft_free_vars(t_vars *vars)
{
	if (vars->north)
		free(vars->north);
	if (vars->south)
		free(vars->south);
	if (vars->west)
		free(vars->west);
	if (vars->east)
		free(vars->east);
	free_mass_str(vars);
}
