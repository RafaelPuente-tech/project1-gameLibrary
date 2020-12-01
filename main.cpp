/*
Project 4 - by Rafael Puente
-------------------------------------
About program: 
      Game Library
      input name // place purchased // price 
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "gameLib.h"
#include "libList.h"
using namespace std;

//------------MAIN FUNCTION---------------
int main(){
    libList list;
    bool keepGoin = true;
    int userInput;

    while (keepGoin)
{
     cout <<"*** WELCOME TO GAME LIBRARY ***"<< endl;
     cout <<"  __ Main Menue __  "<< endl;
     cout <<"1 -> read in game from a file" << endl;
     cout <<"2 -> write out books to a file" << endl;
     cout <<"3 -> add game to library"<< endl;
     cout <<"4 -> print all games in library"<< endl;
     cout <<"5 -> remove game from library"<< endl;
     cout <<"6 -> quit the program"<< endl;
     cout <<"Please enter a choice (1 - 6)"<< endl;
        cin >> userInput;
        cin.ignore(100,'\n');

    if(userInput == 1)
    {
        list.readFromFile();
    }
    else if(userInput == 2)
    {
        list.writeToFile();
    }
    else if(userInput == 3)
    {
        list.addGame();
    }
    else if(userInput == 4)
    {
        list.printGame();
    }
    else if(userInput == 5)
    {
        list.deleteGame();
    }
    else if(userInput == 6)
    {
          cout <<"Thanks for using game Library" << endl;
          keepGoin = false;
    }
    else
    {
         cout << "Bark Bark, Sorry We couldnt fetch that Input" << endl;
    }
 }
    return 0;
}

