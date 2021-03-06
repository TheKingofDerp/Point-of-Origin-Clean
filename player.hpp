#pragma once
#include"util.hpp"
#include"enemy.hpp"

//Player unit values
        #define STARTHP 100
	//Archer
        //        #define ArcherDMG 25
        //        #define ArcherDEF 15

        //Swordsman
        //        #define SwordsmanDMG 20
        //        #define SwordsmanDEF 20

        //Wizard
        //        #define WizardDMG 30
        //        #define  WizardDEF 10
class Player{
friend class RenderPlayerHUD;
protected:
	int hp, energy = 0, dmg, def, maxhp, maxenergy;
	string name, stats;
	string ability1, ability2, ability3;
	string ab1desc, ab2desc, ab3desc;
	Text pTxt;
	Font font;
public:
	Player();
	~Player();
	string getName(){return name;}
	void drawPlayerStats(RenderWindow & window, Player & p);
	
	//Reset function
	static void resetStats(Player & s, Player & a, Player & w);
	static void setDiffStats(Player & s, Player & a, Player & w, int diff);
	void basicAtk(Player & p, Enemy & e);
	//Ability functions
        /*void abil1(Player & p, Enemy & e);
        void abil2(Player & p, Enemy & e);
        void abil3(Player & p, Enemy & e);*/
	//Stat functions
	int getHP(){return hp;}
	void setHP(int h){hp = h;}
	int getEnergy(){return energy;}
	void setEnergy(int e){energy = e;}
	int getDMG(){return dmg;}
	void setDMG(int d){dmg = d;}
	int getDEF(){return def;}
	void setDEF(int df){def = df;}
	int getMaxHP(){return maxhp;}
	void setMaxHP(int mhp){maxhp = mhp;}
	int getMaxEnergy(){return maxenergy;}
	void setMaxEnergy(int me){maxenergy = me;}

};

class Swordsman : public Player{
private:
public:
	Swordsman();
	~Swordsman();
        void abil1(Swordsman & s, Enemy & e);
        void abil2(Swordsman & s, Enemy & e);
        void abil3(Swordsman & s, Enemy & e);
};

class Archer : public Player{
private:
public:
	Archer();
	~Archer();
        void abil1(Archer & a, Enemy & e);
        void abil2(Archer & a, Enemy & e);
        void abil3(Archer & a, Enemy & e);
};

class Wizard : public Player{
private:
public:
	Wizard();
	~Wizard();
        void abil1(Wizard & w, Enemy & e);
        void abil2(Wizard & w, Enemy & e);
        void abil3(Wizard & w, Enemy & e);
};
