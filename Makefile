##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -vf

MAIN		=	src/main.cpp

SRCS		=	src/LogicGates.cpp			\
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
			src/components/Ref4801Comp.cpp		\
			src/components/True.cpp			\
			src/components/False.cpp		\
			src/components/Clock.cpp		\
			src/components/Output.cpp		\
			src/components/Input.cpp		\
			src/readfile/openfile.cpp		\
			src/Error.cpp				\
			src/readfile/Parser.cpp			\
			src/Simulation.cpp			\
      src/readfile/Args.cpp

OBJ_MAIN	=	$(MAIN:.cpp=.o)

OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-LogicGates.cpp	\
			tests/test-Components.cpp \
			tests/test-Clock.cpp		\
			tests/test-Components.cpp	\
			tests/test-Simulation.cpp \
			tests/test-Args.cpp

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Iinclude/ -std=c++17

all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: $(TEST)

tests_run: tests
	@./$(TEST)

$(NAME): $(OBJ_MAIN) $(OBJS)
	@$(CXX) $(OBJ_MAIN) $(OBJS) -o $(NAME)
	@echo " --> $(NAME) built!"

$(TEST): $(OBJS_TEST)
	@$(CXX) $(OBJS_TEST) -o $(TEST) -lcriterion
	@echo " --> $(TEST) built!"
clean:
	@$(RM) $(OBJS) $(OBJS_TEST)

fclean: clean
	@$(RM) $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re debug tests
