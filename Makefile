SRCS		= srcs/000_main.c\
		srcs/ft_error_msg.c\
		srcs/ft_pars_main.c\
		srcs/ft_pars_1.c\
		srcs/ft_assgn_vars.c\
		srcs/ft_tools_1.c\
		srcs/ft_tools_2.c\
		srcs/ft_pars_rgb.c\
		srcs/ft_pars_map.c\
		srcs/ft_first_init_free.c\
		srcs/ft_pars_check_mapgrid_1.c\
		srcs/ft_pars_check_mapgrid_2.c\
		srcs/ft_start_position.c\
		exe/exe.c\
		exe/exe_utils_one.c\
		exe/init_color.c\
		exe/fill_window.c\
		exe/fill_window_two.c\
		exe/move.c\

OBJ			= $(SRCS:.c=.o)
CUBE_H		= include/cube3d.h
LIB_FT		= ./libft/libft.a
LIB_MLX		= ./mlx/libmlx.a
DEPS		= $(CUBE_H) $(LIB_FT) $(LIB_MLX)
ALL_HEADERS	= -I libft/ -I include/ -I mlx
CC			= gcc
CFLAGS		= -Wall -Wextra 
ALL_LIBS	= -L mlx -lmlx -framework OpenGL -framework AppKit -L libft -lft
NAME		= cub3D 


%.o: %.c $(DEPS) 
	$(CC) $(CFLAGS) $(ALL_HEADERS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(@) $(OBJ) $(ALL_LIBS)

$(LIB_FT):
	make all -C ./libft/

$(LIB_MLX):
	make -C mlx
	
clean:
	make clean -C ./libft/
	make clean -C ./mlx/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME)

re: fclean all
