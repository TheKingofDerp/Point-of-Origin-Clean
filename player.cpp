#include"player.hpp"

Player::Player(){}
Player::~Player(){}

Swordsman::Swordsman(){
	hp = maxhp = 100;
	energy = 0;
	dmg = 25;
	def = 20;
	maxenergy = 100;
	name = "Swordsman";
	ability1 = "Double Strike";
	ability2 = "Heavy Blow";
        ability3 = "Fortify";
        ab1desc = "Do 2x DMG. Cost: 20 Energy";
        ab2desc = "Do 4x DMG. Cost: 60 Energy";
        ab3desc = "+25 HP. Cost: 25 Energy";

}
void Player::resetStats(Player & s, Player & a, Player & w){
	s.hp = a.hp = w.hp = s.maxhp = a.maxhp = w.maxhp = 100;
        s.energy = a.energy = w.energy = 0;
        s.maxenergy = a.maxenergy = w.maxenergy = 100;
}

void Player::setDiffStats(Player & s, Player & a, Player & w, int diff){
	switch(diff){
		//Easy
		case 1:
			s.hp = a.hp = w.hp = s.maxhp = a.maxhp = w.maxhp = 125;
			a.def = 15;
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
			a.def = 15;
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
	hp = maxhp = 100;
	energy = 0;
	dmg = 35;
	def = 15;
	maxenergy = 100;
	name = "Archer";	
	ability1 = "Volley"; 
	ability2 = "Heavy Precision Arrow";
        ability3 = "Rapid Fire";
        ab1desc = "Deal 2x DMG. Cost: 20 Energy";
        ab2desc = "Deal 3x DMG. 1/4 Chance to instakill. Cost: 60 Energy";
        ab3desc = "Basic Attack 3x and +10HP. Cost: 25 Energy";
}

Archer::~Archer(){}

Wizard::Wizard(){
	hp = maxhp = 100;
	energy = 0;
	dmg = 40;
	def = 10;
	name = "Wizard";
	maxenergy = 100;
	ability1 = "Fireball";
	ability2 = "Primordial Burst";
        ability3 = "Stun";
        ab1desc = "Do 2x DMG. Cost: 20 Energy";
        ab2desc = "Do 3x DMG and enemy DMG and DEF -2. Cost: 60 Energy ";
        ab3desc = "+10 HP and Enemy DMG and DEF -1. Cost: 25 Energy";
}

Wizard::~Wizard(){}

void Player::drawPlayerStats(RenderWindow & window, Player & p){
	font.loadFromFile("fonts/defused.ttf");
	stats = string(toString<int>(p.getHP())) + string("/") + string(toString<int>(p.getMaxHP())) + string("\n\n") + string(toString<int>(p.getDMG())) + string("\n\n") + string(toString<int>(p.getDEF())) + string("\n\n") + string(toString<int>(p.getEnergy())) + string("/") + string(toString<int>(p.getMaxEnergy()));
	pTxt.setString(stats);
	pTxt.setFont(font);
	pTxt.setCharacterSize(16);
	pTxt.setFillColor(Color::Green);
	pTxt.setPosition(675,410);
	window.draw(pTxt);
}

void Player::basicAtk(Player & p, Enemy & e){
        int truePDMG = p.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - p.getDEF();
        int truePHP = p.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        if(p.getDMG() > e.getDEF()){
                if(trueEHP <= 0)
                        e.setHP(0);
                else
                        e.setHP(trueEHP);
        }
        if(e.getDMG() > p.getDEF()){
                if(truePHP <= 0)
                        p.setHP(0);
                else
                        p.setHP(truePHP);
        }
        if(p.getEnergy() <= p.getMaxEnergy()){
                if((p.getEnergy() + 10) >= p.getMaxEnergy())
                        p.setEnergy(p.getMaxEnergy());
                else
                        p.setEnergy(p.getEnergy() + 10);
        }
}

void Swordsman::abil1(Swordsman & s, Enemy & e){
	int truePDMG = 2 * s.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - s.getDEF();
        int truePHP = s.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
	if(s.getEnergy() >= 20){
		if(truePDMG > 0){
                        if(trueEHP <= 0)
                                e.setHP(0);
                        else
                                e.setHP(trueEHP);
                }
                if(trueEDMG > 0){
                        if(truePHP <= 0)
                                s.setHP(0);
                        else
                                s.setHP(truePHP);
                }
                s.setEnergy(s.getEnergy() - 20);
	}
}
void Archer::abil1(Archer & a, Enemy & e){
        int truePDMG = 2 * a.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - a.getDEF();
        int truePHP = a.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        if(a.getEnergy() >= 20){
                if(truePDMG > 0){
                        if(trueEHP <= 0)
                                e.setHP(0);
                        else
                                e.setHP(trueEHP);
                }
                if(trueEDMG > 0){
                        if(truePHP <= 0)
                                a.setHP(0);
                        else
                                a.setHP(truePHP);
                }
                a.setEnergy(a.getEnergy() - 20);
        }

}
void Wizard::abil1(Wizard & w, Enemy & e){
        int truePDMG = 2 * w.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - w.getDEF();
        int truePHP = w.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        if(w.getEnergy() >= 20){
                if(truePDMG > 0){
                        if(trueEHP <= 0)
                                e.setHP(0);
                        else
                                e.setHP(trueEHP);
                }
                if(trueEDMG > 0){
                        if(truePHP <= 0)
                                w.setHP(0);
                        else
                                w.setHP(truePHP);
                }
                w.setEnergy(w.getEnergy() - 20);
        }

}
void Swordsman::abil2(Swordsman & s, Enemy & e){
        int truePDMG = 4 * s.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - s.getDEF();
        int truePHP = s.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        if(s.getEnergy() >= 60){
                if(truePDMG > 0){
                        if(trueEHP <= 0)
                                e.setHP(0);
                        else
                                e.setHP(trueEHP);
                }
                if(trueEDMG > 0){
                        if(truePHP <= 0)
                                s.setHP(0);
                        else
                                s.setHP(truePHP);
                }
                s.setEnergy(s.getEnergy() - 60);
        }

}
void Archer::abil2(Archer & a, Enemy & e){
        int truePDMG = 4 * a.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - a.getDEF();
        int truePHP = a.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        srand(time(0));
	int x = 1;
	int y = rand()%3;
	cout<<x<<y<<endl;
	if(a.getEnergy() >= 60){
                if(truePDMG > 0){
                        if(trueEHP <= 0 || x == y)
                                e.setHP(0);
                        else
                                e.setHP(trueEHP);
                }
                if(trueEDMG > 0){
                        if(truePHP <= 0)
                                a.setHP(0);
                        else
                                a.setHP(truePHP);
                }
                a.setEnergy(a.getEnergy() - 60);
        }

}
void Wizard::abil2(Wizard & w, Enemy & e){
        int truePDMG = 3 * w.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - w.getDEF();
        int truePHP = w.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        if(w.getEnergy() >= 60){
                if(truePDMG > 0){
                        if(trueEHP <= 0)
                                e.setHP(0);
                        else
                                e.setHP(trueEHP);
                }
                if(trueEDMG > 0){
                        if(truePHP <= 0)
                                w.setHP(0);
                        else
                                w.setHP(truePHP);
                }
		e.setDEF(e.getDEF() - 2);
		e.setDMG(e.getDMG() - 2);
                w.setEnergy(w.getEnergy() - 50);
        }

}
void Swordsman::abil3(Swordsman & s, Enemy & e){
	if(s.getEnergy() >= 25){
                        if((s.getHP() + 25) >= s.getMaxHP())
				s.setHP(s.getMaxHP());
			else
				s.setHP(s.getHP() + 25);
        }
		s.setEnergy(s.getEnergy() - 25);
}
void Archer::abil3(Archer & a, Enemy & e){
        int truePDMG = a.getDMG() - e.getDEF();
        int trueEHP = e.getHP() - truePDMG;	
	if(a.getEnergy() >= 25){
		a.setEnergy(a.getEnergy() - 25);
		for(int i = 0; i < 3; i++){
			e.setHP(trueEHP);
		}
		if((a.getHP() + 10) >= a.getMaxHP())
			a.setHP(maxhp);
		else
			a.setHP(a.getHP() + 10);
	}
}
void Wizard::abil3(Wizard & w, Enemy & e){
	if(w.getEnergy() >= 25){
		if((w.getHP() + 10) >= w.getMaxHP())
			w.setHP(maxhp);
		else
			w.setHP(w.getHP() + 10);
		e.setDMG(e.getDMG() - 1);
		e.setDEF(e.getDEF() - 1);
		w.setEnergy(w.getEnergy() - 25);
	}
}
