#include"gameplayHUD.hpp"
RenderStage::RenderStage(){
	stagefont.loadFromFile("fonts/defused.ttf");
	stage1.setFont(stagefont);
	stage2.setFont(stagefont);
	stage3.setFont(stagefont);
	stage4.setFont(stagefont);
	stage1.setString("Stage 1");
        stage2.setString("Stage 2");
        stage3.setString("Stage 3");
        stage4.setString("Final Stage");
	stage1.setFillColor(ORANGE);
	stage2.setFillColor(ORANGE);
	stage3.setFillColor(ORANGE);
	stage4.setFillColor(ORANGE);
	stage1.setCharacterSize(48);
        stage2.setCharacterSize(48);
        stage3.setCharacterSize(48);
        stage4.setCharacterSize(48);
	stagewidth = stage1.getLocalBounds().width;
	stageheight = stage1.getLocalBounds().height;
	finalstageheight = stage4.getLocalBounds().height;
	finalstagewidth = stage4.getLocalBounds().width;
	stage1.setOrigin(stagewidth/2, stageheight/2);
        stage2.setOrigin(stagewidth/2, stageheight/2);
        stage3.setOrigin(stagewidth/2, stageheight/2);
	stage4.setOrigin(finalstagewidth/2, finalstageheight/2);
	stage1.setPosition(WindowWidth/2, 50);
        stage2.setPosition(WindowWidth/2, 50);
        stage3.setPosition(WindowWidth/2, 50);
        stage4.setPosition(WindowWidth/2, 50);

	vert1.setSize(Vector2f(3, WindowHeight/3));
        vert2.setSize(Vector2f(3, WindowHeight/3));
        horiz.setSize(Vector2f(WindowWidth, 3));
        vert1.setFillColor(GRAY);
        vert2.setFillColor(GRAY);
        horiz.setFillColor(GRAY);
        horizwidth = horiz.getLocalBounds().width;
        horizheight = horiz.getLocalBounds().height;
        vertwidth = vert1.getLocalBounds().width;
        vertheight = vert1.getLocalBounds().height;
        horiz.setOrigin(0, horizheight/2);
        vert1.setOrigin(vertwidth/2, vertheight);
        vert2.setOrigin(vertwidth/2, vertheight);
        horiz.setPosition(0, WindowHeight*2/3);
        vert1.setPosition(WindowWidth/2, WindowHeight);
        vert2.setPosition(WindowWidth*3/4, WindowHeight);

	estats.setFont(stagefont);
	pstats.setFont(stagefont);
	pstats.setString("HP:\n\nDMG:\n\nDEF:\n\nEnergy:");
	estats.setString("HP:\n\n\nDMG:\n\n\nDEF:");
	pstats.setFillColor(Color::Green);
	estats.setFillColor(ORANGE);
	pstats.setCharacterSize(20);
	estats.setCharacterSize(20);
	pstats.setPosition(510, 410);
	estats.setPosition(750, 410);
}
void RenderStage::drawStage1(RenderWindow & window){
	mainmenu.drawBGopaque(window);
	window.draw(horiz);
        window.draw(vert2);
        window.draw(vert1);
	window.draw(stage1);
	window.draw(pstats);
	window.draw(estats);
}
void RenderStage::drawStage2(RenderWindow & window){
	mainmenu.drawBGopaque(window);
	window.draw(horiz);
        window.draw(vert2);
        window.draw(vert1);
	window.draw(stage2);
	window.draw(pstats);
	window.draw(estats);
}
void RenderStage::drawStage3(RenderWindow & window){
	mainmenu.drawBGopaque(window);
	window.draw(horiz);
        window.draw(vert2);
        window.draw(vert1);
	window.draw(stage3);
	window.draw(pstats);
	window.draw(estats);
}
void RenderStage::drawStage4(RenderWindow & window){
	mainmenu.drawBGopaque(window);
	window.draw(horiz);
        window.draw(vert2);
        window.draw(vert1);
	window.draw(stage4);
	window.draw(pstats);
	window.draw(estats);
}
        
RenderStage::~RenderStage(){}


RenderPlayerHUD::RenderPlayerHUD(Player & p){
	font.loadFromFile("fonts/defused.ttf");
	player.setFont(font);
	vs.setFont(font);
	optString = string("1) Basic Attack\n\n\n") + string("2) ") + string(p.ability1) + string("\n\n\n3) ") + string(p.ability2) + string("\n\n\n4) Heal");
	options.setFont(font);
	options.setString(optString);
	options.setCharacterSize(16);
	options.setFillColor(LIGHTBLUE);
	options.setPosition(10, 410);
	descr.setFont(font);
	descr.setString("Do damage. Energy Cost: 0\n\n\n\nDo 2x DMG. Energy Cost: 20\n\n\n\nDo 4x DMG. Energy Cost: 50\n\n\n\nHeal for 2.5x DEF. Energy Cost: 25");
	descr.setFillColor(LIGHTBLUE);
	descr.setCharacterSize(12);
	descr.setPosition(30, 435);
	player.setString(p.getName());
	vs.setString("VS");
	player.setCharacterSize(30);
	vs.setCharacterSize(24);
	player.setFillColor(ORANGE);
	vs.setFillColor(ORANGE);
	playerWidth = player.getLocalBounds().width;
	playerHeight = player.getLocalBounds().height;
	vsWidth = vs.getLocalBounds().width;
	vsHeight = vs.getLocalBounds().height;
	player.setOrigin(playerWidth/2, playerHeight/2);
	vs.setOrigin(vsWidth/2, vsHeight/2);
	player.setPosition(WindowWidth/4, 150);
	vs.setPosition(WindowWidth/2, 150);
}

void RenderPlayerHUD::drawPlayerHUD(RenderWindow & window){
	window.draw(player);
	window.draw(vs);
	window.draw(options);
	window.draw(descr);
}


RenderPlayerHUD::~RenderPlayerHUD(){}

RenderEnemyHUD::RenderEnemyHUD(Enemy & e){
	font.loadFromFile("fonts/defused.ttf");
        enemy.setFont(font);
	enemy.setString(e.getName());
	enemy.setCharacterSize(30);
	enemy.setFillColor(ORANGE);
	enemyWidth = enemy.getLocalBounds().width;
	enemyHeight = enemy.getLocalBounds().height;
	enemy.setOrigin(enemyWidth/2, enemyHeight/2);
	enemy.setPosition(WindowWidth *3/4, 150);
}

void RenderEnemyHUD::drawEnemyHUD(RenderWindow & window){
	window.draw(enemy);
}

RenderEnemyHUD::~RenderEnemyHUD(){}
