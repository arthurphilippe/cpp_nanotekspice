/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4030COMP_HPP_
	#define REF4030COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4030Comp : public DefaultComponent {
	public:
		Ref4030Comp();
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4030COMP_HPP_ */
