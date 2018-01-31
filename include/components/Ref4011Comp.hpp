/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4011COMP_HPP_
	#define REF4011COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4011Comp : public DefaultComponent {
	public:
		Ref4011Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4011COMP_HPP_ */
