/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 11:32:33 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/19 19:41:32 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

# define OPTION_CHARS "Ralrt"

char		**ft_getOptions(int *ac, char **av, char *c, int *option);
int			ft_getPathFromParam(int ac, char **av, t_list **lst_rep, t_list **lst_file);

#endif
