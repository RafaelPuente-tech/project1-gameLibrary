#include <iostream>
#include "libList.h"
#include "gameLib.h"
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

libList::libList()
{
     head = NULL;
     tail = NULL;
}

libList::~libList()
{
    while(head)
    {
    Node *temp = head -> next;
    delete head -> data;
    delete head;
    head = temp;
    }
}



// function for option 1
void libList::readFromFile()
{
    char nameOfGame[50];
    char locationPurchased[50];
    double amountPaid;
    char fileName[MAX_STR];
    cout <<"Enter File Name: " << endl;
    cin.getline(fileName, MAX_STR);

        ifstream infile;
        infile.open(fileName);

    if(infile.is_open())
    {
      while(infile.getline(nameOfGame, MAX_STR))
      {
      infile.getline(locationPurchased, MAX_STR);
      infile >> amountPaid;
      infile.ignore(100, '\n');
        gameLib *OBJ = new gameLib(nameOfGame, locationPurchased, amountPaid);
        addToList(OBJ);
      }
      infile.close();
    }
    else{
        cout <<"Error: ~ #*!@$" << endl;
        }
}


// Function has been moved too GameLib class

// function for option 2
void libList::writeToFile()
{

    char fileName[MAX_STR];
    cout <<"Enter File Name: " << endl;
   cin.getline(fileName, MAX_STR);

        ofstream userFile(fileName);

    if(userFile.is_open())
    {
    if(!head)
    {
    return;
}
    Node *current = head;
    while(current)
{
    userFile << current -> data -> getName() << endl;
    userFile << current -> data -> getLocation() << endl;
    userFile << current -> data -> getAmount() << endl;
    current = current -> next;
 }
    userFile.close();
    }
   else{
        cout <<"Error #!*%" << endl;
       }
}

// function for option 3
void libList::addGame()
{
    char nameOfGame[MAX_STR]; 
    cout <<"Enter Title Of Game: "<< endl;
    cin.getline(nameOfGame, MAX_STR);
  
    char locationPurchased[MAX_STR];
    cout <<"Enter Location Purchased: " << endl;
    cin.getline(locationPurchased, MAX_STR);
   
    double amountPaid;
    cout <<"Enter Price: "<< endl;
    cin >> amountPaid;
   
    gameLib *OBJ = new gameLib(nameOfGame, locationPurchased, amountPaid);
    addToList(OBJ);
}

void libList::addToList(gameLib* data)
{
    const char* gameName = data -> getName();
    Node *new_ptr = new Node;

    new_ptr -> data = data;
    new_ptr -> next = nullptr;

    if(!head)
    {
    head = new_ptr;
    }
    else
    {
    Node *current = head;
    Node *previous = nullptr;

    while(current)
    {
    const char* thisGame = current -> data -> getLocation();
    if(strcmp(thisGame, gameName) > 0)
    {
       new_ptr ->next = current;
       if(previous){
         previous ->next = new_ptr;
       }
       else
       {
         head = new_ptr;
       }
       return;
    }
    previous = current;
    current= current ->next;
    }
    previous -> next = new_ptr;
   }
}


// Function for option  5
void libList::deleteGame()
{
    char userGame[50];
    cout << "Enter Game: " << endl;
    cin.getline(userGame, 50);
    deleteFromList(userGame);
}

void libList::deleteFromList(const char* userGame)
{
    if(!head)  // head is NULL then list is empty
    {
        cout <<" String is Empty ;" << endl;
        return;
    }
    Node* current = head;  // first node
    Node* previous = NULL; // this will be set later
    while(current)        // true if current is NOT NULL
    {
        const char *ThisName = current -> data -> getName();
        if(strcmp(ThisName, userGame) == 0)  // found the Node
        {
            if(!previous)
            {
             head = head -> next;
            }
            else
            {
             previous -> next = current -> next;
            }
             delete current -> data; // delete the data
             delete current;         // delete the node
             return;
            }
       previous = current;
       current = current -> next;
        }
      cout <<" No name Found" << endl;
    }
// print
void libList::printGame()
{
     if(!head)
     {
         cout <<"No Games in list" << endl;
         return;
     }
     Node *current = head;
     while(current)
     {
         current -> data -> print();
         current = current -> next;
     }
}







