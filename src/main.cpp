/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <fstream>
#include <iostream>
#include "Error.hpp"
#include "Parser.hpp"
#include "DefaultComponent.hpp"
#include "Runtime.hpp"

static void print_usage()
{
	std::ifstream s("help.txt");
	std::string tmp;

	if (s.is_open()) {
		while (getline(s, tmp)) {
			std::cout << tmp << std::endl;
		}
	}
}

int main(int ac, char **av)
{
	if (ac < 3) {
		print_usage();
		return 84;
	}
	try {
		nts::Runtime test(ac, av);
		test.run();
	}
	catch (const RuntimeError &error) {
		if (error.getError() == "print_usage")
			print_usage();
		else {
			error.what();
			return 84;
		}
	}
	return 0;
}

