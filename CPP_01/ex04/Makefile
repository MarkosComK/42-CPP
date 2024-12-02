NAME = replace
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp

all: ${NAME}

${NAME}:
	c++ ${FLAGS} ${SRCS} -o ${NAME}

clean:
	rm ${NAME}
	rm *.replace

re: clean all
