#include "libft.h"

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_if_positive(long n)
{
	int		size;
	char	*num_strring;
	long	num;

	num = n;
	size = len(num);
	num_strring = (char *)malloc(sizeof(char) * (size + 1));
	if (!num_strring)
		return (NULL);
	num_strring[size] = '\0';
	while (size > 0)
	{
		num_strring[size - 1] = num % 10 + 48;
		num = num / 10;
		size--;
	}
	return (num_strring);
}

static char	*ft_if_negative(long n)
{
	int		size;
	char	*num_strring;
	long	num;

	num = -n;
	size = len(num) + 1;
	num_strring = (char *)malloc(sizeof(char) * (size + 1));
	if (!num_strring)
		return (NULL);
	num_strring[0] = '-';
	num_strring[size] = '\0';
	while (size > 1)
	{
		num_strring[size - 1] = num % 10 + 48;
		num = num / 10;
		size--;
	}
	return (num_strring);
}

char	*ft_itoa(int n)
{
	char	*num_strring;

	if (n > 0)
		return (ft_if_positive(n));
	else if (n < 0)
		return (ft_if_negative(n));
	else if (n == 0)
	{
		num_strring = (char *)malloc(sizeof(char) * 2);
		if (!num_strring)
			return (NULL);
		num_strring[0] = 0 + 48;
		num_strring[1] = '\0';
		return (num_strring);
	}
	return (NULL);
}
