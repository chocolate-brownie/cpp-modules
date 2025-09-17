#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();

    meta->makeSound();

    std::cout << std::endl << "--- WrongAnimal class test ----" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();

    std::cout << k->getType() << " (Type)" << std::endl;

    k->makeSound();
    wrongMeta->makeSound();

    std::cout << std::endl << "--- Deleting Animals ---" << std::endl;
    delete meta;
    delete j;
    delete i;
    std::cout << std::endl << "--- Deleting WrongAnimals ---" << std::endl;
    delete wrongMeta;
    delete k;

    return 0;
}
