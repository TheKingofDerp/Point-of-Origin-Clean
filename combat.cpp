#include"combat.hpp"

Combat::Combat(){

}

void Combat::Sbattle(RenderWindow & window, Event & event, Swordsman & s, Enemy & e){
	switch(event.type){
		case Event::Closed:
			window.close();
			break;
		case Event::KeyReleased:
			switch(event.key.code){
				case Keyboard::Num1:
					s.basicAtk(s, e);
					cout<<"Basic Attack\n";
					break;
				case Keyboard::Num2:
					s.abil1(s, e);
					cout<<"Ability 1\n";
					break;
				case Keyboard::Num3:
					s.abil2(s, e);
					cout<<"Ability 2\n";
					break;
				case Keyboard::Num4:
					s.abil3(s, e);
					cout<<"Ability3\n";
					break;
			}
	}
}

void Combat::Abattle(RenderWindow & window, Event & event, Archer & a, Enemy & e){
        switch(event.type){
                case Event::Closed:
                        window.close();
                        break;
                case Event::KeyReleased:
                        switch(event.key.code){
                                case Keyboard::Num1:
                                        a.basicAtk(a, e);
                                        cout<<"Basic Attack\n";
                                        break;
                                case Keyboard::Num2:
                                        a.abil1(a, e);
                                        cout<<"Ability 1\n";
                                        break;
                                case Keyboard::Num3:
                                        a.abil2(a, e);
                                        cout<<"Ability 2\n";
                                        break;
                                case Keyboard::Num4:
                                        a.abil3(a, e);
                                        cout<<"Ability3\n";
                                        break;
                        }
        }

}

void Combat::Wbattle(RenderWindow & window, Event & event, Wizard & w, Enemy & e){
        switch(event.type){
                case Event::Closed:
                        window.close();
                        break;
                case Event::KeyReleased:
                        switch(event.key.code){
                                case Keyboard::Num1:
                                        w.basicAtk(w, e);
                                        cout<<"Basic Attack\n";
                                        break;
                                case Keyboard::Num2:
                                        w.abil1(w, e);
                                        cout<<"Ability 1\n";
                                        break;
                                case Keyboard::Num3:
                                        w.abil2(w, e);
                                        cout<<"Ability 2\n";
                                        break;
                                case Keyboard::Num4:
                                        w.abil3(w, e);
                                        cout<<"Ability3\n";
                                        break;
                        }
        }

}

Combat::~Combat(){}
