#pragma once
#include"util.hpp"


//Enemy values
	//Goblin
		#define MAXGoblinHP 100
		#define GoblinDMG 25
		#define GoblinDEF 10
	//Orc
		#define MAXOrcHP 125
		#define OrcDMG 25
		#define OrcDEF 15
	//Vanguard
		#define MAXVanguardHP 150
		#define VanguardDMG 25
		#define VanguardDEF 25
	//Bane
		#define MAXBaneHP 250
		#define BaneDMG 35
		#define BaneDEF 35
		

class Enemy{
protected:
	float hp, dmg, def;
	string name, stats;
	Text eTxt;
	Font font;
public:
	Enemy();
	~Enemy();
	string getName(){return name;}
	void drawEnemyStats(RenderWindow & window, Enemy & e);
	
	static void resetStats(Enemy & g, Enemy & o, Enemy & v, Enemy & b);
	//Stat functions
	int getHP(){return hp;}
	void setHP(int h){hp = h;}
	int getDMG(){return dmg;}
	void setDMG(int dg){dmg = dg;}
	int getDEF(){return def;}
	void setDEF(int df){def = df;}
};

class Goblin : public Enemy{

public:
	Goblin();
	~Goblin();
};

class Orc : public Enemy{

public:
	Orc();
	~Orc();
};

class Vanguard : public Enemy{

public:
	Vanguard();
	~Vanguard();
};

class Bane : public Enemy{

public:
	Bane();
	~Bane();
};
