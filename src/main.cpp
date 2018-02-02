/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include "Error.hpp"
#include "Readfile.hpp"
#include "DefaultComponent.hpp"
#include "Runtime.hpp"

int main(int ac, char **av)
{
	(void) ac;
	(void) av;

	nts::Runtime test;

	try {
		test.run();
	} catch (const RuntimeError &error) {
		error.what();
		return 84;
	}
}

/*
int main(int ac, char **av)
{
	try {
	parserTester(ac, av);
	} catch (const FileError &error) {
		error.what();
	}
	return 0;
}
*/
