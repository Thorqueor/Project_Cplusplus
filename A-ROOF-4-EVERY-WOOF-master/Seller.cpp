#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include "Client.hpp"
#include "Seller.hpp"
using namespace std;

// Default constructor without parameter
Seller::Seller() : Client('b') {}

// Default constructor with minimum parameters
Seller::Seller(char type) : Client(type) {}

// Default constructor with parameters
Seller::Seller(string name, string adress, char type) : Client(name, adress, type) {}

// Copy Constructor
Seller::Seller(const Seller &p) : Client(p.name, p.adress, p.type), Goods_vector(p.Goods_vector) {}

// Destructor
Seller::~Seller() {}

// Display function
void Seller::display(){
  cout<<"Seller"<<endl;
  Client::display();
  cout<<"\tList of selling goods : " << endl;
}

void Seller::add_good(int id){Goods_vector.push_back(id);}
