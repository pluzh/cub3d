/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_img(char *path, void **img, int **data, t_vars *vars)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	*img = mlx_xpm_file_to_image(vars->mlx, path, &vars->tex_w, &vars->tex_h);
	if (!*img)
	{
		printf("Error: wrong path!\n");
		ft_free_vars(vars);
		exit(EXIT_FAILURE);
	}
	*data = (int *)mlx_get_data_addr(
			*img, &bits_per_pixel, &size_line, &endian);
	if (!*data)
	{
		printf("Error: wrong path!\n");
		mlx_destroy_image(vars->mlx, *img);
		ft_free_vars(vars);
		exit(EXIT_FAILURE);
	}
}

void	init_xpm(int direction, t_vars *vars)
{
	if (direction == WALL_NORTH)
		init_img(vars->north, &vars->img_no, &vars->data_no, vars);
	else if (direction == WALL_SOUTH)
		init_img(vars->south, &vars->img_so, &vars->data_so, vars);
	else if (direction == WALL_WEST)
		init_img(vars->west, &vars->img_we, &vars->data_we, vars);
	else if (direction == WALL_EAST)
		init_img(vars->east, &vars->img_ea, &vars->data_ea, vars);
}

int	close_game(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_no);
	mlx_destroy_image(vars->mlx, vars->img_so);
	mlx_destroy_image(vars->mlx, vars->img_we);
	mlx_destroy_image(vars->mlx, vars->img_ea);
	ft_free_vars(vars);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126)
		move_up(vars);
	else if (keycode == 0 || keycode == 123)
		turn_left(vars);
	else if (keycode == 2 || keycode == 124)
		turn_right(vars);
	else if (keycode == 1 || keycode == 125)
		move_down(vars);
	else if (keycode == 53)
	{
		close_game(vars);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	exe_game(t_vars *vars)
{
	init_color(&vars->F);
	init_color(&vars->C);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_hook(vars->win, 17, 1L << 0, close_game, vars);
	mlx_hook(vars->win, 02, 1L << 0, key_hook, vars);
	init_xpm(WALL_NORTH, vars);
	init_xpm(WALL_SOUTH, vars);
	init_xpm(WALL_EAST, vars);
	init_xpm(WALL_WEST, vars);
	fill_window(vars);
	mlx_loop(vars->mlx);
}
