#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Good.hpp"
using namespace std;

// Default constructor without parameter
Good::Good() {}

// Default constructor with parameters
Good::Good(int ID, char type, string ref_seller) : price(0), adress("25, Nowhere Street"), surface(0), ID(ID), type(type), ref_seller(ref_seller){}

// Default constructor with parameters
Good::Good(int price, string adress, int surface, int ID, char type, string ref_seller) : price(price), adress(adress), surface(surface), ID(ID), type(type), ref_seller(ref_seller) {}

// Copy constructor
Good::Good(const Good &p) : price(p.price), adress(p.adress), surface(p.surface), ID(p.ID), type(p.type), ref_seller(p.ref_seller) {}

// Destructor
Good::~Good() {}

// Display function
void Good::display(){
  cout<< "\tID : "<<ID<<endl;
  cout<< "\tAdress : "<<adress<<endl;
  cout<< "\tSurface : "<<surface<<endl;
  cout<< "\tSold by :"<<ref_seller<<endl;
  cout<< "\tPrice : "<<price<<endl;
}
