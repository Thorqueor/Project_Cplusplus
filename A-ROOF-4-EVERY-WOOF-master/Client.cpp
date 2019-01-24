#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Client.hpp"
using namespace std;

//Default Constructor
Client::Client() : name("Good Boy"), adress("63, Collarbone Street") {}

// Default constructor with minimum parameters
Client::Client(char type) : name("Good Boy"), adress("63, Collarbone Street"), type(type) {}

// Default constructor with parameters
Client::Client(string name, string adress, char type) : name(name), adress(adress), type(type) {}

// Copy constructor
Client::Client(const Client &p) : name(p.name), adress(p.adress), type(p.type) {}

// Destructor
Client::~Client() {}

// Display function
void Client::display(){
  cout<< "\tName : "<< name << endl;
  cout<< "\tAdress : " << adress << endl;
}
