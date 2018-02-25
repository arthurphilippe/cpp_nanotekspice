/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#ifndef SIMULATION_HPP_
	#define SIMULATION_HPP_

	#include <vector>
	#include <sstream>
	#include "DefaultComponent.hpp"

namespace nts {
	class Simulation {
	public:
		Simulation(std::vector<std::unique_ptr<IComponent>> &);
		~Simulation();
		void run() noexcept;
		void display() const noexcept;
		void loop() noexcept;
		void printSortedOutput() const noexcept;
		const std::stringstream &getBuffer() const noexcept
		{
			return _output;
		}
		static void sigIntHandler(int) noexcept;
	private:
		static bool sortFunctor(const std::string &a,
					const std::string &b) noexcept;
		void _computeOutput(std::unique_ptr<IComponent> &comp) noexcept;
		std::vector<std::unique_ptr<IComponent>> &_components;
		std::stringstream _output;
		static bool _intSignalRecieved;
	};
}


#endif /* !SIMULATION_HPP_ */
