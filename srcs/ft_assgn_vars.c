/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assgn_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_str_is_empty_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/* нахождение начала карты и установка указателя "vars->map" на него */
int	set_map_string(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->all_map_size)
	{
		if (ft_str_is_empty_2(vars->all_date[i])
			|| vars->all_date[i][0] == '\n'
			|| !ft_str_is_map(vars->all_date[i]))
			i++;
		j++;
	}
	if (i >= j)
		return (1);
	vars->map = vars->all_date + i;
	return (0);
}

/* построчная передача для инициализация переменных текстур и RGB */
int	ft_try_getstring_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->all_date[i])
	{
		if (!ft_str_is_empty(vars->all_date[i]))
			if (ft_assgn_vars(vars->all_date[i], vars))
				return (1);
		i++;
		if (vars->init_flag_textures && vars->F.init_flag && vars->C.init_flag)
			break ;
	}
	if (!(vars->south && vars->north && vars->east && vars->west))
		return (error_msg_main(2, 1));
	if (!(vars->F.init_flag && vars->C.init_flag))
		return (error_msg_main(2, 2));
	if (set_map_string(vars))
		return (error_msg_main(2, 3));
	return (0);
}

/* пропус пробелов и дубликат строк*/
int	ft_assgn_text(char *str, char **vars)
{
	str = str + 3;
	while (*str == ' ')
		str++;
	*vars = ft_strdup(str);
	if (*vars)
		return (0);
	return (error_msg_main(2, 1));
}

int	ft_assgn_vars(char *str, t_vars *vars)
{
	while (*str == ' ')
		str++;
	if (ft_strncmp("SO ", str, 3) == 0)
		return (ft_assgn_text(str, &vars->south));
	else if (ft_strncmp("NO ", str, 3) == 0)
		return (ft_assgn_text(str, &vars->north));
	else if (ft_strncmp("EA ", str, 3) == 0)
		return (ft_assgn_text(str, &vars->east));
	else if (ft_strncmp("WE ", str, 3) == 0)
		return (ft_assgn_text(str, &vars->west));
	else if (ft_strncmp("F ", str, 2) == 0)
		return (ft_rgb_assign(str + 2, &vars->F));
	else if (ft_strncmp("C ", str, 2) == 0)
		return (ft_rgb_assign(str + 2, &vars->C));
	if (vars->south && vars->north && vars->east && vars->west)
		vars->init_flag_textures = 1;
	return (0);
}
