NAME = poly
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -f ${NAME}

re: clean all
