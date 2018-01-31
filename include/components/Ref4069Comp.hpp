/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4069COMP_HPP_
	#define REF4069COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4069Comp : public DefaultComponent {
	public:
		Ref4069Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4069COMP_HPP_ */
