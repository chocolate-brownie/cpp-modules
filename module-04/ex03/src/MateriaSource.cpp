#include "../include/MateriaSource.hpp"
#include <iostream>

/* ************************************************************************** */
/* */
/* Orthodox Canonical Form */
/* */
/* ************************************************************************** */
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _template[i] = 0;
};

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other._template[i])
            _template[i] = other._template[i]->clone();
        else
            _template[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {

    if (this != &other) {
        for (int i = 0; i < 4; ++i)
            delete _template[i];

        for (int i = 0; i < 4; i++) {
            if (other._template[i])
                _template[i] = other._template[i]->clone();
            else
                _template[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete _template[i];
}

/* ************************************************************************** */
/* */
/* Member functions */
/* */
/* ************************************************************************** */
void MateriaSource::learnMateria(AMateria* m) {
    if (m == 0) {
        std::cout << "Error: learnMateria(0) is not valid" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (_template[i] == 0) {
            _template[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; ++i) {
        if (_template[i] != 0 && _template[i]->getType() == type)
            return _template[i]->clone();
    }
    return 0;
}
