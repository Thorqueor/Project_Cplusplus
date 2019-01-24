#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Land.hpp"
using namespace std;


// Default constructor with minimum parameters
Land::Land(int ID, char type, string ref_seller) : Good(ID, type, ref_seller), buildable(true) {}

// Default constructor with parameters
Land::Land(int price, string adress, int surface, int ID, char type, bool buildable, string ref_seller) : Good (price, adress, surface, ID, type, ref_seller), buildable(buildable) {}

// Copy Constructor
Land::Land(const Land &p) : Good(p.price, p.adress, p.surface, p.ID, p.type, ref_seller),buildable(p.buildable) {}

// Destructor
Land::~Land() {}

// Display function
void Land::display(){
  string B;
  if (buildable == true){B="yes";}else{B="no";}
  cout<<"Land"<<endl;
  Good::display();
  cout<<"\tbuildable : "<<B<<endl;
}
