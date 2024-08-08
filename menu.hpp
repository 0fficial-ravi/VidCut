/*Menu.hpp*/
#ifndef MENU
#define MENU
#include <string>
#include <limits>
#include <unistd.h>
#include <iomanip>
using namespace std;
extern int choice;
extern string currPage;
extern int mainMenuFlag;
void greet();
void printMenu(string [],int);
void updateCurrPage(string);
void resetChoice();
void cls();
void resetMainMenuFlag();

int inputChoice();
//menu declaration
int mainMenu();
int convMenu();

#endif
