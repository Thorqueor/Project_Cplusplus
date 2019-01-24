#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Buyer__
#define __Buyer__
using namespace std;


class Buyer : public Client {

public:
  Buyer(); // Default constructor without parameter
  Buyer(char type); // Default constructor with minimum parameters
  Buyer(string name, string adress, char type); // Default constructor with parameters
  ~Buyer(); // Destructor
  Buyer(const Buyer &p); // Copy constructor

void display(); // Display function

};
#endif
