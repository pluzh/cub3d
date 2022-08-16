/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* подсчет строк в файле*/
int	count_line_in_file(int fd)
{
	char	*str;
	int		str_count;

	str_count = 0;
	while (get_next_line(fd, &str))
	{
		str_count++;
		free(str);
	}
	if (ft_strlen(str))
		str_count++;
	free(str);
	return (str_count);
}

/* Чтение карты из файла и запись в структуру */
int	record_map(int fd, t_vars	*vars)
{
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(fd, &str))
	{
		vars->all_date[i] = ft_strdup(str);
		if (!vars->all_date[i])
			return (1);
		i++;
		free(str);
	}
	if (!ft_str_is_empty(str))
	{
		vars->all_date[i] = ft_strdup(str);
		if (!vars->all_date[i])
			return (1);
	}
	free(str);
	return (0);
}

/* Подсчет количества не пустых строк в файле. Вызов функции record_map*/
int	read_receord_map(char	*map_file_name, t_vars *vars)
{
	int		fd;

	fd = open(map_file_name, O_RDONLY);
	if (fd < 0)
		return (error_msg_main(1, 2));
	vars->all_map_size = count_line_in_file(fd);
	vars->all_date = ft_calloc(vars->all_map_size + 1, sizeof(char *));
	if (!vars->all_date)
		return (error_msg_main(2, 0));
	close(fd);
	if (fd < 0)
		return (error_msg_main(1, 4));
	fd = open(map_file_name, O_RDONLY);
	if (fd < 0)
		return (error_msg_main(1, 2));
	if (record_map(fd, vars))
		return (error_msg_main(2, 0));
	return (0);
}

int	ft_parsing_1(char *map_file_name, t_vars *vars)
{
	if (read_receord_map(map_file_name, vars))
		return (1);
	if (ft_try_getstring_vars(vars))
		return (1);
	if (ft_parsing_map(vars))
		return (1);
	return (0);
}
