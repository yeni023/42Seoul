NAME		= RPN
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp RPN.cpp

OBJ = $(SRC:cpp=o)

all: $(NAME)

# colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
ORANGE = \033[38;5;208m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
CUSTOM = \033[38;5;135m

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(CYAN)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(CYAN)║       CPP09 ex01 compile finished.       ║$(DEF_COLOR)"
	@echo "$(CYAN)╚══════════════════════════════════════════╝$(DEF_COLOR)"

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@
	@echo "$(CYAN)Compiling... \t$< $(DEF_COLOR)"

clean:
	@rm -f $(OBJ)
	@echo "$(ORANGE)ex01 obj files has been deleted.$(DEF_COLOR)"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "$(RED)ex01 archive files has been deleted.$(DEF_COLOR)"

re: fclean all
	@echo "$(YELLOW)Cleaned and rebuilt ex01.$(DEF_COLOR)"

.PHONY: all clean fclean re