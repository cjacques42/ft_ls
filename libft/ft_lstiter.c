/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:19:00 by jcornill          #+#    #+#             */
/*   Updated: 2016/05/19 18:49:22 by jcornill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	**begin;
	t_list	*src;

	begin = &lst;
	src = *begin;
	if (!src)
		return ;
	while (src->next != NULL)
	{
		f(src);
		src = src->next;
	}
	f(src);
}
