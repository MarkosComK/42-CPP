NAME = scavtrap
SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm ${NAME}

re: clean all
