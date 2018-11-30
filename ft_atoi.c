/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:33:08 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/29 15:44:02 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' | c == '\n' | c == '\r' |
			c == '\t' | c == '\v' | c == '\f')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	size_t		i;
	size_t		nbr;
	signed char	sign;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[0] == '+' & str[1] == '-') | (str[0] == '-' & str[1] == '+'))
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		if (nbr > ATOI_MAX || (nbr == ATOI_MAX && str[i] - '0' > 7))
			return ((sign == 1) ? -1 : 0);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	return (sign * nbr);
}
