/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:21:27 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/26 20:55:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

private:
	std::string _name;

public:
	Zombie(void);
	~Zombie(void);

	void	setName(std::string name);
	void	announce(void);

};

Zombie*	zombieHorde(int N, std::string name);

#endif