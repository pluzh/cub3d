#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_uch;
	unsigned char	*src_uch;

	src_uch = (unsigned char *)src;
	dst_uch = (unsigned char *)dst;
	i = 0;
	while (i < n && src_uch[i] != (unsigned char)c)
	{
		dst_uch[i] = src_uch[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dst_uch[i] = src_uch[i];
		i++;
		return (&dst_uch[i]);
	}
}
