#pragma once
#include"util.hpp"
#include"menu.hpp"
#include"player.hpp"
#include"enemy.hpp"
class RenderStage{
private:
	Text stage1, stage2, stage3, stage4;
	Font stagefont;
	float stagewidth, stageheight, finalstageheight, finalstagewidth;
	RectangleShape vert1, vert2, horiz;
        float vertheight, vertwidth, horizheight, horizwidth;
	Text pstats, estats;
	MainMenu mainmenu;
public:
	RenderStage();
	~RenderStage();
	void drawStage1(RenderWindow & window);
        void drawStage2(RenderWindow & window);
        void drawStage3(RenderWindow & window);
        void drawStage4(RenderWindow & window);

};

class RenderPlayerHUD{
private:
	Text player, vs, options, descr;
	Font font;
	float playerWidth, playerHeight;
	float vsWidth, vsHeight;
	string optString;
public:
	RenderPlayerHUD(Player & p);
	RenderPlayerHUD(){}
	~RenderPlayerHUD();
	void drawPlayerHUD(RenderWindow & window);
};

class RenderEnemyHUD{
private:
	Text enemy;
	Font font;
	float enemyWidth, enemyHeight;
public:
	RenderEnemyHUD(Enemy & e);
	~RenderEnemyHUD();
	void drawEnemyHUD(RenderWindow & window);
};
