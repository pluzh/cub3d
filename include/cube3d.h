/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:12:47 by trbeardl          #+#    #+#             */
/*   Updated: 2022/05/26 16:28:12 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define PERMITED_SRTING "10NESW "
# define PLAYER_CHARS "NESW"
# define SIZE_ERROR_1 6
# define SIZE_ERROR_2 5
# define SIZE_ERROR_3 7
# define WIDTH 1080
# define HEIGHT 720
# define WALL_NORTH 0
# define WALL_SOUTH 1
# define WALL_WEST 2
# define WALL_EAST 3
# define MY_INT_MAX 2147483647
# define ROT_SPEED 0.1

typedef struct s_rgb
{
	int	rgb;
	int	r;
	int	g;
	int	b;
	int	init_flag;
}	t_rgb;

typedef struct s_data
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	int		win_height;
	int		win_width;
	char	*north;
	char	*east;
	char	*west;
	char	*south;
	int		init_flag_textures;
	t_rgb	F;
	t_rgb	C;
	char	**map;
	char	**map_grid;
	int		count_max_map_len;
	int		count_max_map_str;
	char	**all_date;
	int		all_map_size;
	double	player_y;
	double	player_x;
	double	dir_y;
	double	dir_x;
	double	plane_y;
	double	plane_x;
	int		player_count;
	t_data	*img;
	void	*mlx;
	void	*win;
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
	int		*data;
	int		*data_no;
	int		*data_so;
	int		*data_we;
	int		*data_ea;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		draw_start;
	int		draw_end;
	int		wall_side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		tex_w;
	int		tex_h;
	double	dist;
}	t_vars;

int		set_map_string(t_vars *vars);
int		ft_str_is_map(char	*str);
int		error_msg_main(int class, int error);
int		ft_parsing_main(char	*map_file_name, t_vars	*vars);
int		record_map(int fd, t_vars	*vars);
int		read_receord_map(char	*map_file_name, t_vars *vars);
int		ft_parsing_1(char	*map_file_name, t_vars	*vars);
int		ft_str_is_empty(char	*str);
char	*skipping_spaces(char	**str);
int		count_line_in_file(int fd);
int		ft_rgb_assign(char	*date, t_rgb	*color);
int		ft_check_rgb_format(char *line);
int		ft_b_format(char	*line);
int		ft_rb_format(char	*line);
void	ft_rgb_val(char	*date, t_rgb	*color);
void	ft_print_map(char	**map, int map_size);
void	ft_print_var(t_vars	*vars);
int		ft_max_int(int a, int b);
int		ft_isbase(char c, char	*base);
int		ft_assgn_vars(char	*str, t_vars	*vars);
int		ft_try_getstring_vars(t_vars	*vars);
int		ft_assgn_text(char	*str, char	**vars);
void	ft_first_init(t_vars	*vars);
void	free_mass_str(t_vars	*vars);
void	ft_free_vars(t_vars	*vars);
void	ft_count_max_map_stlen_and_size(t_vars	*vars);
int		ft_record_map_grid(t_vars	*vars);
void	ft_copy_map_to_mapgrid(t_vars	*vars);
int		ft_malloc_map_grid(t_vars	*vars);
int		ft_parsing_map(t_vars	*vars);
int		check_horizontal_empty_line(t_vars	*vars);
int		check_vertical_empty_line(t_vars	*vars);
int		check_forbidden_sign(t_vars	*vars);
int		check_player_count(t_vars	*vars);
int		ft_check_wall_closed_horizontal(t_vars	*vars);
int		ft_check_wall_closed_vertical(t_vars	*vars);
int		validate_map(t_vars	*o);
/* exe.c */
void	exe_game(t_vars *vars);
int		close_game(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	init_xpm(int direction, t_vars *vars);
void	init_img(char *path, void **img, int **data, t_vars *vars);
/* exe_utils_one.c */
void	my_mlx_pixel_put(t_data *img_data, int x, int y, int color);
char	*ft_itoa_base(long nbr, int base);
/* init_color.c */
void	init_color(t_rgb *rgb);
int		ft_atoh(char *str);
/* move.c */
void	move_down(t_vars *vars);
void	move_up(t_vars *vars);
void	turn_right(t_vars *vars);
void	turn_left(t_vars *vars);
/* fill_window.c */
void	fill_window(t_vars *vars);
void	init_deltas(int x, t_vars *vars);
void	init_sides(t_vars *vars);
int		throw_ray(t_vars *vars);
void	fill_vertical(int x, int side, t_vars *vars);
/* fill_window_two.c */
void	init_texture(int side, t_vars *vars);
void	fill_ceil(int x, int draw_start, t_vars *vars);
void	fill_texture(int x, int side, int line_height, t_vars *vars);
void	init_wall_x(int side, t_vars *vars);
void	fill_floor(int x, int draw_end, t_vars *vars);
#endif
