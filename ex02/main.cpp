#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

static void AnimalArray(void) {
	std::cout << "Abstract Animal array " << std::endl;
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
	std::cout << "\n";
}

static void DogCopy(void) {
	std::cout << "Dog copy" << std::endl;
	Dog original;
	original.setIdea(0, "Chase the ball");
	Dog copy(original);

	original.setIdea(0, "Take a nap");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;
	std::cout << "\n";
}

static void DogAssignment(void) {
	std::cout << "Dog assignment" << std::endl;
	Dog original;
	original.setIdea(0, "Chase the ball");
	Dog copy;

	copy = original;
	original.setIdea(0, "Take a nap");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Assigned idea: " << copy.getIdea(0) << std::endl;
	std::cout << "\n";
}

static void CatCopy(void) {
	std::cout << "Cat copy" << std::endl;
	Cat original;
	original.setIdea(0, "Climb the curtains");
	Cat copy(original);

	original.setIdea(0, "Sit in a box");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copied idea:   " << copy.getIdea(0) << std::endl;
	std::cout << "\n";
}

static void CatAssignment(void) {
	std::cout << "Cat assignment" << std::endl;
	Cat original;
	original.setIdea(0, "Climb the curtains");
	Cat copy;

	copy = original;
	original.setIdea(0, "Sit in a box");
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Assigned idea: " << copy.getIdea(0) << std::endl;
	std::cout << "\n";
}

int main(void) {
	// Animal animal; // Does not compile: Animal is abstract.
	AnimalArray();
	DogCopy();
	DogAssignment();
	CatCopy();
	CatAssignment();
	return (0);
}
