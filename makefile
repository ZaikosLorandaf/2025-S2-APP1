CC = g++
SRC = canevas.cpp couche.cpp forme.cpp graphicus-02.cpp tests.cpp rectangle.cpp carre.cpp cercle.cpp
OBJ = ${SRC:.cpp=.o}
CFLAGS = -Wall -Os -march=native

all: Graphicus

.o: %.cpp
	${CC} -c ${CFLAGS} ${SRC} $<

Graphicus: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o Graphicus

clean:
	rm -f ${OBJ}

