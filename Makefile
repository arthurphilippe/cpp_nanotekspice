##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CXX		=	g++ -std=c++14

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
			src/components/Output.cpp\
			src/components/Input.cpp		\
			src/components/Ref4801Comp.cpp \
			src/readfile/openfile.cpp	\
			src/Error.cpp \
			src/readfile/Parser.cpp

OBJ_MAIN	=	$(MAIN:.cpp=.o)

OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-LogicGates.cpp	\
			tests/test-Clock.cpp

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Iinclude/

all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: CPPFLAGS += -lcriterion
tests: clean
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
