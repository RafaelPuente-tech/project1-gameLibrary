#include <iostream>
#include "gameLib.h"
#include <cstring>
using namespace std;
// Function Definitions

// pram Constructor
gameLib::gameLib(char* Name, char* location, double amount)
{
    nameOfGame = NULL;
    setName(Name);
    locationPurchased = NULL;
    setLocation(location);
    amountPaid = amount;
}

// default constructor 
gameLib::gameLib()
{
    nameOfGame = new char[MAX_STR];
    strcpy(nameOfGame,"<no value>");

    locationPurchased = new char[MAX_STR];
    strcpy(locationPurchased, "<no value>");

    amountPaid = 0.0;
}

// destructor 
gameLib::~gameLib()
{
    delete[]nameOfGame;
    delete[]locationPurchased;
}
// copy constructer
 gameLib::gameLib(const gameLib &cpy)
{
    nameOfGame = NULL;
    setName(cpy.nameOfGame);
    locationPurchased = NULL;
    setLocation(cpy.locationPurchased);
    amountPaid = cpy.amountPaid;
}

const gameLib gameLib::operator= (const gameLib& cpy)
{

      if(this != &cpy)
{
      if (nameOfGame != NULL) delete [] nameOfGame;
      nameOfGame = new char[strlen(cpy.nameOfGame)+1];
      strcpy(nameOfGame, cpy.nameOfGame);

      locationPurchased = new char[strlen(cpy.locationPurchased)+1];
      strcpy(locationPurchased, cpy.locationPurchased);

      amountPaid = cpy.amountPaid;
}
      return *this;
}

//-------------------------
//Get name of game
// accessor
const char* gameLib::getName()
{
    return nameOfGame;
}

// Mutator
void gameLib::setName(const char* Name)
{
    if(nameOfGame != NULL)
       delete [] nameOfGame;
    nameOfGame = new char[strlen(Name)+1];
    strcpy(nameOfGame, Name);
}


//--------------------------
//Get Name of Location
// accessor
const char* gameLib::getLocation()
{
    return locationPurchased;
}

//Mutator
void gameLib::setLocation(const char* Location)
{
    if(locationPurchased != NULL)
      delete [] locationPurchased;
    locationPurchased = new char[strlen(Location)+1];
    strcpy(locationPurchased, Location);
}

//---------------------------
// Year
// accessor
double  gameLib::getAmount()
{
    return amountPaid;
}

//Mutator 
void gameLib::setAmount(double amount)
{
        amountPaid = amount;
}


// ---------------------------------
// print 
void gameLib::print()
{
    cout <<" Name: "<< nameOfGame  << endl;
    cout <<" Place: "<< locationPurchased << endl;
    cout <<" Price: $"<< amountPaid << endl;
}
