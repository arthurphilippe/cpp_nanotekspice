/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** logicgates
*/

#ifndef LOGICGATES_HPP_
	#define LOGICGATES_HPP_

	#include "IComponent.hpp"

namespace nts {
	class LogicGates {
	public:
		static Tristate ANDGate(Tristate a, Tristate b);
		static Tristate NANDGate(Tristate a, Tristate b);
		static Tristate ORGate(Tristate a, Tristate b);
		static Tristate NORGate(Tristate a, Tristate b);
		static Tristate XORGate(Tristate a, Tristate b);
	};
}

#endif /* !LOGICGATES_HPP_ */
