#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem_adr;

	mem_adr = (unsigned char *)b;
	while (len--)
		*mem_adr++ = (unsigned char)c;
	return (b);
}
