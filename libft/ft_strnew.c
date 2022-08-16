#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (size));
	*line = '\0';
	return (line);
}
