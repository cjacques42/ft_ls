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
	char		c;

	c = 0;
	av++;
	options = ft_getOptions(&ac, av, &c);
	ft_printf("Option: %d", options, options);
	if (c)
	{
		ft_printf("ls: illegal option -- %c\nusage: ls [-%s] [file ...]\n", c, OPTION_CHARS);
		return (1);
	}
	return (0);
}
