parametrosCompilacao=-Wall -std=c++20
parametrosBoost =
gg=gg

OBJ = main.o Game.o UserInterface.o

all: $(gg)

$(gg): $(OBJ)
	g++ -o $(gg) $(OBJ) $(parametrosCompilacao) $(parametrosBoost)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp $(parametrosCompilacao)

UserInterface.o: UserInterface.cpp UserInterface.hpp
	g++ -c UserInterface.cpp $(parametrosCompilacao)

run:
	./$(gg)

clean:
	rm -f *.o *.gch $(gg)
