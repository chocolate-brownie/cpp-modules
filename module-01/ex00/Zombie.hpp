/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:48:55 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/26 18:10:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie(std::string name);
  ~Zombie();

  void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif