#include <iostream>
#include <string>
using namespace std;
void greet();
void printMenu(string [],int);

void greet()
{
    system("clear");
    system("echo \"$(<greet.me)\"");
}
void printMenu(string menu[],int length)
{
    cout<<"\nEnter your Choice !"<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<"("<<(i+1)<<")"<<menu[i]<<endl;
    }
}
int main()
{
    string mainMenu[]={"Dummy","Menu","Exit"};
    greet();
    printMenu(mainMenu,sizeof(mainMenu)/sizeof(mainMenu[0]));
    return 0;
}
