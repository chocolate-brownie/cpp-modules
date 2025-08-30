/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:07:34 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/30 19:01:43 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Harl harlFilter;
  if (argc != 2)
    return (std::cout << "Usage: ./harlFilter <levels> " << std::endl, 0);

  std::string arg1(argv[1]);
  harlFilter.complain(arg1);

  return 0;
}