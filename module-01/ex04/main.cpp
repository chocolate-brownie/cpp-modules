/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:06:00 by mgodawat          #+#    #+#             */
/*   Updated: 2025/09/01 14:14:23 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
    return (1);
  }

  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  if (s1.empty()) {
    std::cout << "[Error]: The string to be replaced (s1) cannot be empty."
              << std::endl;
    return (1);
  }

  std::string fileContent;
  if (!readFileContent(filename, fileContent)) {
    return (1);
  }

  std::string newContent = replaceContent(fileContent, s1, s2);

  std::string newFileName = filename + ".replace";
  if (!writeFileContent(newFileName, newContent)) {
    return (1);
  }

  return (0);
}