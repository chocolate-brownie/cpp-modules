/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:13:45 by mgodawat          #+#    #+#             */
/*   Updated: 2025/09/01 14:13:52 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>

bool readFileContent(const std::string &filename, std::string &content) {
  std::ifstream inputFile(filename.c_str());
  if (!inputFile.is_open()) {
    std::cerr << "[Error]: Failed to open input file: " << filename
              << std::endl;
    return (false);
  }
  std::stringstream buffer;
  buffer << inputFile.rdbuf();
  content = buffer.str();
  inputFile.close();
  return (true);
}

std::string replaceContent(const std::string &content, const std::string &s1,
                           const std::string &s2) {
  std::string newContent = "";
  size_t lastPos = 0;
  size_t findPos;

  while ((findPos = content.find(s1, lastPos)) != std::string::npos) {
    newContent += content.substr(lastPos, findPos - lastPos);
    newContent += s2;
    lastPos = findPos + s1.length();
  }
  newContent += content.substr(lastPos);
  return (newContent);
}

bool writeFileContent(const std::string &filename, const std::string &content) {
  std::ofstream outFile(filename.c_str());
  if (!outFile.is_open()) {
    std::cerr << "[Error]: Failed to create output file: " << filename
              << std::endl;
    return (false);
  }
  outFile << content;
  outFile.close();
  return (true);
}