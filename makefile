Cones: Weapon.o Character.o main.o
	g++ Weapon.o Character.o main.o -o cone

main.o: main.cpp
	g++ -c main.cpp

Character.o: Character.h Character.cpp
	g++ -c Character.cpp

Weapon.o: Weapon.h Weapon.cpp
	g++ -c Weapon.cpp

clean:
	rm -f *.o cone

