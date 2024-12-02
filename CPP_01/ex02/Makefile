NAME = teste
FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp

all: ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm ${NAME}

re: clean all
	c++ ${FLAGS} ${SRCS} -o ${NAME}
