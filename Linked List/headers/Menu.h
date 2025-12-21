#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

// Console utility functions
void gotoxy(int column, int line);
void textattr(int i);

// Menu system
void runMenu();

#endif
