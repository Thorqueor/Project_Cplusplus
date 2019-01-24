#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Client__
#define __Client__
using namespace std;


class Client{

protected:
  string name;
  string adress;
  char type; // 'b' = buyer, 's' = seller


public:
  Client();
  Client(char type); // Default constructor with minimum parameters
  Client(string name, string adress, char type); // Default constructor with parameters
  ~Client(); // Destructor
  Client(const Client &p); // Copy constructor

void display(); // Display function


//Getter
string getName(){return name;}
string getCAdress(){return adress;}
char getType(){return type;}

};
#endif
