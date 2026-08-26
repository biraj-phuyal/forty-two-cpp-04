#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

static void testCorrectAnimals(void) {
	std::cout << "\n=== Correct polymorphism ===" << std::endl;
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();

	delete cat;
	delete dog;
	delete meta;
}

static void testWrongAnimals(void) {
	std::cout << "\n=== Wrong polymorphism ===" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " through a WrongAnimal pointer: ";
	wrongCat->makeSound();
	std::cout << wrongMeta->getType() << ": ";
	wrongMeta->makeSound();

	delete wrongCat;
	delete wrongMeta;
}

static void testCopies(void) {
	std::cout << "\n=== Copy and assignment ===" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	Cat originalCat;
	Cat assignedCat;

	assignedCat = originalCat;
	std::cout << copiedDog.getType() << ": ";
	copiedDog.makeSound();
	std::cout << assignedCat.getType() << ": ";
	assignedCat.makeSound();
}

int main(void) {
	testCorrectAnimals();
	testWrongAnimals();
	testCopies();
	return (0);
}
