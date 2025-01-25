#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : count(0)
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete templates[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete templates[i];
			templates[i] = NULL;
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
		}
		count = other.count;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m || count >= 4) return;
	templates[count++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < count; i++) {
		if (templates[i]->getType() == type)
			return templates[i]->clone();
	}
	return NULL;
}
