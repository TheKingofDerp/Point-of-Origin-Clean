#pragma once
#include"util.hpp"
#include"player.hpp"
#include"enemy.hpp"

class Combat{
private:

public:
	Combat();
	~Combat();
	void Sbattle(RenderWindow & window, Event & event, Swordsman & s, Enemy & e);
        void Abattle(RenderWindow & window, Event & event, Archer & a, Enemy & e);
        void Wbattle(RenderWindow & window, Event & event, Wizard & w, Enemy & e);
};
