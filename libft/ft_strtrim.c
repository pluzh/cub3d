#include "libft.h"

static int	find_ch_str (char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	first(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!find_ch_str(s1[i], set))
			return (i);
		i++;
	}
	return (-1);
}

static size_t	last(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1) - 1;
	while (j)
	{
		if (!find_ch_str(s1[j], set))
			return (j + 1);
		j--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first_len;
	size_t	last_len;
	size_t	i;
	char	*return_string;

	i = 0;
	if (!s1)
		return (NULL);
	first_len = first(s1, set);
	last_len = last(s1, set);
	if (first_len >= last_len)
	{
		first_len = 0;
		last_len = 0;
	}
	return_string = malloc(sizeof(char) * (last_len - first_len + 1));
	if (!return_string)
		return (NULL);
	while (first_len < last_len)
		return_string[i++] = s1[first_len++];
	return_string[i] = '\0';
	return (return_string);
}
