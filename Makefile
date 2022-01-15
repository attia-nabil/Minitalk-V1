# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nattia <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:51:33 by nattia            #+#    #+#              #
#    Updated: 2022/01/14 15:51:38 by nattia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_CLIENT		=	mandatory/client.c
M_SERVER		=	mandatory/server.c

B_CLIENT		=	bonus/client_bonus.c
B_SERVER		=	bonus/server_bonus.c

TOOLS			=	tools/tools.c tools/tools1.c
HEADER			=	include/minitalk.h

RM				=	rm -f
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

all			:	mandatory

mandatory	:	$(M_CLIENT) $(M_SERVER) $(HEADER)
	$(CC) $(CFLAGS) -I include $(M_CLIENT) $(TOOLS) -o client
	$(CC) $(CFLAGS) -I include $(M_SERVER) $(TOOLS) -o server

bonus		:	$(B_CLIENT) $(B_SERVER) $(HEADER)
	$(CC) $(CFLAGS) -I include $(B_CLIENT) $(TOOLS) -o client_bonus
	$(CC) $(CFLAGS) -I include $(B_SERVER) $(TOOLS) -o server_bonus

fclean		:
	$(RM) client server client_bonus server_bonus
	
re			:	fclean all

.PHONY		:	all fclean re bonus mandatory
