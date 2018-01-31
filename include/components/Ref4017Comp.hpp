/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4017COMP_HPP_
	#define REF4017COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4017Comp : public DefaultComponent {
	public:
		Ref4017Comp();
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4017COMP_HPP_ */