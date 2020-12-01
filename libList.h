#include <iostream>
#include <string>
#include "gameLib.h"
// change to linear linked list 
#ifndef LIBLIST_H
#define LIBLIST_H

using namespace std;


class libList
{
    public:
        libList();
       ~libList();
        void readFromFile();
        void writeToFile();

        void addGame();
        void addToList(gameLib* OBJ);

        void printGame();
        void deleteGame();
        void deleteFromList(const char* userGame);
       

    private:
        struct Node
        {
             gameLib *data;
             Node *next;
        };
        Node *head;
        Node *tail;
};
#endif
