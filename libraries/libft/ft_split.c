#include "libft.h"

static int	nword(const char *s, char c)
{
	int		nb;
	int		j;

	nb = 0;
	while (*s != '\0')
	{
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j != 0)
		{
			s += j;
			nb = nb + 1;
		}
		else
			s++;
	}
	return (nb);
}

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

static char	**ft_res(char **ptr, char *s, char c, int k)
{
	size_t	j;
	int		i;

	i = 0;
	while (i < k)
	{
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j != 0)
		{
			ptr[i] = malloc(sizeof(char) * (j + 1));
			if (!ptr[i])
			{
				ft_free(ptr);
				return (NULL);
			}
			ft_strlcpy(ptr[i], s, j + 1);
			s += j;
			i++;
		}
		else
			s++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		nb;

	if (!s)
		return (NULL);
	nb = nword(s, c);
	ptr = malloc(sizeof(char *) * (nb + 1));
	if (!ptr)
		return (NULL);
	return (ft_res(ptr, (char *)s, c, nb));
}
