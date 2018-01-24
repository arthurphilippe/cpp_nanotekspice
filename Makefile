##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -vf

SRCS		=	src/main.cpp

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Iinclude/

all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: $(NAME)

debugre: CPPFLAGS += -ggdb
debugre: fclean
debugre: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
