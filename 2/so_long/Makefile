NAME = so_long
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIB = -Llibft -lgnl -Llibgnl -lft -L./mlx -lmlx

INCLUDES = -I./libgnl -I./libft -I./mlx -I./mandatory

MLX = mlx/libmlx.a

RM = rm -rf

SRCS = ./mandatory/check_map.c \
		./mandatory/check_path.c \
		./mandatory/main.c \
		./mandatory/moving_key.c \
		./mandatory/key_func.c \
		./mandatory/print_errors.c \
		./mandatory/make_window.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(MLX)
	make -C ./libft all
	make -C ./libgnl all
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -framework OpenGL -framework AppKit $(LIB)

$(MLX)	:
	make -C ./mlx

.c.o :
	$(CC) -Imlx $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	make -C ./libft clean
	make -C ./libgnl clean
	make -C ./mlx clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
