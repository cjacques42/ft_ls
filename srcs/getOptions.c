#include "ft_ls.h"

int		ft_putBitToOne(char c)
{
	int		option;
	int		i;

	i = 0;
	option = 1;
	while (OPTION_CHARS[i] != c)
		i++;
	return (option << i);
}

int		ft_parseParam(char *str, char *c)
{
	int		option;
	int		i;

	option = 0;
	i = 1;
	while (str[i])
	{
		if (ft_strchr(OPTION_CHARS, str[i]) == NULL)
		{
			*c = str[i];
			return (-1);
		}
		else
			option |= ft_putBitToOne(str[i]);
		i++;
	}
	return (option);
}

char	**ft_getOptions(int *ac, char **av, char *c, int *option)
{
	int		ret;

	while (*ac > 1)
	{
		if (*av && ft_strcmp(*av, "-") == 0)
			return (av);
		else if (*av && ft_strcmp(*av, "--") == 0)
		{
			(*ac)--;
			av++;
		}
		else if (*av && **av == '-')
		{
			ret = ft_parseParam(*av, c);
			if (ret == -1 && (*option = ret))
				return (av);
			else
				*option |= ret;
		}
		else
			return (av);
		av++;
		(*ac)--;
	}
	return (av);
}
