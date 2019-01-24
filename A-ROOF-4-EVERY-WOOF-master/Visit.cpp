#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Visit.hpp"
using namespace std;

// Default constructor without parameters
Visit::Visit() {}

// Default constructor with minimum parameters
Visit::Visit(int ID_visit, int ref_good, string ref_buyer) : ID_visit(ID_visit),ref_good(ref_good),ref_buyer(ref_buyer),proposition(false), proposed_price(0){}

// Default constructor with parameters
Visit::Visit(int ID_visit, bool proposition, int proposed_price, int ref_good, string ref_buyer) : ID_visit(ID_visit), proposition(proposition), proposed_price(proposed_price), ref_good(ref_good), ref_buyer(ref_buyer) {}

// Copy Constructor
Visit::Visit(const Visit &p) : ID_visit(p.ID_visit), proposition(p.proposition), proposed_price(p.proposed_price), ref_good(p.ref_good), ref_buyer(p.ref_buyer) {}

// Destructor
Visit::~Visit() {}

void Visit::display(){
  cout<<"Visit number "<<ID_visit<<endl;
  cout<<"Visitor : "<<ref_buyer<<endl;
  cout<<"ID of the place visited : "<<ref_good<<endl;
  if (proposition == true){
    cout<<"There was a buy offer for the price of : "<<proposed_price<<"euros"<<endl;
  }
  else{
    cout<<"There was no buy offer."<<endl;
  }
}
