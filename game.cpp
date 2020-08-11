#include"game.hpp"
Game::Game(){this->initWindow();}
void Game::initWindow(){
	//Creates a new SFML window

	ifstream ifs("Config/windows.dat");
	VideoMode window_bounds(800, 600);
	string title = "None";
	unsigned framerate_limit = false;
	bool vertical_sync_enabled = false;
	if(ifs.is_open()){
		getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;	
	}
	ifs.close();
	window.create(VideoMode(window_bounds), title);
	window.setFramerateLimit(framerate_limit);
	window.setVerticalSyncEnabled(vertical_sync_enabled);
}
void Game::run(){
	while(window.isOpen()){
		//if in menu
		if(inMenu){
			while(window.pollEvent(event)){
				switch(event.type){
					case Event::Closed:
						window.close();
						break;
					case Event::KeyReleased:
						switch(event.key.code){
							case Keyboard::Enter:
								inMenu = false;
								inChooseDiff = true;
								break;
							case Keyboard::Escape:
								window.close();
						}
						break;
				}
			}
			mainmenu.drawMainMenu(window);
		}
		if(inChooseDiff){
			while(window.pollEvent(event)){
                                switch(event.type){
                                        case Event::Closed:
                                                window.close();
                                                break;
                                        case Event::KeyReleased:
                                                switch(event.key.code){
                                                        case Keyboard::Escape:
                                                                inChooseDiff = false;
                                                                inMenu = true;
                                                                break;
                                                        case Keyboard::Num1:
                                                                //Player::setDiffStats(swords, arch, wiz, 1);
                                                                inChooseDiff = false;
                                                                inClassSelect = true;
                                                                break;
                                                        case Keyboard::Num2:
                                                                //Player::setDiffStats(swords, arch, wiz, 2);
                                                                inChooseDiff = false;
                                                                inClassSelect = true;
                                                                break;
                                                        case Keyboard::Num3:
                                                                //Player::setDiffStats(swords, arch, wiz, 3);
                                                                inChooseDiff = false;
                                                                inClassSelect = true;
                                                                break;
                                                }
                                                break;
                                }
                        }
                        difficulty.render(window);
		}
		if(inClassSelect){
			//pick a class or go back
                        while(window.pollEvent(event)){
                                switch(event.type){
                                        case Event::Closed:
                                                window.close();
                                                break;
                                        case Event::KeyReleased:
                                                switch(event.key.code){
                                                        case Keyboard::Escape:
                                                                inClassSelect = false;
                                                                inMenu = true;
                                                                break;
                                                        case Keyboard::Num1:
                                                                //inClassSelect = false;
                                                                //inGame = true;
                                                                //inStage1 = true;
                                                                isSwords = true;
                                                                cout<<"1\n";
								break;
                                                        case Keyboard::Num2:
                                                                //inClassSelect = false;
                                                                //inGame = true;
                                                                //inStage1 = true;
                                                                isArch = true;
								cout<<"2\n";
                                                                break;
                                                        case Keyboard::Num3:
                                                                //nClassSelect = false;
                                                                //inGame = true;
                                                                //inStage1 = true;
                                                                isWiz = true;
								cout<<"3\n";
                                                                break;
                                                break;
                                                }
                                }
                        }
                        classselect.render(window);
		}
		//If not in any screen
		if(!inMenu && !inChooseDiff && !inClassSelect){
			window.close();
		}
	}
}

