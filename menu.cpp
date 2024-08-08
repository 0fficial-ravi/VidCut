/*Menu.cpp*/
#include "menu.hpp"
#include <iostream>
using namespace std;

string currPage="main";
int choice;
int mainMenuFlag;

//Function Definations
void resetMainMenuFlag()
{
    mainMenuFlag=0;
}
void cls()
{
    system("clear");
}
void updateCurrPage(string page)
    {
        currPage=page;
    }
void greet()
{
    system("clear");
    system("echo \"$(<greet.me)\"");
}
void printMenu(string menu[],int length)
{
   // cout<<"\n\t\t\t\tMake your choice !!\n";
    for(int i=0;i<length;i++)
    {
        cout<<"("<<(i+1)<<")"<<menu[i]<<endl;
    }
}
void resetChoice()
{
    choice=-9999;
}

int inputChoice()
{
int num=0;
bool validInp=false;
while(!validInp)
    {
        cout<<"\nYour choice:";
        cin>>setw(1)>>num;
        if(cin.fail())
        {
            cout<<"\n\t\t\tPlease input a valid integer value!!!"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else
            validInp=true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

return num;
}

//Menus
int mainMenu()
{
    resetChoice();
    string menu[]={"Convert","Exit"};
    while(1)
    {
        greet();
        cout<<"\n--------[Main Menu]--------\n\n"<<endl;
        printMenu(menu,sizeof(menu)/sizeof(menu[0]));
        choice=inputChoice();
        switch(choice)
        {
            case 1: {
                    resetChoice();
                    updateCurrPage("main/convert/");
                    convMenu();
                    break;
                    }
            case 2: return 0;
            default:    resetChoice();
                        cout<<"Please enter a valid input !!"<<endl;
                        sleep(2);
                     
        }
    }
    return 0;
}
int convMenu()
{
   resetChoice();
   updateCurrPage("main/convert/");
   string menu[]={"Video","Audio","Back","Exit"};
    while(1)
    {   
        cls();
        cout<<"--------[Convert Menu]-------\n\n"<<endl;
        printMenu(menu,sizeof(menu)/sizeof(menu[0]));
        choice=inputChoice();
        switch(choice)
        {
            case 1: {
                    resetChoice();
                    updateCurrPage("main/convert/Video/");
                    //dummy call to convert video fn
                    break;
                    }
            case 2: {
                    resetChoice();
                    updateCurrPage("main/convert/Audio/");
                    //dummy call to convert video fn
                    break;
                    }
            case 3: return 0;
            case 4: exit(0);
            default:    resetChoice();
                        cout<<"Please enter a valid input !!"<<endl;
                        sleep(2);
                     
        }
    }
    return 0;
}
