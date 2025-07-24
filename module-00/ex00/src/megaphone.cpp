/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:04:22 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/23 20:36:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <iostream>

std::string toUpper(const std::string &input)
{
	std::string result = input;
	for (size_t i = 0; i < result.size(); ++i)
	{
		if (std::isalpha(result[i]))
			result[i] = std::toupper(result[i]);
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
		std::cout << toUpper(argv[i]);
	std::cout << std::endl;
	return (0);
}