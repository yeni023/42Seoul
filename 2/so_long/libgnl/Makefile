NAME = libgnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# INCLUDES = ./libft.h

SRCS_PART1 = \
			get_next_line.c get_next_line_utils.c


SRCS = \
		$(SRCS_PART1)

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