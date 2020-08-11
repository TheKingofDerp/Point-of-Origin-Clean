#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>
#include<stack>
#include<map>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#define WindowWidth 960
#define WindowHeight 600
#define ORANGE Color(255, 96, 0)
#define GRAY Color(128, 128, 128)
#define LIGHTBLUE Color(0, 128, 255)

using namespace std;
using namespace sf;

template<typename T>
string toString(T arg){
	stringstream ss;
	ss << arg;
	return ss.str();
}
