/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	fill_floor(int x, int draw_end, t_vars *vars)
{
	int	i;

	i = draw_end;
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(vars->img, x, i, vars->F.rgb);
		i++;
	}
}

void	init_wall_x(int side, t_vars *vars)
{
	if (side)
		vars->wall_x = vars->player_x
			+ vars->perp_wall_dist * vars->ray_dir_x - vars->map_x;
	else
		vars->wall_x = vars->player_y
			+ vars->perp_wall_dist * vars->ray_dir_y - vars->map_y;
}

void	fill_texture(int x, int side, int line_height, t_vars *vars)
{
	int		y;
	int		color;
	double	step;
	double	tex_pos;

	init_wall_x(side, vars);
	vars->tex_x = vars->wall_x * vars->tex_w;
	step = 1.0 * vars->tex_h / line_height;
	tex_pos = (vars->draw_start - HEIGHT / 2 + line_height / 2) * step;
	y = vars->draw_start;
	while (y < vars->draw_end)
	{
		vars->tex_y = (int)tex_pos &(vars->tex_h - 1);
		tex_pos += step;
		if (vars->wall_side == WALL_NORTH)
			color = vars->data_no[vars->tex_h * vars->tex_y + vars->tex_x];
		else if (vars->wall_side == WALL_SOUTH)
			color = vars->data_so[vars->tex_h * vars->tex_y + vars->tex_x];
		else if (vars->wall_side == WALL_WEST)
			color = vars->data_we[vars->tex_h * vars->tex_y + vars->tex_x];
		else if (vars->wall_side == WALL_EAST)
			color = vars->data_ea[vars->tex_h * vars->tex_y + vars->tex_x];
		my_mlx_pixel_put(vars->img, x, y, color);
		y++;
	}
}

void	fill_ceil(int x, int draw_start, t_vars *vars)
{
	int		i;

	i = 0;
	while (i < draw_start)
	{
		my_mlx_pixel_put(vars->img, x, i, vars->C.rgb);
		i++;
	}
}

void	init_texture(int side, t_vars *vars)
{
	if (side)
	{
		if (vars->ray_dir_y < 0)
			vars->wall_side = WALL_SOUTH;
		else
			vars->wall_side = WALL_NORTH;
	}
	else
	{
		if (vars->ray_dir_x < 0)
			vars->wall_side = WALL_EAST;
		else
			vars->wall_side = WALL_WEST;
	}
}
