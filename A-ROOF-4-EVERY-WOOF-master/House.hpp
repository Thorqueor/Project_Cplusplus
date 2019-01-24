#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __House__
#define __House__
#include "Good.hpp"
using namespace std;


class House : public Good {

private:
  int room_nb;
  bool garage;
  bool garden;
  bool pool;

public:
  House(int ID, char type, string ref_seller); // Default constructor with minimum parameters
  House(int price, string adress, int surface, int ID, char type, int room_nb, bool garage,bool garden, bool pool, string ref_seller); // Default constructor with parameters
  ~House(); // Destructor
  House(const House &p); // Copy constructor

  void display(); // Display function
  int getRoomNb(){return room_nb;}
  bool getGarage(){return garage;}
  bool getGarden(){return garden;}
  bool getPool(){return pool;}
};
#endif
