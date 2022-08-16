#include "libft.h"

int	get_next_line(int fd, char	**line)
{
	int		i;
	int		rd;
	char	ch;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(10000);
	*line = buffer;
	rd = read(fd, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i++] = ch;
		rd = read(fd, &ch, 1);
	}
	buffer[i] = '\0';
	return (rd);
}
