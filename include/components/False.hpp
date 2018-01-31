/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** true
*/

#ifndef FALSE_HPP_
	#define FALSE_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class False : public DefaultComponent {
	public:
		False(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}
#endif /* !FALSE_HPP_ */
