#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void test_regular_animals() {
   std::cout << "\n=== Testing Regular Animals ===\n" << std::endl;
   
   const Animal* meta = new Animal();
   const Animal* dog = new Dog();
   const Animal* cat = new Cat();
   
   std::cout << "\nTesting Types:" << std::endl;
   std::cout << "Dog type: " << dog->getType() << std::endl;
   std::cout << "Cat type: " << cat->getType() << std::endl;
   std::cout << "Base type: " << meta->getType() << std::endl;
   
   std::cout << "\nTesting Sounds:" << std::endl;
   dog->makeSound();
   cat->makeSound();
   meta->makeSound();
   
   std::cout << "\nTesting Delete:" << std::endl;
   delete meta;
   delete dog;
   delete cat;
}

void test_wrong_animals() {
    std::cout << "\n=== Testing Wrong Animals ===\n" << std::endl;
    
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    // Add copy test
    WrongCat original_wrong_cat;
    WrongCat copied_wrong_cat(original_wrong_cat);
    
    std::cout << "\nTesting Types:" << std::endl;
    std::cout << "WrongCat type: " << wrong_cat->getType() << std::endl;
    std::cout << "Wrong base type: " << wrong_meta->getType() << std::endl;
    
    std::cout << "\nTesting Sounds:" << std::endl;
    wrong_cat->makeSound();
    wrong_meta->makeSound();
    
    delete wrong_meta;
    delete wrong_cat;
}
void test_copy_constructor() {
   std::cout << "\n=== Testing Copy Constructors ===\n" << std::endl;
   
   std::cout << "Creating original objects:" << std::endl;
   Cat original_cat;
   Dog original_dog;
   
   std::cout << "\nTesting Cat copy:" << std::endl;
   Cat copied_cat(original_cat);
   copied_cat.makeSound();
   
   std::cout << "\nTesting Dog copy:" << std::endl;
   Dog copied_dog(original_dog);
   copied_dog.makeSound();
}

void test_assignment_operator() {
   std::cout << "\n=== Testing Assignment Operators ===\n" << std::endl;

   Cat cat1, cat2;
   Dog dog1, dog2;

   std::cout << "\nTesting Cat assignment:" << std::endl;
   cat2 = cat1;
   cat2.makeSound();

   std::cout << "\nTesting Dog assignment:" << std::endl;
   dog2 = dog1;
   dog2.makeSound();
}

int main() {
   test_regular_animals();
   test_wrong_animals();
   test_copy_constructor();
   test_assignment_operator();

   return 0;
}
