/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:08:21 by rymuller          #+#    #+#             */
/*   Updated: 2019/02/03 16:11:19 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list			*get_list(t_list **alst, int fd)
{
	t_list				*temp;

	temp = *alst;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(alst, temp);
	return (temp);
}

int						get_next_line(const int fd, char **line)
{
	static t_list		*alst;
	t_list				*list;
	void				*temp;
	int					num_bytes;
	char				buff[BUFF_SIZE + 1];

	CHERROR(fd, line, read(fd, buff, 0));
	CHECK((list = get_list(&alst, fd)));
	while (((num_bytes = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[num_bytes] = '\0';
		CHFRJOIN(temp, list->content, buff);
		if ((ft_strchr(buff, '\n')))
			break ;
	}
	CHREAD(num_bytes < BUFF_SIZE, ft_strlen(list->content));
	CHECK((*line = ft_strchrdup(list->content, '\n')));
	if (ft_strchr(list->content, '\n'))
	{
		CHFRESH(temp, list->content, ft_strchr(temp, '\n') + 1);
	}
	else
		ft_strclr(list->content);
	return (1);
}
