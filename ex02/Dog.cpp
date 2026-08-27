#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal(), brain(new Brain()) {
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const {
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(unsigned int index, const std::string &idea) {
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(unsigned int index) const {
	return (brain->getIdea(index));
}
