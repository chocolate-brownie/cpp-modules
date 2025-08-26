/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:49:02 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/26 20:59:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {

  int numZombies = 4;

  std::cout << "Creating zombies on the heap" << std::endl;
  Zombie *zombies = zombieHorde(numZombies, "Hordeling");

  std::cout << std::endl << "The horde annouces itself" << std::endl;
  for (int i = 0; i < numZombies; i++) {
    zombies[i].announce();
  }

  std::cout << std::endl << "Destroying the hordes..." << std::endl;
  delete[] zombies;

  return 0;
}
