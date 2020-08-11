#pragma once
#include"util.hpp"
#include"menu.hpp"
class Game{
private:
	//Create Classes
	RenderWindow window;
	Event event;
	MainMenu mainmenu;
	Difficulty difficulty;
	ClassSelect classselect;
	//inScreen variables
	bool inMenu = true;
	bool inChooseDiff = false;
	bool inClassSelect = false;
	bool inGame = false;
		bool isArch = false;
		bool isSwords = false;
		bool isWiz = false;
		bool inStage1 = false;
		bool inStage2 = false;
		bool inStage3 = false;
		bool inStage4 = false;
	//Initialization
	void initWindow();
	void initStates();
	
public:
	Game();
	~Game(){}

	void run();
};
