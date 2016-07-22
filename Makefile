CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD -g
OBJECTS = main.o controller.o inputvalidation.o view.o textdisplay.o graphicdisplay.o window.o player.o human.o computer.o board.o piece.o king.o queen.o rook.o knight.o bishop.o pawn.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = chess

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
