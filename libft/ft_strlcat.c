#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	dest_len = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (dest_len < dstsize && dest[dest_len])
		dest_len++;
	if (dstsize <= dest_len)
		return (dstsize + src_len);
	i = 0;
	while (dstsize && (--dstsize - dest_len) && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
