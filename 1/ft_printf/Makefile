NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = 	ft_printf.c  	\
		ft_print_c.c	\
		ft_print_s.c	\
		ft_print_d.c	\
		ft_print_i.c	\
		ft_print_p.c	\
		ft_print_u.c	\
		ft_print_x.c	\
		ft_print_etc.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar crs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re