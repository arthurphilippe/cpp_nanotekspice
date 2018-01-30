/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4040COMP_HPP_
	#define REF4040COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4040Comp : public DefaultComponent {
	public:
		Ref4040Comp();
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4040COMP_HPP_ */
