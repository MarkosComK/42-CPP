#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void testDeepCopy() {
    std::cout << "\n=== Testing Deep Copy ===\n" << std::endl;
    
    // Create original dog and set some ideas
    Dog originalDog;
    originalDog.setBrainIdea(0, "I love bones!");
    originalDog.setBrainIdea(1, "Must chase tail!");
    
    // Create a copy using copy constructor
    Dog copyDog(originalDog);
    
    // Create another dog and use assignment operator
    Dog assignDog;
    assignDog = originalDog;
    
    // Modify original dog's ideas
    originalDog.setBrainIdea(0, "Modified idea!");
    
    // Print all dogs' ideas to verify deep copy
    std::cout << "Original dog's idea: " << originalDog.getBrainIdea(0) << std::endl;
    std::cout << "Copy dog's idea: " << copyDog.getBrainIdea(0) << std::endl;
    std::cout << "Assigned dog's idea: " << assignDog.getBrainIdea(0) << std::endl;
    
    // Same test for cats
    Cat originalCat;
    originalCat.setBrainIdea(0, "I love fish!");
    Cat copyCat(originalCat);
    Cat assignCat = originalCat;
    
    originalCat.setBrainIdea(0, "Modified cat idea!");
    
    std::cout << "Original cat's idea: " << originalCat.getBrainIdea(0) << std::endl;
    std::cout << "Copy cat's idea: " << copyCat.getBrainIdea(0) << std::endl;
    std::cout << "Assigned cat's idea: " << assignCat.getBrainIdea(0) << std::endl;
}

void testArrayOfAnimals() {
    std::cout << "\n=== Testing Array of Animals ===\n" << std::endl;
    
    const int arraySize = 4;  // Make it even for half dogs, half cats
    Animal* animals[arraySize];
    
    // Fill array with dogs and cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
            std::cout << "Created Dog " << i << std::endl;
        } else {
            animals[i] = new Cat();
            std::cout << "Created Cat " << i << std::endl;
        }
    }
    
    // Make them make sounds
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " makes sound: ";
        animals[i]->makeSound();
    }
    
    // Delete all animals
    std::cout << "\nDeleting all animals..." << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
}

void testBasicFunctionality() {
    std::cout << "\n=== Testing Basic Functionality ===\n" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    j->makeSound();
    i->makeSound();
    
    delete j;
    delete i;
}

int main() {
    std::cout << "Starting Animal Class Tests\n" << std::endl;
    
    // Test 1: Basic functionality test
    testBasicFunctionality();
    
    // Test 2: Deep copy test
    testDeepCopy();
    
    // Test 3: Array of animals test
    testArrayOfAnimals();
    
    std::cout << "\nAll tests completed.\n" << std::endl;
    
    // Optional: Test for memory leaks
    // You can run this program with valgrind to check for memory leaks:
    // valgrind --leak-check=full ./your_program
    
    return 0;
}
