#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

static void CorrectAnimals(void) {
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

static void WrongAnimals(void) {
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	const WrongCat directWrongCat;

	std::cout << wrongCat->getType() << " through a WrongAnimal pointer: ";
	wrongCat->makeSound();
	std::cout << directWrongCat.getType() << " directly: ";
	directWrongCat.makeSound();
	std::cout << wrongMeta->getType() << ": ";
	wrongMeta->makeSound();

	delete wrongCat;
	delete wrongMeta;
}

static void Copies(void) {
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
	CorrectAnimals();
	WrongAnimals();
	Copies();
	return (0);
}
