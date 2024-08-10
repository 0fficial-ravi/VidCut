/*Menu.hpp*/
#ifndef MENU
#define MENU
#include <stdlib.h>
#include <string>
#include <limits>
#include <unistd.h>
#include <iomanip>
using namespace std;
extern int choice;
extern string currPage;
extern int mainMenuFlag;

extern string targetFileLoc;
extern string destLoc;
extern string outFileName;
extern string targetFileName;


void getTargetFileName();
void dispLoc();
void greet();
void printMenu(string [],int);
void updateCurrPage(string);
void resetChoice();
void cls();
void resetMainMenuFlag();
void getLocations();

int inputChoice();
//menu declaration
int mainMenu();
int convMenu();
int convVid();
int convAud();


//Formats for Audio/Video
int audioFormat(int);
int videoFormat();
#endif
