#include"enemy.hpp"
/*Enemy values          
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
                #define MAXBaneHP 200
                #define BaneDMG 35
                #define BaneDEF 30
 */                  


Enemy::Enemy(){}
Enemy::~Enemy(){}

void Enemy::resetStats(Enemy & g, Enemy & o, Enemy & v, Enemy & b){
	g.setHP(100);
	o.setHP(125);
	v.setHP(150);
	b.setHP(250);
}

Goblin::Goblin(){
	hp = 100;
	dmg = 25;
	def = 10;
	name = "Goblin";
}

Goblin::~Goblin(){}

Orc::Orc(){
	hp = 125;
	dmg = 25;
	def = 15;
	name = "Orc";
}

Orc::~Orc(){}

Vanguard::Vanguard(){
	hp = 150;
	dmg = 25;
	def = 25;
	name = "Vanguard";
}

Vanguard::~Vanguard(){}

Bane::Bane(){
	hp = 200;
	dmg = 35;
	def = 30;
	name = "Bane";
}

Bane::~Bane(){}

void Enemy::drawEnemyStats(RenderWindow & window, Enemy & e){
	font.loadFromFile("fonts/defused.ttf");
	stats = string(toString<int>(e.getHP())) + string("\n\n\n") + string(toString<int>(e.getDMG())) + string("\n\n\n") + string(toString<int>(e.getDEF()));
	eTxt.setString(stats);
	eTxt.setFont(font);
	eTxt.setCharacterSize(20);
	eTxt.setFillColor(ORANGE);
	eTxt.setPosition(850, 410);
	window.draw(eTxt);
}
