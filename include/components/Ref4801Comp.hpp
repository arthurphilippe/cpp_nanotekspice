/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4801COMP_HPP_
	#define REF4801COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4801Comp : public DefaultComponent {
	public:
		Ref4801Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4801COMP_HPP_ */
