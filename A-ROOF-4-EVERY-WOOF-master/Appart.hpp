#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Appart__
#define __Appart__
#include "Good.hpp"
using namespace std;


class Appart : public Good {

private:
  int room_nb;
  int floor;
  bool garage;
  bool cellar;
  bool balcony;
  int total_appart_nb;


public:
  Appart(int ID, char type, string ref_seller); // Default constructor with minimum parameters
  Appart(int price, string adress, int surface, int ID, char type,int room_nb, int floor, bool garage,bool cellar,bool balcony,int total_appart_nb,string ref_seller); // Default constructor with parameters
  ~Appart(); // Destructor
  Appart(const Appart &p); // Copy constructor

  void display(); // Display function
  int getNbRoom(){return room_nb;}
  int getFloor(){return floor;}
  bool getGarage(){return garage;}
  bool getCellar(){return cellar;}
  bool getBalcony(){return balcony;}
  int getAppartNumber(){return total_appart_nb;}

};
#endif
