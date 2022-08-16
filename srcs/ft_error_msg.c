/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbeardl <trbeardl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:42 by trbeardl          #+#    #+#             */
/*   Updated: 2022/04/14 11:58:07 by trbeardl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

/* вывод сообщений об ошибках группы 1*/
void	error_msg_1(int i)
{
	char	*msg_mass[SIZE_ERROR_1];

	msg_mass[0] = "usage 2 arguments !\n";
	msg_mass[1] = "file is not .cub. Verify filename extension.\n";
	msg_mass[2] = "could not open .cub or .xpm.\n";
	msg_mass[3] = "could not read from .cub or .xpm.\n";
	msg_mass[4] = "could not close .cub or .xpm.\n";
	msg_mass[5] = "well this error is unknown...awkward\n";
	if (i >= 0 && i < SIZE_ERROR_1)
		printf("%s", msg_mass[i]);
	else
		printf("%s", msg_mass[SIZE_ERROR_1 - 1]);
}

/* вывод сообщений об ошибках группы 2 (препарсинг картф и переменных)*/
void	error_msg_2(int i)
{
	char	*msg_mass[SIZE_ERROR_2];

	msg_mass[0] = "Malloc failed while allocating memory for the map\n";
	msg_mass[1] = "please verify texture informations format\n";
	msg_mass[2] = "please verify C or F [RGB] informations format.\n";
	msg_mass[3] = "missing information to create map.\n";
	msg_mass[4] = "well this error is unknown...awkward\n";
	if (i >= 0 && i < SIZE_ERROR_2)
		printf("%s", msg_mass[i]);
	else
		printf("%s", msg_mass[SIZE_ERROR_2 - 1]);
}

/* вывод сообщений об ошибках группы 3 (парсинг карты)*/
void	error_msg_3(int i)
{
	char	*msg_mass[SIZE_ERROR_3];

	msg_mass[0] = "non authorized character in map grid.\n";
	msg_mass[1] = "map has more than one player.\n";
	msg_mass[2] = "horizontal empty line found in map grid.\n";
	msg_mass[3] = "empty line found vertically.\n";
	msg_mass[4] = "wall missing. Map border must '1' only.\n";
	msg_mass[5] = "missing player in map grid.\n";
	msg_mass[6] = "well this error is unknown...awkward\n";
	if (i >= 0 && i < SIZE_ERROR_3)
		printf("%s", msg_mass[i]);
	else
		printf("%s", msg_mass[SIZE_ERROR_3 - 1]);
}

/* выбор группы ошибок для дальнейшего вывода */
int	error_msg_main(int class, int error)
{
	printf("Error\nParsing: ");
	if (class == 1)
		error_msg_1(error);
	if (class == 2)
		error_msg_2(error);
	if (class == 3)
		error_msg_3(error);
	return (1);
}
