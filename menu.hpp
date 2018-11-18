/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include<fstream>
using std::ifstream;
using std::ofstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

// function prototype for the program's menu
void introMenu(int&, bool&);
void GameMenu(int&);
//void OLD_GameMenu(char&);
void mainMenuReturn(bool&);

#endif
