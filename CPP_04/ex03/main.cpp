// main.cpp
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	// Additional tests
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");  // Should print inventory full
	me->equip(tmp);
	delete tmp;  // Clean up unequipped materia

	me->use(0, *bob);  // ice
	me->use(1, *bob);  // cure
	me->use(2, *bob);  // ice
	me->use(3, *bob);  // cure
	me->use(4, *bob);  // Should do nothing - invalid index

	me->unequip(0);    // Test unequip
	me->use(0, *bob);  // Should do nothing - empty slot

	delete bob;
	delete me;
	delete src;

	return 0;
}
