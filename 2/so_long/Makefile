NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

# 제출 전에 바꾸고 내기
SRCS = 	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ -L./mlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c
	make -C ./mlx
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	make -C ./mlx clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re