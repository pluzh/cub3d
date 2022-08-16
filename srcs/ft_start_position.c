/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 07:13:30 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 12:09:30 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	free_and_return(t_vars *o)
{
	ft_free_vars(o);
	return (1);
}

void	init_camera_plane(t_vars *o)
{
	if (o->dir_x == 0 && o->dir_y == -1)
	{
		o->plane_x = 0.66;
		o->plane_y = 0;
	}
	else if (o->dir_x == 0 && o->dir_y == 1)
	{
		o->plane_x = -0.66;
		o->plane_y = 0;
	}
	else if (o->dir_y == 0 && o->dir_x == -1)
	{
		o->plane_x = 0;
		o->plane_y = -0.66;
	}
	else if (o->dir_y == 0 && o->dir_x == 1)
	{
		o->plane_x = 0;
		o->plane_y = 0.66;
	}
}

void	init_direction(int y, int x, t_vars *vars)
{
	if (vars->map_grid[y][x] == 'N')
	{
		vars->dir_y = -1;
		vars->dir_x = 0;
	}
	else if (vars->map_grid[y][x] == 'S')
	{
		vars->dir_y = 1;
		vars->dir_x = 0;
	}
	else if (vars->map_grid[y][x] == 'E')
	{
		vars->dir_y = 0;
		vars->dir_x = 1;
	}
	else if (vars->map_grid[y][x] == 'W')
	{
		vars->dir_y = 0;
		vars->dir_x = -1;
	}
}

int	check_symbol(int y, int x, t_vars *vars)
{
	if (vars->map_grid[y][x] == '0' || vars->map_grid[y][x] == '1'
		|| vars->map_grid[y][x] == ' ')
		return (0);
	else if (vars->map_grid[y][x] == 'N' || vars->map_grid[y][x] == 'S'
		|| vars->map_grid[y][x] == 'E' || vars->map_grid[y][x] == 'W')
	{
		vars->player_y = y + 0.5;
		vars->player_x = x + 0.5;
		init_direction(y, x, vars);
		init_camera_plane(vars);
		vars->player_count++;
		if (vars->player_count > 1)
			return (1);
		return (0);
	}
	else
		return (1);
}

int	validate_map(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map_grid[y])
	{
		x = 0;
		while (vars->map_grid[y][x])
		{
			if (check_symbol(y, x, vars))
			{
				printf("Error: not allowed symbol or too mush players!\n");
				return (free_and_return(vars));
			}
			x++;
		}
		y++;
	}
	return (0);
}
