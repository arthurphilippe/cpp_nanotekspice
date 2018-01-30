##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -vf

SRCS		=	src/main.cpp				\
			src/components/DefaultComponent.cpp	\
			src/components/Ref4001Comp.cpp		\
			# src/components/Ref2716Comp.cpp		\
			# src/components/Ref4008Comp.cpp		\
			# src/components/Ref4011Comp.cpp		\
			# src/components/Ref4013Comp.cpp		\
			# src/components/Ref4017Comp.cpp		\
			# src/components/Ref4030Comp.cpp		\
			# src/components/Ref4040Comp.cpp		\
			# src/components/Ref4069Comp.cpp		\
			# src/components/Ref4071Comp.cpp		\
			# src/components/Ref4081Comp.cpp		\
			# src/components/Ref4094Comp.cpp		\
			# src/components/Ref4514Comp.cpp		\
			# src/components/Ref4801Comp.cpp

OBJS		=	$(SRCS:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Iinclude/

all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: fclean
debug: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)
	@echo " --> $(NAME) built!"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
