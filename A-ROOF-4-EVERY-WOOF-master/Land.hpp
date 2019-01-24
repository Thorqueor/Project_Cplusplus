#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Land__
#define __Land__
#include "Good.hpp"
using namespace std;


class Land : public Good {

private:
  bool buildable;

public:
  Land(int ID, char type, string ref_seller); // Default constructor with minimum parameters
  Land(int price, string adress, int surface, int ID, char type, bool buildable, string ref_seller); // Default constructor with parameters
  ~Land(); // Destructor
  Land(const Land &p); // Copy constructor

  void display(); // Display function
  bool getBuildable(){return buildable;}
};
#endif
