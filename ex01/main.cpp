#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

static void AnimalArray(void) {
	const int animalCount = 10;
	Animal *animals[animalCount];

	for (int i = 0; i < animalCount; i++) {
		if (i < animalCount / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < animalCount; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < animalCount; i++)
		delete animals[i];
}

static void DogCopy(void) {
	Dog original;
	original.setIdea(0, "Chase the ball");
	Dog copy(original);

	original.setIdea(0, "Take a nap");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;
}

static void DogAssignment(void) {
	Dog original;
	original.setIdea(0, "Chase the ball");
	Dog copy;

	copy = original;
	original.setIdea(0, "Take a nap");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Assigned idea: " << copy.getIdea(0) << std::endl;
}

static void CatCopy(void) {
	Cat original;
	original.setIdea(0, "Climb the curtains");
	Cat copy(original);

	original.setIdea(0, "Sit in a box");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;
}

static void CatAssignment(void) {
	Cat original;
	original.setIdea(0, "Climb the curtains");
	Cat copy;

	copy = original;
	original.setIdea(0, "Sit in a box");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Assigned idea: " << copy.getIdea(0) << std::endl;
}

int main(void) {
	AnimalArray();
	DogCopy();
	DogAssignment();
	CatCopy();
	CatAssignment();
	return (0);
}
