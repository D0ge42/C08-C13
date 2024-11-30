#include <stdio.h>
#include <stdlib.h>

int	ft_strchr(char *charset, char s)
{
	while (*charset)
	{
		if (*charset == s)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;
	int	j;

	j = ft_strlen(str);
	count = 1;
	i = 0;
	if (*str == '\0')
		return (0);
	while (ft_strchr(charset, str[j - 1]))
		j--;
	while (ft_strchr(charset, str[i]))
		i++;
	while (i < j)
	{
		if (ft_strchr(charset, str[i]))
		{
			count++;
			while (ft_strchr(charset, str[i]))
				i++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	*end;
	int		i;
	int		j;
	int		words;
	char	**new;

	i = 0;
	words = count_words(str, charset);
	new = (char **)malloc(sizeof(char *) * (words + 1));
	while (words-- && *str)
	{
		j = 0;
		while (ft_strchr(charset, *(str)))
			str++;
		end = str;
		while (!ft_strchr(charset, *(end)))
			end++;
		new[i] = (char *)malloc(sizeof(char) * (end - str + 1));
		while (str < end)
			new[i][j++] = *str++;
		new[i++][j] = '\0';
	}
	new[i] = 0;
	return (new);
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;
	char	**new;
	char	*charset;
	int		words;

	str = "++ciao!++co-,me!.tai-------";
	charset = "!-,.";
	i = 0;
	words = count_words(str, charset);
	new = ft_split(str, charset);
	while (i < words)
	{
		printf("%s\n", new[i]);
		i++;
	}
}
