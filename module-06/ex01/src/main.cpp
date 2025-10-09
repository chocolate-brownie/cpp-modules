#include "../include/Data.hpp"
#include "../include/Serializer.hpp"
#include <iostream>

int main() {
    // 1. Create an instance of Data on the heap and initialize it.
    Data* originalPtr = new Data;
    originalPtr->name = "42";
    originalPtr->value = 42;

    std::cout << "--- Step 1: Original Data ---" << std::endl;
    std::cout << "Original Pointer Address:\t" << originalPtr << std::endl;
    std::cout << "Data content (name):\t" << originalPtr->name << std::endl;
    std::cout << "Data content (value):\t" << originalPtr->value << std::endl;
    std::cout << std::endl;

    // 2. Serialize the pointer to a uintptr_t.
    uintptr_t serializedValue = Serializer::serialize(originalPtr);

    std::cout << "--- Step 2: Serialization ---" << std::endl;
    std::cout << "Serialized to integer:\t" << serializedValue << std::endl;
    std::cout << std::endl;

    // 3. Deserialize the uintptr_t back to a Data pointer.
    Data* deserializedPtr = Serializer::deserialize(serializedValue);

    std::cout << "--- Step 3: Deserialization ---" << std::endl;
    std::cout << "Deserialized Pointer Address:\t" << deserializedPtr
              << std::endl;
    std::cout << "Data content (name):\t" << deserializedPtr->name << std::endl;
    std::cout << "Data content (value):\t" << deserializedPtr->value
              << std::endl;
    std::cout << std::endl;

    // 4. Verify that the round-trip was successful.
    std::cout << "--- Step 4: Verification ---" << std::endl;
    if (originalPtr == deserializedPtr) {
        std::cout << "✅ Success: The original and deserialized pointers are "
                     "the same."
                  << std::endl;
    } else {
        std::cout << "❌ Failure: The pointers do not match." << std::endl;
    }
    std::cout << std::endl;

    delete originalPtr;

    return 0;
}
