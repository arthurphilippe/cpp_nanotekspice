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
	std::unique_ptr<nts::IComponent> bouton =
		std::move(nts::DefaultComponent::createComponent("input", "bouton"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	led->setLink(1, *bouton, 1);
	bouton->setLink(1, *led, 1);
	bouton->dump();
	led->dump();
	led->compute(1);
	bouton->compute(3);
	led->compute(1);
	bouton->compute(2);
	led->compute(1);
	// std::cout << bouton->getName() << std::endl;
}
