#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main() {
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    // i->makeSound();
    // j->makeSound();

    Cat cat;
    cat.setIdea(0, "Hello");
    cat.setIdea(1, "Human");
    cat.setIdea(2, "Person");
    for (int i = 0; i < 3; i++) {
        cat.printIdea(i);
    }

    // meta->makeSound();

    /*
        std::cout << std::endl << "--- WrongAnimal class test ----" <<
       std::endl; const WrongAnimal* wrongMeta = new WrongAnimal(); const
       WrongAnimal* k = new WrongCat();


        std::cout << k->getType() << " (Type)" << std::endl;

        k->makeSound();
        wrongMeta->makeSound();
     */
    std::cout << std::endl << "--- Deleting Animals ---" << std::endl;
    // delete meta;
    delete j;
    delete i;
    /*
        std::cout << std::endl << "--- Deleting WrongAnimals ---" << std::endl;
        delete wrongMeta;
        delete k;
     */
    return 0;
}
