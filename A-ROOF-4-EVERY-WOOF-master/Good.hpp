#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Good__
#define __Good__
using namespace std;


class Good{

protected:
  int price;
  string adress;
  int surface;
  string ref_seller; //Should correspond to the map key of the seller of this good.
  int ID; //unique
  char type; // h=house, a=appart, l=land, b=business space


public:
  Good(); // Default constructor without parameter
  Good(int ID, char type, string ref_seller); // Default constructor with minimum parameters
  Good(int price, string adress, int surface, int ID, char type, string ref_seller); // Default constructor with parameters
  ~Good(); // Destructor
  Good(const Good &p); // Copy constructor



//Getter
int getPrice(){return price;}
string getAdress(){return adress;}
int getSurface(){return surface;}
int getID(){return ID;}
char getType(){return type;}
string getRefseller(){return ref_seller;}
void display(); // Display function

};
#endif
