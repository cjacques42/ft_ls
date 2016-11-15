/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/24 11:45:06 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int ac, char **av)
{
	int			options;
	t_list		*lst_rep;
	t_list		*lst_file;
	char		c;
	int			ret;

	c = 0;
	lst_rep = NULL;
	lst_file = NULL;
	options = 0;
	av = ft_getOptions(&ac, ++av, &c, &options);
	ft_printf("Option : %d -- param : %s\n", options, *av);
	if (c)
	{
		ft_printf("ls: illegal option -- %c\nusage: ls [-%s] [file ...]\n", c, OPTION_CHARS);
		return (1);
	}
	ret = ft_getPathFromParam(ac, av, &lst_rep, &lst_file);
	return (0);
}
