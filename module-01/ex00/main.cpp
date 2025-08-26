/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:49:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/26 18:54:18 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {

	std::cout << "Creating a zombie on the heap..." << std::endl;
	Zombie* zombieFromHeap = newZombie("HeapZombie");
	zombieFromHeap->announce();

	std::cout << "\nCreating a zombie on the stack..." << std::endl;
	randomChump("StackZombie");

	std::cout << "\nManually deleting the heap zombie before exiting..." << std::endl;
	delete zombieFromHeap;

	return (0);
}