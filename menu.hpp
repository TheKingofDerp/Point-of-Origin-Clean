#pragma once
#include"util.hpp"

class MainMenu{
private:
        Text title, start, exit;
        Font font;
        Texture bg;
        Sprite bg1;
public:
	MainMenu();
	~MainMenu(){}
	void drawMainMenu(RenderWindow & window);
	void runEmpty(RenderWindow & window, Event & event);
	void drawBG(RenderWindow & window);
	void drawBGopaque(RenderWindow & window);
};

class Difficulty{
private:
        Text difftext;
        Font difffont;
	MainMenu mainmenu;
public:
        Difficulty();
        ~Difficulty(){}
        void render(RenderWindow & window);
};

class ClassSelect{
private:
        Text select, swordsman, archer, wizard, back;
        Font ClassSelectFont;
	MainMenu mainmenu;
        float swordsmanwidth, swordsmanheight, archerwidth, archerheight;
        float wizardwidth, wizardheight;
        float backwidth, backheight, selectwidth, selectheight;
public:
        ClassSelect();
        ~ClassSelect(){}
        void render(RenderWindow & window);

};

class WinLose{
private:
	Text win, lose, menu;
	Font font;
public:
	WinLose();
	~WinLose(){}
	void drawWin(RenderWindow & window);
	void drawLose(RenderWindow & window);
};
