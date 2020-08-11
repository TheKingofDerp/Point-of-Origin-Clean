#include"player.hpp"

Player::Player(){}
Player::~Player(){}

Swordsman::Swordsman(){
	hp = 100;
	energy = 0;
	dmg = 25;
	def = 20;
	maxenergy = 100;
	name = "Swordsman";
	ability1 = "Double Strike";
	ability2 = "Heavy Blow";
}
void Player::resetStats(Player & s, Player & a, Player & w){
	s.hp = a.hp = w.hp = 100;
        s.energy = a.energy = w.energy = 0;
        s.maxenergy = a.maxenergy = w.maxenergy = 100;
}

void Player::setDiffStats(Player & s, Player & a, Player & w, int diff){
	switch(diff){
		//Easy
		case 1:
			s.hp = a.hp = w.hp = 125;
			s.def = 25;
			a.def = 20;
			w.def = 15;
			s.energy = a.energy = w.energy = 25;
			s.maxenergy = a.maxenergy = w.maxenergy = 125;
			break;
		case 2:
			//Default stats;
			break;
		case 3:
			s.dmg = 20;
			s.def = 20;
                        a.dmg = 30;
			a.def = 20;
                        w.dmg = 25;
			w.def = 10;
			s.energy = a.energy = w.energy = 0;
			s.maxenergy = a.maxenergy = w.maxenergy = 125;
			break;
		default:
			break;
	}
}

Swordsman::~Swordsman(){}

Archer::Archer(){
	hp = 100;
	energy = 0;
	dmg = 35;
	def = 15;
	maxenergy = 100;
	name = "Archer";	
	ability1 = "Volley"; 
	ability2 = "Heavy Precision Arrow";
}

Archer::~Archer(){}

Wizard::Wizard(){
	hp = 100;
	energy = 0;
	dmg = 40;
	def = 10;
	name = "Wizard";
	maxenergy = 100;
	ability1 = "Fireball";
	ability2 = "Primordial Burst";
}

Wizard::~Wizard(){}

void Player::drawPlayerStats(RenderWindow & window, Player & p){
	font.loadFromFile("fonts/defused.ttf");
	stats = string(toString<int>(p.getHP())) + string("\n\n") + string(toString<int>(p.getDMG())) + string("\n\n") + string(toString<int>(p.getDEF())) + string("\n\n") + string(toString<int>(p.getEnergy()));
	pTxt.setString(stats);
	pTxt.setFont(font);
	pTxt.setCharacterSize(20);
	pTxt.setFillColor(Color::Green);
	pTxt.setPosition(650,410);
	window.draw(pTxt);
}
