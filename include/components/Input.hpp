/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Input : public DefaultComponent {
	public:
		Input(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
		Tristate _state;
	private:
	};
}

#endif /* !INPUT_HPP_ */
