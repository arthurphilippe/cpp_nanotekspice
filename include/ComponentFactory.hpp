/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** ComponentFactory
*/

#ifndef COMPOMENTFACTORY_HPP_
	#define COMPOMENTFACTORY_HPP_

	#include <vector>
	#include <string>
	#include <memory>
	#include <unordered_map>
	#include <functional>
	#include "IComponent.hpp"

namespace nts{
	class ComponentFactory {
		public:
			ComponentFactory() = delete;
			static std::unique_ptr<IComponent> createComponent(
			const std::string &type,
			const std::string &value = "",
			const std::string &param = "");

		protected:
		private:
			static std::unordered_map<std::string,
				std::function<std::unique_ptr<IComponent>(
					const std::string &)>> _genesisMap;
			static void populateGenesisMap();
			static std::unique_ptr<IComponent> create2716(
				const std::string &name,
				const std::string &value);
			static std::unique_ptr<IComponent> create4001(
				const std::string &name);
			static std::unique_ptr<IComponent> create4008(
				const std::string &name);
			static std::unique_ptr<IComponent> create4011(
				const std::string &name);
			static std::unique_ptr<IComponent> create4013(
				const std::string &name);
			static std::unique_ptr<IComponent> create4017(
				const std::string &name);
			static std::unique_ptr<IComponent> create4030(
				const std::string &name);
			static std::unique_ptr<IComponent> create4040(
				const std::string &name);
			static std::unique_ptr<IComponent> create4069(
				const std::string &name);
			static std::unique_ptr<IComponent> create4071(
				const std::string &name);
			static std::unique_ptr<IComponent> create4081(
				const std::string &name);
			static std::unique_ptr<IComponent> create4094(
				const std::string &name);
			static std::unique_ptr<IComponent> create4514(
				const std::string &name);
			static std::unique_ptr<IComponent> create4801(
				const std::string &name);
			static std::unique_ptr<IComponent> createTrue(
				const std::string &name);
			static std::unique_ptr<IComponent> createFalse(
				const std::string &name);
			static std::unique_ptr<IComponent> createInput(
				const std::string &name);
			static std::unique_ptr<IComponent> createOutput(
				const std::string &name);
			static std::unique_ptr<IComponent> createClock(
				const std::string &name);
	};
}

#endif /* !COMPOMENTFACTORY_HPP_ */
