#include"combat.hpp"

Combat::Combat(){

}

void Combat::battle(RenderWindow & window, Event & event, Player & p, Enemy & e){
	switch(event.type){
		case Event::Closed:
			window.close();
			break;
		case Event::KeyReleased:
			switch(event.key.code){
				case Keyboard::Num1:
					basicAtk(p, e);
					cout<<"Basic Attack\n";
					break;
				case Keyboard::Num2:
					ability1Atk(p, e);
					cout<<"Ability 1\n";
					break;
				case Keyboard::Num3:
					ability2Atk(p, e);
					cout<<"Ability 2\n";
					break;
				case Keyboard::Num4:
					heal(p);
					cout<<"Heal\n";
					break;
			}
	}

}

void Combat::basicAtk(Player & p, Enemy & e){
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


void Combat::ability1Atk(Player & p, Enemy & e){
        int truePDMG = 2 * p.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - p.getDEF();
        int truePHP = p.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
	cout<<"True PDMG: "<<truePDMG<<"\n";
	cout<<"True EHP: "<<trueEHP<<"\n";
	if(p.getEnergy() >= 20){
		if(truePDMG > 0){
			if(trueEHP <= 0)
				e.setHP(0);
			else
				e.setHP(trueEHP);
		}
		if(trueEDMG > 0){
			if(truePHP <= 0)
				p.setHP(0);
			else
				p.setHP(truePHP);
		}
		p.setEnergy(p.getEnergy() - 20);
	}
}

void Combat::ability2Atk(Player & p, Enemy & e){
        int truePDMG = 4 * p.getDMG() - e.getDEF();
        int trueEDMG = e.getDMG() - p.getDEF();
        int truePHP = p.getHP() - trueEDMG;
        int trueEHP = e.getHP() - truePDMG;
        if(p.getEnergy() >= 50){
                if(truePDMG > 0){
                        if(trueEHP <= 0)
				e.setHP(0);
			else
				e.setHP(trueEHP);
		}
                if(trueEDMG > 0){
                        if(truePHP <= 0)
				p.setHP(0);	
			else
				p.setHP(truePHP);
		}
                p.setEnergy(p.getEnergy() - 50);
        }

}

void Combat::heal(Player & p){
	if(p.getEnergy() >= 25 && p.getHP() < 100){
		if((p.getHP() + 2.5 * p.getDEF()) > 100)
			p.setHP(100);
		else
			p.setHP(p.getHP() + 2.5 * p.getDEF());
		p.setEnergy(p.getEnergy() - 25);
	}
}

void Combat::PlayerDeath(Player & p){

}


Combat::~Combat(){}
