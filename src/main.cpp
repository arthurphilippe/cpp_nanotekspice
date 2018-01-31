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
	std::unique_ptr<nts::IComponent> kappa = std::move(nts::DefaultComponent::createComponent("4001"));
	std::cout << "salut" << std::endl;
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4001"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4008"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4011"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4013"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4017"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4030"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4040"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4069"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4071"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4081"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4094"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4514"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("4801"));
	kappa->dump();
	kappa = std::move(nts::DefaultComponent::createComponent("2716"));
	kappa->dump();

	// std::cout << kappa->getName() << std::endl;
}
