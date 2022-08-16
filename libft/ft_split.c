#include "libft.h"

static int	ft_lcount(const char *s, char c)
{
	int	i;
	int	lcount;

	i = 0;
	lcount = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		while (s[i] && c != s[i])
			i++;
		lcount++;
	}
	if (i)
		lcount -= (c == s[i - 1]);
	return (lcount);
}

static char	**ft_freeres(char **res)
{
	if (NULL == res)
		return (NULL);
	while (*res)
		free(*res++);
	free(res);
	return (NULL);
}

static char	*ft_getpart(const char *s, char c)
{
	char	*c_pos;

	c_pos = ft_strchr(s, c);
	if (c_pos == NULL)
		return (ft_substr(s, 0, ft_strlen(s)));
	else
		return (ft_substr(s, 0, c_pos - s));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		lines;
	int		l_pos;

	if (!s)
		return (NULL);
	lines = ft_lcount(s, c);
	res = (char **)malloc((lines + 1) * sizeof(char *));
	if (NULL == res)
		return (NULL);
	l_pos = 0;
	while (lines--)
	{
		while (*s && *s == c)
			s++;
		res[l_pos] = ft_getpart(s, c);
		if (NULL == res[l_pos])
			return (ft_freeres(res));
		s += ft_strlen(res[l_pos]);
		l_pos++;
	}
	res[l_pos] = NULL;
	return (res);
}
