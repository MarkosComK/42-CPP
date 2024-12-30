NAME = bsp
SRCS = Fixed.cpp main.cpp Point.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm ${NAME}

re: clean all
