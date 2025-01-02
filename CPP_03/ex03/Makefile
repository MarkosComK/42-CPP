NAME = diamondtrap
SRCS = ClapTrap.cpp main.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm ${NAME}

re: clean all
