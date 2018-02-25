/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** component interface
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

	#include <cstddef>
	#include <string>

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent {
	public:
		struct ComponentLink {
			IComponent 	&_linked;
			size_t		_pairedPin;
			size_t		_pin;
			Tristate	_value;
		};

		virtual ~IComponent() = default;
		virtual Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin) noexcept = 0;
		virtual void dump() const noexcept = 0;
		virtual const std::string &getName() const noexcept = 0;
		virtual const std::string &getType() const noexcept = 0;
		virtual Tristate getLinkByPin(size_t pin) const noexcept = 0;
		virtual bool isValid() const noexcept = 0;
	protected:
	private:
	};
}


#endif /* !ICOMPONENT_HPP_ */
