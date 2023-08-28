NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIB = -Llibft -lft -Llibgnl -lgnl -L./mlx -lmlx

INCLUDES = -I./libgnl -I./libft -I./mlx -I./mandatory

MLX = mlx/libmlx.a

RM = rm -rf

# DIR = ./mandatory/

# 제출 전에 바꾸고 내기
# MANDATORY_NAME = check.c exit.c \
# 		image_init.c \
# 		key.c \
# 		main.c \
# 		mlx_etc.c \
# 		move.c

SRCS = ./mandatory/check.c \
		./mandatory/image_init.c \
		./mandatory/main.c \
		./mandatory/move.c \
		#./mandatory/exit.c ./mandatory/key.c ./mandatory/mlx_etc.c \

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