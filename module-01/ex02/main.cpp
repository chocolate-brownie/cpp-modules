#include <iostream>
#include <string>

int main(void) {

  std::string stringVAR = "HI THIS IS BRAIN";
  std::string *stringPTR = &stringVAR;
  std::string &stringREF = stringVAR;

  std::cout << "Memory address of the string variable: " << &stringVAR
            << std::endl;
  std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

  std::cout << "The value of the string variable: " << stringVAR << std::endl;
  std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

  return 0;
}
