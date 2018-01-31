/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4008COMP_HPP_
	#define REF4008COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4008Comp : public DefaultComponent {
	public:
		Ref4008Comp();
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4008COMP_HPP_ */
