/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:24:04 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/26 20:52:27 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie *zombieHorde(int N, std::string name) {
  Zombie *horde = new Zombie[N];

  for (int i = 0; i < N; i++) {
    horde[i].setName(name);
  }

  return horde;
}