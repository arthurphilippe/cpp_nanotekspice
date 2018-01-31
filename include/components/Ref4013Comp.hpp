/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4013COMP_HPP_
	#define REF4013COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4013Comp : public DefaultComponent {
	public:
		Ref4013Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4013COMP_HPP_ */
