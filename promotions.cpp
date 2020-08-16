#include"promotions.hpp"

Promotion::Promotion(){
	font.loadFromFile("fonts/defused.ttf");
	pro1.setFont(font);
	pro2.setFont(font);
	pro3.setFont(font);
	pro4.setFont(font);
	pro5.setFont(font);
        desc1.setFont(font);
        desc2.setFont(font);
        desc3.setFont(font);
        desc4.setFont(font);
        desc5.setFont(font);
	title.setFont(font);
	pro1.setString("1) Endurance");
	pro2.setString("2) Shield Hardening");
	pro3.setString("3) Focus");
	pro4.setString("4) Lethality");
	pro5.setString("5) Health Potion");
        desc1.setString("+25 Energy and Max Energy");
        desc2.setString("+3 DEF");
        desc3.setString("+2 DMG + 1 DEF");
        desc4.setString("+4 DMG");
        desc5.setString("+15 HP and Max HP");
	title.setString("Choose a Promotion");
	title.setCharacterSize(60);
	pro1.setCharacterSize(36);
	pro2.setCharacterSize(36);
        pro3.setCharacterSize(36);
        pro4.setCharacterSize(36);
        pro5.setCharacterSize(36);
        desc1.setCharacterSize(24);
        desc2.setCharacterSize(24);
        desc3.setCharacterSize(24);
        desc4.setCharacterSize(24);
        desc5.setCharacterSize(24);
	title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
        pro1.setOrigin(pro1.getLocalBounds().width/2, pro1.getLocalBounds().height/2);
        pro2.setOrigin(pro2.getLocalBounds().width/2, pro2.getLocalBounds().height/2);
        pro3.setOrigin(pro3.getLocalBounds().width/2, pro3.getLocalBounds().height/2);
        pro4.setOrigin(pro4.getLocalBounds().width/2, pro4.getLocalBounds().height/2);
        pro5.setOrigin(pro5.getLocalBounds().width/2, pro5.getLocalBounds().height/2);
        desc1.setOrigin(desc1.getLocalBounds().width/2, desc1.getLocalBounds().height/2);
        desc2.setOrigin(desc2.getLocalBounds().width/2, desc2.getLocalBounds().height/2);
        desc3.setOrigin(desc3.getLocalBounds().width/2, desc3.getLocalBounds().height/2);
        desc4.setOrigin(desc4.getLocalBounds().width/2, desc4.getLocalBounds().height/2);
        desc5.setOrigin(desc5.getLocalBounds().width/2, desc5.getLocalBounds().height/2);
	title.setPosition(WindowWidth/2, WindowHeight/7);
	pro1.setPosition(WindowWidth/2, WindowHeight*2/7);
        pro2.setPosition(WindowWidth/2, WindowHeight*3/7);
        pro4.setPosition(WindowWidth/2, WindowHeight*4/7);
        pro3.setPosition(WindowWidth/2, WindowHeight*5/7);
        pro5.setPosition(WindowWidth/2, WindowHeight*6/7);
        desc1.setPosition(WindowWidth/2, WindowHeight*2/7 + 40);
        desc2.setPosition(WindowWidth/2, WindowHeight*3/7 + 40);
        desc4.setPosition(WindowWidth/2, WindowHeight*4/7 + 40);
        desc3.setPosition(WindowWidth/2, WindowHeight*5/7 + 40);
        desc5.setPosition(WindowWidth/2, WindowHeight*6/7 + 40);
	title.setFillColor(ORANGE);
	pro1.setFillColor(ORANGE);
	pro2.setFillColor(ORANGE);
	pro3.setFillColor(ORANGE);
	pro4.setFillColor(ORANGE);
	pro5.setFillColor(ORANGE);
	desc1.setFillColor(ORANGE);
	desc2.setFillColor(ORANGE);
	desc3.setFillColor(ORANGE);
	desc4.setFillColor(ORANGE);
	desc5.setFillColor(ORANGE);
}

void Promotion::drawPromotion(RenderWindow & window){
	window.clear();
	mainmenu.drawBGopaque(window);
	window.draw(title);
	window.draw(pro1);
	window.draw(pro2);
	window.draw(pro3);
	window.draw(pro4);
	window.draw(pro5);
	window.draw(desc1);
	window.draw(desc2);
	window.draw(desc3);
	window.draw(desc4);
	window.draw(desc5);
	window.display();
}

//Endurace
void Promotion::promote1(Player & p){
	p.setMaxEnergy(p.getMaxEnergy() + 25);
	p.setEnergy(p.getEnergy() + 25);
}
//Shield hardening
void Promotion::promote2(Player & p){
	p.setDEF(p.getDEF() + 3);
}
//Focus
void Promotion::promote3(Player & p){
	p.setDMG(p.getDMG() + 2);
	p.setDEF(p.getDEF() + 1);
}
//Lethality
void Promotion::promote4(Player & p){
	p.setDMG(p.getDMG() + 5);
}
//Health Potion
void Promotion::promote5(Player & p){
	p.setMaxHP(p.getMaxHP() + 15);
	p.setHP(p.getHP() + 15);
}
