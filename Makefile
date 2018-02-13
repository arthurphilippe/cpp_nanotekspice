##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## Makefile
##

CXX		=	g++

NAME		=	nanotekspice

RM		=	rm -vf

MAIN		=	src/main.cpp

SRCS		=	src/LogicGates.cpp			\
			src/DefaultComponent.cpp		\
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
			src/readfile/Args.cpp			\
			src/Runtime.cpp

OBJ_MAIN	=	$(MAIN:.cpp=.o)

OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-LogicGates.cpp	\
			tests/test-Parser.cpp		\
			tests/test-Clock.cpp		\
			tests/test-Components.cpp	\
			tests/test-Simulation.cpp	\
			tests/test-Args.cpp

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Iinclude/ -std=c++17

%.o: %.cpp
	@printf "[\033[0;32massembly\033[0m]....%s\n" $<
	@$(CXX) -c -o $@ $< $(CPPFLAGS)


all: $(NAME)

debug: CPPFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: CXX=g++
tests: $(TEST)

tests_run: tests
	@./$(TEST)

$(NAME): $(OBJ_MAIN) $(OBJS)
	@printf "[\033[0;36mlinkage\033[0m].....%s\n" $(NAME)
	@$(CXX) $(OBJ_MAIN) $(OBJS) -o $(NAME)
	@echo -e " --> complete!"

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinkage\033[0m].....%s\n" $(TEST)
	@$(CXX) $(OBJS_TEST) -o $(TEST) -lcriterion
	@echo -e " --> complete!"
clean:
	@echo -en "[\033[0;31mdeletion\033[0m]...." ; $(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'
	@echo " of $(NAME)'s objects"

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@echo -e "[\033[0;31mdeletion\033[0m]....$(NAME)"

re: fclean all

.PHONY: all clean fclean re debug tests
