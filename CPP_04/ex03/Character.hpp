#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		int size;
		AMateria* dropped[100];
		int dropCount;

	public:
		Character(const std::string& name);
		Character(const Character& other);
		virtual ~Character();
		Character& operator=(const Character& other);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
