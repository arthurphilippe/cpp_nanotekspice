/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Clock : public DefaultComponent {
	public:
		Clock(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
		static Tristate _state;
	private:
	};
}


#endif /* !CLOCK_HPP_ */
