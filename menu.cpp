/*Menu.cpp*/
#include "menu.hpp"
#include <iostream>
using namespace std;

string currPage="main";
string targetFileLoc="";
string destLoc="~/Desktop/";
string outFileName;
string targetFileName;
int choice;
int mainMenuFlag;

void getTargetFileName()
{
    for(int i=targetFileLoc.length()-1;i>=0;i--)
    {
        if(targetFileLoc.at(i)=='/')
        {
            targetFileName=targetFileLoc.substr((i+1),targetFileLoc.length()-(i+1));
            targetFileLoc=targetFileLoc.substr(0,i+1);
            break;
        }
    }
}

void getLocations()
{
    cout<<"Enter source file location:";
    getline(cin,targetFileLoc);
    getTargetFileName();
    cout<<"Specify output file location (Default Desktop):";
    getline(cin,destLoc);
    if(destLoc.empty())
        destLoc="~/Desktop/";
    cout<<"Specify output file name (Default VidConvOutput):";
    getline(cin,outFileName);
    if(outFileName.empty())
        outFileName="VidCutOutput";
    dispLoc();
}

void dispLoc()
{
    cout<<"\nInput File Location:"<<targetFileLoc<<endl;
    cout<<"Input File Name:"<<targetFileName<<endl;
    cout<<"\nDestination:"<<destLoc<<endl;
    cout<<"Output File Name:"<<outFileName<<endl;
    sleep(7);
}
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
    for(int i=0;i<length;i++)
    {
       cout<<"["<<(i+1)<<"] "<<menu[i]<<endl;
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
        system("Color 02");
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
                    convVid();
                    break;
                    }
            case 2: {
                    resetChoice();
                    updateCurrPage("main/convert/Audio/");
                    convAud();
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
int convVid()
{
   resetChoice();
   updateCurrPage("main/convert/Video/");
   string menu[]={"Video->Audio","Video->Video (Other Format)","Back","Exit"};
    while(1)
    {   
        cls();
        cout<<"--------[Convert Video Menu]-------\n\n"<<endl;
        printMenu(menu,sizeof(menu)/sizeof(menu[0]));
        choice=inputChoice();
        switch(choice)
        {
            case 1: {
                    resetChoice();
                    updateCurrPage("main/convert/Video_Audio/");
                    audioFormat(0);
                    break;
                    }
            case 2: {
                    resetChoice();
                    updateCurrPage("main/convert/Video_Video/");
                    //dummy call to convert video->video (other format) fn
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
int convAud()
{
   resetChoice();
   updateCurrPage("main/convert/Audio/");
   string menu[]={"Add Album art to audio","Audio->Audio (Other Format)","Back","Exit"};
    while(1)
    {   
        cls();
        cout<<"--------[Convert Audio Menu]-------\n\n"<<endl;
        printMenu(menu,sizeof(menu)/sizeof(menu[0]));
        choice=inputChoice();
        switch(choice)
        {
            case 1: {
                    resetChoice();
                    updateCurrPage("main/convert/Audio/PictToAudio/");
                    //dummy call to add picture to audio fn
                    break;
                    }
            case 2: {
                    resetChoice();
                    updateCurrPage("main/convert/Audio/Audio_Audio/");
                    //dummy call to convert audio->audio (other format) fn
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

//Formats for Audio/Video

int audioFormat(int flag)
{
    int status=0;
   resetChoice();
   //updateCurrPage("main/convert/Audio/");
   string menu[]={"mp3","flac","wav","ogg","Back","Exit"};
   string command="";
    while(1)
    {   
        cls();
        if(flag==0)
        cout<<"--------[Convert Video->Audio Menu]-------\n\n"<<endl;
        if(flag==1)
        cout<<"--------[Convert Audio->Audio\t(Other Format) Menu]-------\n\n"<<endl;
        printMenu(menu,sizeof(menu)/sizeof(menu[0]));
        choice=inputChoice();
        if(choice!=5 && choice!=6)
        getLocations();
        switch(choice)
        {
            case 1:
                    command="ffmpeg -i "+targetFileLoc+"\""+targetFileName+"\""+" -vn "+destLoc+"\""+outFileName+"."+menu[0]+"\"";
                    break;
            case 2: 
                    command="ffmpeg -i "+targetFileLoc+"\""+targetFileName+"\""+ " -vn -c:a flac "+destLoc+"\""+outFileName+"."+menu[1]+"\"";
                    break;
            case 3:
                    command="ffmpeg -i "+targetFileLoc+"\""+targetFileName+"\""+ " -vn -acodec pcm_s16le "+destLoc+"\""+outFileName+"."+menu[2]+"\"";
                    break;
            case 4:
                    command="ffmpeg -i "+targetFileLoc+"\""+targetFileName+"\""+ " -vn -acodec libvorbis "+destLoc+"\""+outFileName+"."+menu[3]+"\"";
                    break;
                   
            case 5: return 0;

            case 6: exit(1);

            default:   
                        resetChoice();
                        cout<<"Please enter a valid input !!"<<endl;
                        sleep(2);
        }

                    resetChoice();
                    //cout<<"\nExecuting :$"<<command<<endl;
                    //sleep(20);
                    status=system(command.c_str());
                    if(status==0)
                    {
                        cls();
                        cout<<"\n\n\n\t\t\t\tFile convertion Successful Yay!! (:"<<endl;
                        sleep(3);
                    }
                    else{
                        cls();
                        cout<<"\n\n\n\t\t\t\tFile Conversion Failed (T_T) "<<endl;
                        sleep(3);
                    }
    }
    return 0; 
}

