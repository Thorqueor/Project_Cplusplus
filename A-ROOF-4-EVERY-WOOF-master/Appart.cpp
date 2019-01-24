#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Appart.hpp"
using namespace std;


// Default constructor with minimum parameters
Appart::Appart(int ID, char type, string ref_seller) : Good( ID, type, ref_seller), room_nb(2), floor(3), garage(true), cellar(false), balcony(false), total_appart_nb(10) {}

// Default constructor with parameters
Appart::Appart(int price, string adress, int surface, int ID, char type, int room_nb, int floor, bool garage, bool cellar, bool balcony, int total_appart_nb, string ref_seller) : Good(price, adress, surface, ID,type, ref_seller), room_nb(room_nb), floor(floor), garage(garage), cellar(cellar), balcony(balcony), total_appart_nb(total_appart_nb) {}

// Copy Constructor
Appart::Appart(const Appart &p) : Good(p.price, p.adress, p.surface, p.ID, p.type,p.ref_seller), room_nb(p.room_nb), floor(p.floor), garage(p.garage), cellar(p.cellar), balcony(p.balcony), total_appart_nb(p.total_appart_nb) {}

// Destructor
Appart::~Appart() {}

// Display function
void Appart::display(){
  string G;
  string C;
  string B;
  if (garage==true){G="yes";}else{G="no";}
  if (cellar==true){C="yes";}else{C="no";}
  if (balcony==true){B="yes";}else{B="no";}
  cout<<"Appartment"<<endl;
  Good::display();
  cout<<"\tNumber of rooms : "<<room_nb<<endl;
  cout<<"\tFloor : "<<floor<<endl;
  cout<<"\tGarage : "<<G<<endl;
  cout<<"\tCellar : "<<C<<endl;
  cout<<"\tBalcony : "<<B<<endl;
  cout<<"\tGarage : "<<G<<endl;
  cout<<"\tNumber of appartments in the building : "<<total_appart_nb<<endl;
}
