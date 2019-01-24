#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#ifndef __Agency__
#define __Agency__
using namespace std;

//save all info here
//aRoof4everyWoof


class Agency {
private:
  map <string, Buyer*> BuyerList;
  map <string, Seller*> SellerList;
  map <int, Good*> GoodsList;
  map <int, Visit*> VisitList;



public:
  Agency(); //default constructor
  Agency(const Agency &p); //copy constructor
  ~Agency(); //destructor



  void add_good(Good newGood); //creation of new Good type object
  void add_buyoffer(); //creation of new buy offer
  void add_buyer(Buyer c); //creation of new Buyer type Client object
  void add_seller(Seller c); //creation of new Seller type Client object
  bool check_seller(string IDcheck); //check if seller name already exists
  bool check_buyer(string IDcheck); //check if buyer name already exists
  bool check_good(int IDcheck); //check if good ID already exists
  bool check_visit(int ref_visit);
  void client_creator(); //function to add a new Client to the Agency
  void good_creator(); //function to add a new Good to the Agency
  void visit_creator(); //fucnction to add a new Visit

  void display_clients(); //function to display all clients in the database
  void display_goods(); //function to display all goods in the database
  void display_by_price(char type, int pricemax); //display function for goods under a certain price
  void display_goods_by_client(string clientID); //display all the goods sold by a predetermined client.

  void good_sale(int Good_id);
/**
  void save_good(); //fucnction to save the list of Good objects
  void load_good(); //fucnction to load the list of Good objects
  void save_buyer(); //fucnction to save the list of Buyer objects
  void load_buyer(); //fucnction to load the list of Buyer objects
  void save_seller(); //fucnction to save the list of Seller objects
  void load_seller(); //fucnction to load the list of Seller objects
  void save_visit(); //fucnction to save the list of Visit objects
  void load_visit(); //fucnction to load the list of Visit objects
**/


//Getters
  map <int, Good*> getGoodsList(){return GoodsList;}


};
#endif
