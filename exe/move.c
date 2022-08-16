/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	turn_left(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(-ROT_SPEED) - vars->dir_y * sin(-ROT_SPEED);
	vars->dir_y = old_dir_x * sin(-ROT_SPEED) + vars->dir_y * cos(-ROT_SPEED);
	old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(-ROT_SPEED)
		- vars->plane_y * sin(-ROT_SPEED);
	vars->plane_y = old_plane_x * sin(-ROT_SPEED)
		+ vars->plane_y * cos(-ROT_SPEED);
	fill_window(vars);
}

void	turn_right(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(ROT_SPEED) - vars->dir_y * sin(ROT_SPEED);
	vars->dir_y = old_dir_x * sin(ROT_SPEED) + vars->dir_y * cos(ROT_SPEED);
	old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(ROT_SPEED)
		- vars->plane_y * sin(ROT_SPEED);
	vars->plane_y = old_plane_x * sin(ROT_SPEED)
		+ vars->plane_y * cos(ROT_SPEED);
	fill_window(vars);
}

void	move_up(t_vars *vars)
{
	if (vars->dist > 0.66)
	{
		vars->player_y += vars->dir_y / 4;
		vars->player_x += vars->dir_x / 4;
		fill_window(vars);
	}
}

void	move_down(t_vars *vars)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = vars->player_x - 0.66 * vars->dir_x;
	new_pos_y = vars->player_y - 0.66 * vars->dir_y;
	if (vars->map_grid[new_pos_y][new_pos_x] != '1')
	{
		vars->player_y -= vars->dir_y / 4;
		vars->player_x -= vars->dir_x / 4;
		fill_window(vars);
	}
}
