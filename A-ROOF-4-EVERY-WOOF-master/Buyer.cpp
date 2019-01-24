#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Client.hpp"
#include "Buyer.hpp"
using namespace std;

// Default constructor without parameter
Buyer::Buyer() : Client('b') {}

// Default constructor with minimum parameters
Buyer::Buyer(char type) : Client(type) {}

// Default constructor with parameters
Buyer::Buyer(string name, string adress, char type) : Client(name, adress, type) {}

// Copy Constructor
Buyer::Buyer(const Buyer &p) : Client(p.name, p.adress, p.type) {}

// Destructor
Buyer::~Buyer() {}

// Display function
void Buyer::display(){
  cout<<"Buyer"<<endl;
  Client::display();
  cout<<"\tList of visited goods : " << endl;
}
