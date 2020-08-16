#pragma once
#include"util.hpp"
#include"player.hpp"
#include"menu.hpp"
//Base promotion class
class Promotion{
private:
	Text title;
	Text pro1, desc1, pro2, desc2, pro3, desc3, pro4, desc4, pro5, desc5;
	Font font;
	MainMenu mainmenu;
public:
	Promotion();
	~Promotion(){}
	void drawPromotion(RenderWindow & window);
	void promote1(Player & p);
	void promote2(Player &  p);
	void promote3(Player & p);
	void promote4(Player & p);
	void promote5(Player &  p);
};

