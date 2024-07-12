# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 16:32:18 by yeeunpar          #+#    #+#              #
#    Updated: 2023/12/20 16:36:27 by yeeunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

CC				= @cc
CFLAGS			= -Wall -Werror -Wextra -pthread

SRC				= main.c utils.c init.c etc_message.c philo_thread.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

OBJS			= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@rm -f $(OBJS)
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:
	@make clean
	@rm -f $(NAME)
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m