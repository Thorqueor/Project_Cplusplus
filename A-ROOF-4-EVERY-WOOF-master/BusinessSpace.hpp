#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __BusinessSpace__
#define __BusinessSpace__
#include "Good.hpp"
using namespace std;


class BusinessSpace : public Good {

private:
  int storefront_size;
  bool storage_room;

public:
  BusinessSpace(int ID, char type, string ref_seller); // Default constructor without parameters
  BusinessSpace(int price, string adress, int surface, int ID, char type, int storefront_size, bool storage_room, string ref_seller); // Default constructor with parameters
  ~BusinessSpace(); // Destructor
  BusinessSpace(const BusinessSpace &p); // Copy constructor

  void display(); // Display function
  int getStoresize(){return storefront_size;}
  bool getStorageroom(){return storage_room;}
};
#endif
