#pragma once
#include"util.hpp"
#include"gameplayHUD.hpp"
#include"combat.hpp"
#include"promotions.hpp"
class Game{
private:
	//Create Classes
	RenderWindow window;
	Event event, action;
	MainMenu mainmenu;
	Difficulty difficulty;
	ClassSelect classselect;
	RenderStage renderstage;
	//Create players/enemies
	Swordsman swords;
	Archer arch;
	Wizard wiz;
	Goblin goblin;
	Orc orc;
	Vanguard vanguard;
	Bane bane;
	Combat combat;
	WinLose winlose;
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
		bool inPromotion1 = false;
		bool inPromotion2 = false;
		bool inPromotion3 = false;
	bool inWin = false;
	bool inLose = false;
	//Initialization
	void initWindow();

public:
	Game();
	~Game(){}

	void run();
};
