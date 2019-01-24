#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Visit__
#define __Visit__
using namespace std;


class Visit {

private:
  int ID_visit;
  bool proposition;
  int proposed_price;
  int ref_good; //mapped to Good ID
  string ref_buyer; //mapped to Client name

public:
  Visit(); // Default constructor without parameter
  Visit(int ID_visit, int ref_good,std::string ref_buyer); // Default constructor with minimum parameters
  Visit(int ID_visit, bool proposition, int proposed_price, int ref_good,std::string ref_buyer); // Default constructor with parameters
  ~Visit(); // Destructor
  Visit(const Visit &p); // Copy constructor

//////GETTERS///////
int getID(){return ID_visit;}
int get_ref_good(){return ref_good;}
string get_ref_buyer(){return ref_buyer;}
bool get_Proposition_status(){return proposition;}
int get_proposed_price(){return proposed_price;}

//////SETTERS///////
void set_price(int newprice){this->proposed_price = newprice;}
void set_proposition(bool flag){this->proposition = flag;}

void display();
};
#endif
