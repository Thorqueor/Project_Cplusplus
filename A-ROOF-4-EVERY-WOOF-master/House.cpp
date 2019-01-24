#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "House.hpp"
using namespace std;


// Default constructor with minimum parameters
House::House(int ID, char type, string ref_seller) : Good(ID, type, ref_seller), room_nb(4), garage(true), garden(true), pool(false) {}

// Default constructor with parameters
House::House(int price, string adress, int surface, int ID, char type, int room_nb, bool garage, bool garden, bool pool, string ref_seller) : Good(price, adress, surface, ID, type, ref_seller), room_nb(room_nb), garage(garage), garden(garden), pool(pool) {}

// Copy Constructor
House::House(const House &p) : Good(p.price, p.adress, p.surface, p.ID, p.type, p.ref_seller), room_nb(p.room_nb), garage(p.garage), garden(p.garden), pool(p.pool) {}

// Destructor
House::~House() {}

// Display function
void House::display(){
  string G;
  string GA;
  string P;
  if (garage==true){G="yes";}else{G="no";}
  if (garden==true){GA="yes";}else{GA="no";}
  if (pool==true){P="yes";}else{P="no";}
  cout<<"House"<<endl;
  Good::display();
  cout<<"\tNumber of rooms : "<<room_nb<<endl;
  cout<<"\tGarage : "<<G<<endl;
  cout<<"\tGarden : "<<GA<<endl;
  cout<<"\tPool : "<<P<<endl;
}
