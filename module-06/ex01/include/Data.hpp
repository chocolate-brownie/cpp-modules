#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
  private:
    Data();
    Data(const Data&);
    Data& operator=(const Data&);
    ~Data();

  public:
    std::string s1;
    int n;
};

#endif
