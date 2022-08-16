/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:17:46 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 08:09:58 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* Проверка корректности расширения файла */
int	ft_check_file_extension(char *filename, char *extantion_name)
{
	unsigned int	i;

	i = (unsigned int)(ft_strlen(filename) - ft_strlen(extantion_name));
	if (ft_strcmp(&filename[i], extantion_name) == 0)
		return (0);
	else
		return (error_msg_main(1, 1));
}

/* Проверка читаемости файла*/
int	ft_is_file_readable(char *file_name)
{
	int		fd;
	int		ret;
	char	buf;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (error_msg_main(1, 2));
	ret = read(fd, &buf, 1);
	if (ret < 0)
		return (error_msg_main(1, 3));
	close(fd);
	if (fd < 0)
		return (error_msg_main(1, 4));
	return (0);
}

int	ft_parsing_main(char *map_file_name, t_vars *vars)
{
	if (ft_check_file_extension(map_file_name, "cub"))
		return (1);
	if (ft_is_file_readable(map_file_name))
		return (1);
	if (ft_parsing_1(map_file_name, vars))
		return (1);
	return (0);
}
