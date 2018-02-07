/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <fstream>
#include <iostream>
#include "Error.hpp"
#include "Readfile.hpp"
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
	try {
		nts::Runtime test(ac, av);
		test.run();
       	}
	catch (const RuntimeError &error) {
		if (error.getError().compare("exit") == 0)
			return 0;
		else if (error.getError().compare("print_usage") == 0)
			print_usage();
		else {
			error.what();
			return 84;
		}
	} 
	return 0;
}

