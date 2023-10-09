NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INCLUDES = ./libft.h

SRCS_PART1 = \
			ft_atoi.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_strchr.c \
			ft_memset.c \
			ft_calloc.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_strdup.c \
			ft_memcmp.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strncmp.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_memmove.c \
			ft_strjoin.c \
			ft_putchar_fd.c \
			ft_minitalk_atoi.c \
			upgrade_ft_strchr.c \
			ft_putstr_fd.c

SRCS_PART2 = \
			ft_itoa.c \
			ft_split.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

SRCS = \
		$(SRCS_PART1) \
		$(SRCS_PART2)

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = \
			 	ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstiter.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJ_FILE = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILE = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	ar crs $(NAME) $^

bonus :
	make BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re