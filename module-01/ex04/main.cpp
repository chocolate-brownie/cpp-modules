/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:06:00 by mgodawat          #+#    #+#             */
/*   Updated: 2025/08/28 21:19:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  (void)argv;
  if (argc != 4) {
    std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
    return 1;
  }

  /** Read data from a file */
  std::ifstream inputfile(argv[1]);
  if (!inputfile.is_open()) {
    std::cout << "[Error]: Failed to open the file" << std::endl;
    return 1;
  }

  /** Copy the content from the file to a string and close the file*/
  std::stringstream buffer;
  buffer << inputfile.rdbuf();
  std::string fileContent = buffer.str();
  inputfile.close();

  /** Find the s1 in the string fileContent, replace it with s2 and create
  a while new string called newContent */
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  std::string newContent = "";

  size_t findPos;
  size_t lastPos = 0;

  while ((findPos = fileContent.find(s1, lastPos)) != std::string::npos) {
    newContent += fileContent.substr(lastPos, findPos - lastPos);
    newContent += s2;
    lastPos = findPos + s1.length();
  }

  newContent += fileContent.substr(lastPos);

  /** Write data a new file */
  std::string newFileName = std::string(argv[1]) + ".replace";
  std::ofstream outFile(newFileName.c_str());
  if (!outFile.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
    return 1;
  }
  outFile << newContent;
  outFile.close();

  return (0);
}
