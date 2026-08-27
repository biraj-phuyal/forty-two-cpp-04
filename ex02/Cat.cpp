#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal(), brain(new Brain()) {
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(unsigned int index, const std::string &idea) {
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(unsigned int index) const {
	return (brain->getIdea(index));
}
