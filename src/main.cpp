/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include "DefaultComponent.hpp"

int main()
{
	std::cout << "salut" << std::endl;
	auto kappa = nts::DefaultComponent::createComponent("4001");
	std::cout << kappa->getName() << std::endl;
}
