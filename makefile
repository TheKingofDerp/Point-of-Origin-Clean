POO: precomp
	g++ -c main.cpp game.cpp menu.cpp gameplayHUD.cpp player.cpp enemy.cpp combat.cpp 
	g++  main.o game.o menu.o gameplayHUD.o player.o enemy.o combat.o -o point -lsfml-graphics -lsfml-window -lsfml-system
	./point

precomp:
	touch point
	rm point

clean: 
	rm *.o

run:
	./point
