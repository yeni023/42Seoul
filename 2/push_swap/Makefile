# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeeunpar <yeeunpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 01:44:03 by yeeunpar          #+#    #+#              #
#    Updated: 2023/11/20 16:04:24 by yeeunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

MPATH_SRCS = args.c check_sort.c find.c main.c \
		move_pa_pb.c move_ra_rb_rr.c move_rra_rrb_rrr.c \
		move_sa_sb_ss.c rotate.c sort_utils.c sort.c stack_pop.c\
		push_stack.c stack.c utils_split.c utils.c

# BPATH_SRCS = args_checker.c checker_utils.c checker.c check_sort_checker.c \
# 				get_next_line.c get_next_line_utils.c operationp_checker.c \
# 				operationr_checker.c operations_checker.c operationrr_checker.c \
# 				stack_checker.c stack_pop_checker.c push_stack_checker.c \
# 				utils_split_checker.c utils_checker.c

# FILES
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_DIR	=	bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

NAME = push_swap
BONUS = checker
RM = rm -rf

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

$(BONUS):		$(OBJ_B)
				@$(CC) $(OBJ_B) -o $(BONUS)
				@echo -e "$(GREEN)$(BONUS) created!$(DEFAULT)"

all:			$(NAME)

bonus:			$(BONUS)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(BONUS)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m