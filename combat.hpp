#pragma once
#include"util.hpp"
#include"player.hpp"
#include"enemy.hpp"

class Combat{
private:

public:
	Combat();
	~Combat();
	void battle(RenderWindow & window, Event & event, Player & p, Enemy & e);
	void basicAtk(Player & p, Enemy & e);
	void ability1Atk(Player & p, Enemy & e);
	void ability2Atk(Player & p, Enemy & e);
	void heal(Player & p);
	void PlayerDeath(Player & p);
};
