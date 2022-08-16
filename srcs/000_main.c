/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   000_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 07:13:30 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 12:09:30 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	ft_first_init(&vars);
	if (argc != 2)
	{
		error_msg_main(1, 0);
		ft_free_vars(&vars);
		return (-1);
	}
	if (ft_parsing_main(argv[1], &vars))
	{
		ft_free_vars(&vars);
		return (-1);
	}
	exe_game(&vars);
	return (0);
}
