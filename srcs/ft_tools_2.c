/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:40:38 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/12 13:40:39 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* вывод массива строк на экран */
void	ft_print_map(char **map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

/* вывод екстуры и RGB на экран */
void	ft_print_var(t_vars *vars)
{
	printf("**********************************");
	printf("\nsouth = |%s|\n", vars->south);
	printf("west =  |%s|\n", vars->west);
	printf("noth =  |%s|\n", vars->north);
	printf("east =  |%s|\n", vars->east);
	printf("rgb F = %d, %d, %d\n", vars->F.r, vars->F.g, vars->F.b);
	printf("rgb C = %d, %d, %d\n", vars->C.r, vars->C.g, vars->C.b);
	printf("**********************************\n");
}
