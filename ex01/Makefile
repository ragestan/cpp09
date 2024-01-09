CXX = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM        = rm -f
NAME    = RPN
SRC        = main.cpp\
			RPN.cpp

FILIO = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(FILIO)
		${CXX} ${CPPFLAGS} ${FILIO} -o ${NAME}

clean:
	$(RM) $(FILIO)

fclean: clean
	$(RM) $(NAME)

re: fclean all