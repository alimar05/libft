/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:17:56 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/29 20:36:04 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elm_nw;
	t_list	*lst_nw;
	t_list	*lst_bf;

	if (lst != NULL & f != NULL)
	{
		if (!(elm_nw = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		lst_nw = elm_nw;
		lst_bf = lst->next;
		while (lst_bf)
		{
			if (!(elm_nw->next =
						ft_lstnew(f(lst_bf)->content, f(lst_bf)->content_size)))
			{
				ft_lstdel(&lst_nw, del);
				return (NULL);
			}
			elm_nw = elm_nw->next;
			lst_bf = lst_bf->next;
		}
		return (lst_nw);
	}
	return (NULL);
}
