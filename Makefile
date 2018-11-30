# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 23:46:05 by jaleman           #+#    #+#              #
#    Updated: 2019/02/18 14:35:42 by rymuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

CFLAGS	= -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(patsubst %.c,%.o,$(wildcard *.c))
	ar rs $(NAME) $?

%.o: %.c
	gcc $(CFLAGS) -I includes/ $<

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
