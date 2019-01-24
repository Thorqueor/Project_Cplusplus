#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "BusinessSpace.hpp"
using namespace std;

// Default constructor with minimum parameters
BusinessSpace::BusinessSpace(int ID, char type, string ref_seller) : Good(ID, type, ref_seller), storefront_size(0), storage_room(false) {}

// Default constructor with parameters
BusinessSpace::BusinessSpace(int price, string adress, int surface, int ID, char type, int storefront_size, bool storage_room, string ref_seller) : Good(price, adress, surface, ID, type, ref_seller), storefront_size(storefront_size), storage_room(storage_room) {}

// Copy Constructor
BusinessSpace::BusinessSpace(const BusinessSpace &p) : Good(p.price, p.adress, p.surface, p.ID, p.type, p.ref_seller),storefront_size(p.storefront_size), storage_room(p.storage_room) {}

// Destructor
BusinessSpace::~BusinessSpace() {}

// Display function
void BusinessSpace::display(){
  string S;
  if (storage_room==true){S="yes";}else{S="no";}
  cout<<"Business Space"<<endl;
  Good::display();
  cout<<"\tSize of the storefront : "<<storefront_size<<endl;
  cout<<"\tStorage room : "<<S<<endl;
}
