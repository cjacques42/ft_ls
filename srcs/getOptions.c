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

int		ft_getOptions(int *ac, char **av, char *c)
{
	int		option;
	int		ret;

	option = 0;
	while (*ac > 1)
	{
		if (*av && ft_strcmp(*av, "-") == 0)
		{
			return (option);
		}
		else if (*av && ft_strcmp(*av, "--") == 0)
		{
			(*ac)--;
			av++;
		}
		else if (*av && **av == '-')
		{
			ret = ft_parseParam(*av, c);
			if (ret == -1)
			{
				return (ret);
			}
			else
			{
				option |= ret;
			}
		}
		else
		{
			return (option);
		}
		av++;
		(*ac)--;
	}
	return (option);
}
