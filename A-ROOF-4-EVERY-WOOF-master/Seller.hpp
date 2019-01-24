#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Seller__
#define __Seller__
using namespace std;


class Seller : public Client {
protected:
  vector<int> Goods_vector;
public:
  Seller(); // Default constructor without parameter
  Seller(char type); // Default constructor with minimum parameters
  Seller(string name, string adress, char type); // Default constructor with parameters
  ~Seller(); // Destructor
  Seller(const Seller &p); // Copy constructor

vector<int> getGoods_vector(){return Goods_vector;}

void display(); // Display function
void add_good(int id);

};
#endif
