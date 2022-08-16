#include "libft.h"

static int	space_ignore(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					negative;
	unsigned long int	nbr;
	unsigned long int	max;

	negative = 1;
	max = 922337203685477580;
	i = space_ignore(str);
	if (str[i] == '-')
		negative = -1;
	if (negative == -1 || str[i] == '+')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr > max || (nbr == max && str[i] > '7')) && negative == 1)
			return (-1);
		else if ((nbr > max || (nbr == max && str[i] > '8')) && negative == -1)
			return (0);
		nbr = (nbr * 10) + (str[i++] - '0');
	}
	return (nbr * negative);
}
