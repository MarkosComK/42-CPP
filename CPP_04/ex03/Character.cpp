#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) :
	name(name),
	size(0),
	dropCount(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		dropped[i] = NULL;
}

Character::Character(const Character& other) : size(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete inventory[i];
	for (int i = 0; i < dropCount; i++)
		delete dropped[i];
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.getName();
		for (int i = 0; i < 4; i++)
		{
			delete inventory[i];
			inventory[i] = NULL;
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
		size = other.size;
	}
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m) return;
	for (int i = 0; i < 4; i++) 
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			size++;
			return;
		}
	}
	std::cout << "Inventory full\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		dropped[dropCount++] = inventory[idx];
		inventory[idx] = NULL;
		size--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}
