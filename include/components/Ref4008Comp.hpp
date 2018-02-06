/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4008COMP_HPP_
	#define REF4008COMP_HPP_

	#include <list>
	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4008Comp : public DefaultComponent {
	public:
		struct TruthStatement {
			Tristate a;
			Tristate b;
			Tristate c;
			Tristate carry;
			Tristate sum;
		};
		Ref4008Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	private:
		std::list<TruthStatement> _truthTable;
		Tristate completeAdder(Tristate, Tristate, Tristate,
					Tristate &);
	};
}

#endif /* !REF4008COMP_HPP_ */
