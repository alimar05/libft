# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rymuller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 14:32:09 by rymuller          #+#    #+#              #
#    Updated: 2018/11/29 17:02:38 by rymuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -c -Wall -Wextra -Werror

HEADERS = libft.h

SRCS = *.c

OBJECTS = *.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRCS) -I $(HEADERS)
	ar rs $(NAME) $(OBJECTS)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
