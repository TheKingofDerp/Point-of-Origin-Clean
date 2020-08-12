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
        RenderPlayerHUD PArch(arch);
        RenderPlayerHUD PSwords(swords);
        RenderPlayerHUD PWiz(wiz);
        RenderEnemyHUD gob1(goblin);
        RenderEnemyHUD orc1(orc);
        RenderEnemyHUD vang1(vanguard);
        RenderEnemyHUD bane1(bane);

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
			Enemy::resetStats(goblin, orc, vanguard, bane);
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
                                                                Player::setDiffStats(swords, arch, wiz, 1);
                                                                inChooseDiff = false;
                                                                inClassSelect = true;
                                                                break;
                                                        case Keyboard::Num2:
                                                                Player::setDiffStats(swords, arch, wiz, 2);
                                                                inChooseDiff = false;
                                                                inClassSelect = true;
                                                                break;
                                                        case Keyboard::Num3:
                                                                Player::setDiffStats(swords, arch, wiz, 3);
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
                                                                inClassSelect = false;
                                                                inGame = true;
                                                                inStage1 = true;
                                                                isSwords = true;
								break;
                                                        case Keyboard::Num2:
                                                                inClassSelect = false;
                                                                inGame = true;
                                                                inStage1 = true;
                                                                isArch = true;
                                                                break;
                                                        case Keyboard::Num3:
                                                                inClassSelect = false;
                                                                inGame = true;
                                                                inStage1 = true;
                                                                isWiz = true;
                                                                break;
                                                break;
                                                }
                                }
                        }
                        classselect.render(window);
		}
		if(inGame){
			if(inStage1){
				while(window.pollEvent(action)){
                                       	switch(action.type){
                                       	        case Event::Closed:
                                       	                window.close();
                                       	                break;
                                       	        case Event::KeyReleased:
                                       	                switch(action.key.code){
                                       	                        case Keyboard::Escape:
                                       	                                Player::resetStats(swords, arch, wiz);
                                       	                                Enemy::resetStats(goblin, orc, vanguard, bane);
                                       	                                inStage1 = false;
                                       	                                inGame = false;
                                       	                                inMenu = true;
                                       	                                isSwords = false;
                                       	                                isArch = false;
                                       	                                isWiz = false;
                                       	                                break;
                                       	                }
                                       	                break;
                                       	}
                                       	if(isSwords){
                                       	        combat.Sbattle(window, action, swords, goblin);
						if(swords.getHP() == 0){
							inLose = true;
							inGame = false;
							inStage1 = false;
						}
					}
                                       	if(isArch){
                                       	        combat.Abattle(window, action, arch, goblin);
						if(arch.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage1 = false;
                                                }
                                        }
                                       	if(isWiz){
                                       	        combat.Wbattle(window, action, wiz, goblin);
						if(wiz.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage1 = false;
                                                }
                                        }
                               	}
				window.clear();
                               	renderstage.drawStage1(window);
                               	if(isSwords){
                              	        PSwords.drawPlayerHUD(window);
                               	        swords.drawPlayerStats(window, swords);
                               	}
                               	else if(isArch){
                               	        PArch.drawPlayerHUD(window);
                               	        arch.drawPlayerStats(window, arch);
                               	}
                               	else if(isWiz){
                               	        PWiz.drawPlayerHUD(window);
                               	        wiz.drawPlayerStats(window, wiz);
                               	}
                               	gob1.drawEnemyHUD(window);
                               	goblin.drawEnemyStats(window, goblin);
                               	window.display();
                               	if(goblin.getHP() == 0){
                               	        inStage1 = false;
                               		inStage2 = true;
                               	}
			}
			if(inStage2){
				while(window.pollEvent(action)){
					switch(action.type){
                                                case Event::Closed:
                                                        window.close();
                                                        break;
                                                case Event::KeyReleased:
                                                        switch(action.key.code){
                                                                case Keyboard::Escape:
                                                                        Player::resetStats(swords, arch, wiz);
                                                                        Enemy::resetStats(goblin, orc, vanguard, bane);
                                                                        inStage2 = false;
                                                                        inGame = false;
                                                                        inClassSelect = true;
                                                                        isSwords = false;
                                                                        isArch = false;
                                                                        isWiz = false;
                                                                        break;
                                                        }
                                                        break;
                                        }
                                        if(isSwords){
                                                combat.Sbattle(window, action, swords, orc);
                                                if(swords.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage2 = false;
                                                }
                                        }
                                        if(isArch){
                                                combat.Abattle(window, action, arch, orc);
                                                if(arch.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage2 = false;
                                                }
                                        }
                                        if(isWiz){
                                                combat.Wbattle(window, action, wiz, orc);
                                                if(wiz.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage2 = false;
                                                }
                                        }
				}
				window.clear();
                                renderstage.drawStage2(window);
                                if(isSwords){
                                        PSwords.drawPlayerHUD(window);
                                        swords.drawPlayerStats(window, swords);
                                }
                                else if(isArch){
                                        PArch.drawPlayerHUD(window);
                                        arch.drawPlayerStats(window, arch);
                                }
                                else if(isWiz){
                                        PWiz.drawPlayerHUD(window);
                                        wiz.drawPlayerStats(window, wiz);
                                }
                                orc1.drawEnemyHUD(window);
                                orc.drawEnemyStats(window, orc);
                                window.display();
                                if(orc.getHP() == 0){
                                        inStage2 = false;
                                        inStage3 = true;
                                }
			}	
			if(inStage3){
				while(window.pollEvent(action)){
					switch(action.type){
                                                case Event::Closed:
                                                        window.close();
                                                        break;
                                                case Event::KeyReleased:
                                                        switch(action.key.code){
                                                                case Keyboard::Escape:
                                                                        Player::resetStats(swords, arch, wiz);
                                                                        Enemy::resetStats(goblin, orc, vanguard, bane);
                                                                        inStage3 = false;
                                                                        inGame = false;
                                                                        inClassSelect = true;
                                                                        isSwords = false;
                                                                        isArch = false;
                                                                        isWiz = false;
                                                                        break;
                                                        }
                                                        break;
                                        }
					if(isSwords){
                                                combat.Sbattle(window, action, swords, vanguard);
                                                if(swords.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage3 = false;
                                                }
                                        }
                                        if(isArch){
                                                combat.Abattle(window, action, arch, vanguard);
                                                if(arch.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage3 = false;
                                                }
                                        }
                                        if(isWiz){
                                                combat.Wbattle(window, action, wiz, vanguard);
                                                if(wiz.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage3 = false;
                                                }
                                        }
				}
				window.clear();
                                renderstage.drawStage3(window);
                                if(isSwords){
                                        PSwords.drawPlayerHUD(window);
                                        swords.drawPlayerStats(window, swords);
                                }
                                else if(isArch){
                                        PArch.drawPlayerHUD(window);
                                        arch.drawPlayerStats(window, arch);
                                }
                                else if(isWiz){
                                        PWiz.drawPlayerHUD(window);
                                        wiz.drawPlayerStats(window, wiz);
                                }
                                vang1.drawEnemyHUD(window);
                                vanguard.drawEnemyStats(window, vanguard);
                                window.display();
                                if(vanguard.getHP() == 0){
                                        inStage3 = false;
                                        inStage4 = true;
                                }
			}
			if(inStage4){
				while(window.pollEvent(action)){
					switch(action.type){
                                                case Event::Closed:
                                                        window.close();
                                                        break;
                                                case Event::KeyReleased:
                                                        switch(action.key.code){
                                                                case Keyboard::Escape:
                                                                        Player::resetStats(swords, arch, wiz);
                                                                        Enemy::resetStats(goblin, orc, vanguard, bane);
                                                                        inStage4 = false;
                                                                        inGame = false;
                                                                        inClassSelect = true;
                                                                        isSwords = false;
                                                                        isArch = false;
                                                                        isWiz = false;
                                                                        break;
                                                        }
                                                        break;
                                        }
                                        if(isSwords){
                                                combat.Sbattle(window, action, swords, bane);
                                                if(swords.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage4 = false;
                                                }
                                        }
                                        if(isArch){
                                                combat.Abattle(window, action, arch, bane);
                                                if(arch.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage4 = false;
                                                }
                                        }
                                        if(isWiz){
                                                combat.Wbattle(window, action, wiz, bane);
                                                if(wiz.getHP() == 0){
                                                        inLose = true;
                                                        inGame = false;
                                                        inStage4 = false;
                                                }
                                        }
				}
				window.clear();
                                renderstage.drawStage4(window);
                                if(isSwords){
                                        PSwords.drawPlayerHUD(window);
                                        swords.drawPlayerStats(window, swords);
                                }
                                else if(isArch){
                                        PArch.drawPlayerHUD(window);
                                        arch.drawPlayerStats(window, arch);
                                }
                                else if(isWiz){
                                        PWiz.drawPlayerHUD(window);
                                        wiz.drawPlayerStats(window, wiz);
                                }
                                bane1.drawEnemyHUD(window);
                                bane.drawEnemyStats(window, bane);
                                window.display();
                                if(bane.getHP() == 0){
                                        inStage4 = false;
                                        inWin = true;
                                }
			}
		}
		if(inWin){
			while(window.pollEvent(event)){
				if(event.type == Event::Closed)
					window.close();
				if(event.type == Event::KeyReleased)
					if(event.key.code == Keyboard::Escape){
						inWin = false;
						inMenu = true;
					}
			}
			window.clear();
			mainmenu.drawBGopaque(window);
			winlose.drawWin(window);
			window.display();
		}
		if(inLose){
			while(window.pollEvent(event)){
                                if(event.type == Event::Closed)
                                        window.close();
                                if(event.type == Event::KeyReleased)
                                        if(event.key.code == Keyboard::Escape){
                                                inLose = false;
                                                inMenu = true;
                                        }
                        }
			window.clear();
			mainmenu.drawBGopaque(window);
			winlose.drawLose(window);
			window.display();
		}
		//If not in any screen
		if(!inMenu && !inChooseDiff && !inClassSelect && !inGame && !inWin && !inLose){
			window.close();
		}
	}
}

