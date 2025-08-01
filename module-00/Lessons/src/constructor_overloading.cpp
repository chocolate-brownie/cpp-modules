#include <iomanip>
#include <iostream>

int main() {
  // Table header
  std::cout << std::setw(15) << std::left << "Name" << std::setw(10)
            << std::right << "Age" << std::endl;

  // Table separator
  std::cout << std::setw(15) << std::setfill('-') << "" << std::setw(10) << ""
            << std::setfill(' ') << std::endl;

  // Table rows
  std::cout << std::setw(15) << std::left << "Alice" << std::setw(10)
            << std::right << 23 << std::endl;

  std::cout << std::setw(15) << std::left << "Bob" << std::setw(10)
            << std::right << 31 << std::endl;

  std::cout << std::setw(15) << std::left << "Charlie" << std::setw(10)
            << std::right << 18 << std::endl;

  return 0;
}
