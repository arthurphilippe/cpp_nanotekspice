/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Output : public DefaultComponent {
	public:
		Output(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
		virtual bool isValid() const noexcept override;
	protected:
		Tristate _state;
	private:
	};
}

#endif /* !OUTPUT_HPP_ */
