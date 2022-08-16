#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	size_t	total;

	total = count * size;
	dst = malloc(total);
	if (!dst)
		return (0);
	ft_bzero(dst, total);
	return ((void *)dst);
}
