#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n && str[i] != (unsigned char)c)
		i ++;
	if (i == n)
		return (NULL);
	return ((void *)&str[i]);
}
