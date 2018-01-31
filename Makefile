##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CXX		=	c++

NAME		=	nanotekspice

RM		=	rm -vf

SRCS		=	src/main.cpp				\
			src/LogicGates.cpp			\
			src/components/DefaultComponent.cpp	\
			src/components/Ref4001Comp.cpp		\
			src/components/Ref2716Comp.cpp		\
			src/components/Ref4008Comp.cpp		\
			src/components/Ref4011Comp.cpp		\
			src/components/Ref4013Comp.cpp		\
			src/components/Ref4017Comp.cpp		\
			src/components/Ref4030Comp.cpp		\
			src/components/Ref4040Comp.cpp		\
			src/components/Ref4069Comp.cpp		\
			src/components/Ref4071Comp.cpp		\
			src/components/Ref4081Comp.cpp		\
			src/components/Ref4094Comp.cpp		\
			src/components/Ref4514Comp.cpp		\
			src/components/Ref4801Comp.cpp \
			src/Error.cpp \
			src/readfile/openfile.cpp	\


OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-LogicGates.cpp	\
			src/LogicGates.cpp

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Iinclude/

all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: clean
debug: $(NAME)

tests: CPPFLAGS += -lcriterion
tests: fclean
tests: $(NAME) $(TEST)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)
	@echo " --> $(NAME) built!"

$(TEST): $(OBJS_TEST)
	@$(CXX) $(OBJS_TEST) -o $(TEST) -lcriterion

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
