/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	fill_vertical(int x, int side, t_vars *vars)
{
	int	line_height;

	if (x == WIDTH / 2)
		vars->dist = vars->perp_wall_dist;
	line_height = HEIGHT / vars->perp_wall_dist;
	vars->draw_start = -line_height / 2 + HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = line_height / 2 + HEIGHT / 2;
	if (vars->draw_end >= HEIGHT)
		vars->draw_end = HEIGHT - 1;
	init_texture(side, vars);
	fill_ceil(x, vars->draw_start, vars);
	fill_floor(x, vars->draw_end, vars);
	fill_texture(x, side, line_height, vars);
}

int	throw_ray(t_vars *vars)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			side = 0;
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			side = 1;
		}
		if (vars->map_grid[vars->map_y][vars->map_x] == '1')
			hit = 1;
	}
	return (side);
}

void	init_sides(t_vars *vars)
{
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (vars->player_x - vars->map_x) * vars->delta_dist_x;
	}
	else
	{
		vars->step_x = 1;
		vars->side_dist_x = (vars->map_x + 1.0 - vars->player_x)
			* vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (vars->player_y - vars->map_y) * vars->delta_dist_y;
	}
	else
	{
		vars->step_y = 1;
		vars->side_dist_y = (vars->map_y + 1.0 - vars->player_y)
			* vars->delta_dist_y;
	}
}

void	init_deltas(int x, t_vars *vars)
{
	vars->camera_x = 2 * x / (double) WIDTH - 1;
	vars->ray_dir_x = vars->dir_x + vars->plane_x * vars->camera_x;
	vars->ray_dir_y = vars->dir_y + vars->plane_y * vars->camera_x;
	vars->map_x = (int )vars->player_x;
	vars->map_y = (int )vars->player_y;
	if (vars->ray_dir_x == 0)
		vars->delta_dist_x = MY_INT_MAX;
	else
		vars->delta_dist_x = fabs(1 / vars->ray_dir_x);
	if (vars->ray_dir_y == 0)
		vars->delta_dist_y = MY_INT_MAX;
	else
		vars->delta_dist_y = fabs(1 / vars->ray_dir_y);
}

void	fill_window(t_vars *vars)
{
	int		x;
	int		side;
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.data = mlx_get_data_addr(
			img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars->img = &img;
	x = 0;
	while (x < WIDTH)
	{
		init_deltas(x, vars);
		init_sides(vars);
		side = throw_ray(vars);
		if (side == 0)
			vars->perp_wall_dist = vars->side_dist_x - vars->delta_dist_x;
		else
			vars->perp_wall_dist = vars->side_dist_y - vars->delta_dist_y;
		fill_vertical(x, side, vars);
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img->img);
}
