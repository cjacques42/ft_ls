#include "ft_ls.h"

int			ft_displayError(char *filename, char *str)
{
	if (ft_strcmp("\0", filename) == 0)
	{
		ft_puterr("ls: fts_open: ");
		ft_puterr(str);
		ft_puterr("\n");
		return (1);
	}
	else
	{
		ft_puterr("ls: ");
		ft_puterr(filename);
		ft_puterr(": ");
		ft_puterr(str);
		ft_puterr("\n");
		return (0);
	}
}

void		ft_parsePath(int ac, char **av, t_list **lst_rep, t_list **lst_file)
{
	DIR		*ptr;

	if (ac <= 1)
		return ;
	ptr = opendir(*av);
	if (ptr == NULL)
	{
		if (errno == 20)
			ft_lstadd(lst_file, ft_lstnew((void*)*av, 0));
		else
			ft_displayError(*av, strerror(errno));
	}
	else
	{
		ft_lstadd(lst_rep, ft_lstnew((void*)ptr, 0));
	}
	ft_getPathFromParam(ac - 1, av + 1, lst_rep, lst_file);
}

int			ft_getPathFromParam(int ac, char **av, t_list **lst_rep, t_list **lst_file)
{
	int		len;
	int		i;
	DIR		*ptr;

	i = 0;
	len = ac;
	while (len > 1)
	{
		if (ft_strcmp("\0", av[i]) == 0)
		{
			return (ft_displayError(av[i], "No such file or directory"));
		}
		i++;
		len--;
	}
	ft_parsePath(ac, av, lst_rep, lst_file);
	if (*lst_rep == NULL && (ptr = opendir(*av)))
		ft_lstadd(lst_rep, ft_lstnew((void*)ptr, 0));
	return (0);
}
