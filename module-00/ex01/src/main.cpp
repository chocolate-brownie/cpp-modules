/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:19:38 by mgodawat          #+#    #+#             */
/*   Updated: 2025/07/24 13:51:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace	std;

void	ftPutStr(const string src)
{
	if (!src.empty())
		cout << src << endl;
	else
		cout << "ftPutstr: param cannot be NULL" << endl;
	return ;
}

int	main(void)
{
    ftPutStr(NULL);
	return (0);
}