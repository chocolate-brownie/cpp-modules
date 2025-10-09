#ifndef DATA_HPP
#define DATA_HPP

#include <string>

// This structure is a simple container for data.
// Its only purpose is to be the target for our serialization and
// deserialization test.
struct Data {
    std::string name;
    int value;
};

#endif
