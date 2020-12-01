#include <iostream>
#include <string>
#ifndef GAMELIB_H
#define GAMELIB_H 
using namespace std;
const int MAX_STR = 100;

class gameLib
{
    public:
        gameLib();
       ~gameLib();
        gameLib(char* nameOfGame, char* locationPurchased, double amountPaid);
        gameLib(const gameLib &cpy);
        void print();

       const gameLib operator= (const gameLib &cpy);

//Accessors
        const char* getName();
        const char* getLocation();
        double getAmount();
// Mutator 
        void setName(const char* Name);
        void setLocation(const char* location);
        void setAmount(double amount);

 
    private:
        char* nameOfGame;
        char* locationPurchased;
        double amountPaid;
};
#endif
