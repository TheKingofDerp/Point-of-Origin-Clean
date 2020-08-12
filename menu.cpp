#include"menu.hpp"

MainMenu::MainMenu(){
        bg.loadFromFile("images/mustafar.jpeg");
        bg1.setTexture(bg);
        font.loadFromFile("fonts/defused.ttf");
        title.setFont(font);
        start.setFont(font);
        exit.setFont(font);
        title.setString("Point of Origin");
        start.setString("Press ENTER to Start");
        exit.setString("Press ESC to Exit");
        title.setCharacterSize(48);
        start.setCharacterSize(36);
        exit.setCharacterSize(36);
        title.setOrigin(title.getLocalBounds().width/2, title.getLocalBounds().height/2);
        start.setOrigin(start.getLocalBounds().width/2, start.getLocalBounds().height/2);
        exit.setOrigin(exit.getLocalBounds().width/2, exit.getLocalBounds().height/2);
        title.setFillColor(ORANGE);
        start.setFillColor(ORANGE);
        exit.setFillColor(ORANGE);
        title.setPosition(WindowWidth/2, WindowHeight/4);
        start.setPosition(WindowWidth/2, WindowHeight/2);
        exit.setPosition(WindowWidth/2, WindowHeight*3/4);
}

//MainMenu::~MainMenu(){}
void MainMenu::runEmpty(RenderWindow & window, Event & event){
	while(window.pollEvent(event)){
		if(event.type == Event::Closed)
			window.close();
	}
	window.clear();
	window.draw(bg1);
	window.display();
}

void MainMenu::drawMainMenu(RenderWindow &window){
        window.clear();
	window.draw(bg1);
        window.draw(title);
        window.draw(start);
        window.draw(exit);
	window.display();
}

void MainMenu::drawBG(RenderWindow & window){
	window.draw(bg1);
}

void MainMenu::drawBGopaque(RenderWindow & window){
	bg1.setColor(Color(255, 255, 255, 96));
	window.draw(bg1);
}

Difficulty::Difficulty(){
        difffont.loadFromFile("fonts/defused.ttf");
        difftext.setFont(difffont);
        difftext.setString("Choose Difficulty\n\n\n1) Easy\n\n\n2) Medium\n\n\n3) Hard");
        difftext.setCharacterSize(36);
        difftext.setFillColor(ORANGE);
        difftext.setOrigin(difftext.getLocalBounds().width/2, difftext.getLocalBounds().height/2);
        difftext.setPosition(WindowWidth/2, WindowHeight/2);

}
void Difficulty::render(RenderWindow & window){
	window.clear();
	mainmenu.drawBGopaque(window);
	window.draw(difftext);
	window.display();
}

ClassSelect::ClassSelect(){
        ClassSelectFont.loadFromFile("fonts/defused.ttf");
        swordsman.setFont(ClassSelectFont);
        archer.setFont(ClassSelectFont);
        wizard.setFont(ClassSelectFont);
        back.setFont(ClassSelectFont);
        select.setFont(ClassSelectFont);
        select.setString("Pick a Class");
        swordsman.setString("1) Swordsman");
        archer.setString("2) Archer");
        wizard.setString("3) Wizard");
        back.setString("ESC) Back to Main Menu");
        swordsman.setCharacterSize(36);
        archer.setCharacterSize(36);
        wizard.setCharacterSize(36);
        back.setCharacterSize(36);
        select.setCharacterSize(36);
        selectwidth = select.getLocalBounds().width;
        selectheight = select.getLocalBounds().height;
        swordsmanwidth = swordsman.getLocalBounds().width;
        swordsmanheight = swordsman.getLocalBounds().height;
        archerwidth = archer.getLocalBounds().width;
        archerheight = archer.getLocalBounds().height;
        wizardwidth = wizard.getLocalBounds().width;
        wizardheight = wizard.getLocalBounds().height;
        backwidth = back.getLocalBounds().width;
        backheight = back.getLocalBounds().height;
        select.setOrigin(selectwidth/2, selectheight/2);
        swordsman.setOrigin(swordsmanwidth/2, swordsmanheight/2);
        archer.setOrigin(archerwidth/2, archerheight/2);
        wizard.setOrigin(wizardwidth/2, wizardheight/2);
        back.setOrigin(backwidth/2, backheight/2);
        select.setFillColor(ORANGE);
        swordsman.setFillColor(ORANGE);
        wizard.setFillColor(ORANGE);
        archer.setFillColor(ORANGE);
        back.setFillColor(ORANGE);
        select.setStyle(Text::Regular);
        swordsman.setStyle(Text::Regular);
        archer.setStyle(Text::Regular);
        wizard.setStyle(Text::Regular);
        back.setStyle(Text::Regular);
        select.setPosition(WindowWidth/2, 100);
        swordsman.setPosition(WindowWidth/2, 200);
        archer.setPosition(WindowWidth/2, 300);
        wizard.setPosition(WindowWidth/2, 400);
        back.setPosition(WindowWidth/2, 500);
}

void ClassSelect::render(RenderWindow & window){
        window.clear();
        mainmenu.drawBGopaque(window);
        window.draw(select);
        window.draw(swordsman);
        window.draw(archer);
        window.draw(wizard);
        window.draw(back);
        window.display();
}

WinLose::WinLose(){
	font.loadFromFile("fonts/defused.ttf");
	win.setFont(font);
	lose.setFont(font);
	menu.setFont(font);
	win.setString("\t    Congratulations\n  You have restored peace \nand prosperity to the world");
	lose.setString("  Congratulations\n\t\tYou lost");
	menu.setString("ESC) Main Menu");
	win.setFillColor(ORANGE);
	lose.setFillColor(ORANGE);
	menu.setFillColor(ORANGE);
	win.setCharacterSize(40);
	lose.setCharacterSize(40);
	menu.setCharacterSize(24);
	win.setOrigin(win.getLocalBounds().width/2, win.getLocalBounds().height/2);
	win.setPosition(WindowWidth/2, WindowHeight/3);
        lose.setOrigin(lose.getLocalBounds().width/2, lose.getLocalBounds().height/2);
        lose.setPosition(WindowWidth/2, WindowHeight/3);
        menu.setOrigin(menu.getLocalBounds().width/2, menu.getLocalBounds().height/2);
        menu.setPosition(WindowWidth/4, WindowHeight*2/3);
}

void WinLose::drawWin(RenderWindow & window){
	window.draw(win);
	window.draw(menu);
}
void WinLose::drawLose(RenderWindow & window){
        window.draw(lose);
        window.draw(menu);
}

