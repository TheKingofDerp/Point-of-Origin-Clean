POO: precomp
	g++ -c main.cpp game.cpp menu.cpp
	g++ main.o game.o menu.o -o point -lsfml-graphics -lsfml-window -lsfml-system
	./point

precomp:
	touch point
	rm point

clean: 
	rm *.o

run:
	./point
