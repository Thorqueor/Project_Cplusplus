#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <fstream>
#include "Visit.hpp"
#include "Good.hpp"
#include "Appart.hpp"
#include "House.hpp"
#include "Land.hpp"
#include "BusinessSpace.hpp"
#include "Client.hpp"
#include "Buyer.hpp"
#include "Seller.hpp"
#include "Agency.hpp"

using namespace std;

//save all info here
//aRoof4everyWoof

int good_cpt=0;
int visit_cpt=0;

Agency::Agency(){}

Agency::Agency(const Agency &p) : BuyerList(p.BuyerList), SellerList(p.SellerList), GoodsList(p.GoodsList), VisitList(p.VisitList) {}

Agency::~Agency() {
  for(map<string, Buyer*>::iterator itr = BuyerList.begin(); itr != BuyerList.end(); itr++){
    delete (itr->second);
  }
  BuyerList.clear();

  for(map<string, Seller*>::iterator itr = SellerList.begin(); itr != SellerList.end(); itr++){
    delete (itr->second);
  }
  SellerList.clear();

  for(map<int, Good*>::iterator itr = GoodsList.begin(); itr != GoodsList.end(); itr++){
    delete (itr->second);
  }
  GoodsList.clear();

  for(map<int, Visit*>::iterator itr = VisitList.begin(); itr != VisitList.end(); itr++){
    delete (itr->second);
  }
  VisitList.clear();
}

/*
PRICING AND SELLING FUNCTIONS
*/


void Agency::add_buyoffer(){ //creation of new buy offer
  bool flag;
  bool previous_proposition;
  int price;
  int visit_id;
  cout<<"Enter the id of the visit where the proposition was made ?"<<endl;
  cin >> visit_id;
  flag = check_visit(visit_id);
  if (flag == false){
    cout<<"Sorry, this id doesn't exist in our system."<<endl;
    return;
  }

  previous_proposition = VisitList[visit_id]->get_Proposition_status();
  if (previous_proposition == true){
    cout<<"It seems a buy offer was already done for this visit, maybe you made a mistake ?"<<endl;
    return;
  }

  cout<<"What was the proposed price ?"<<endl;
  cin>>price;
  VisitList[visit_id]->set_proposition(true);
  VisitList[visit_id]->set_price(price);
  cout<<"The buyoffer has been added !"<<endl;
}


/*
CREATION FUNCTIONS
*/

bool Agency::check_buyer (string IDcheck){ //checks if Buyer already exists
  if (BuyerList.find(IDcheck) == BuyerList.end()){
    return false;
  }
  else{
    return true;
  }
}


bool Agency::check_seller (string IDcheck){ //checks if Seller already exists
  if (SellerList.find(IDcheck) == SellerList.end()){
    return false;
  }
  else{
    return true;
  }
}


bool Agency::check_good (int ref_good){ //check if good ID already exists
  if (GoodsList.find(ref_good) ==  GoodsList.end()){
    return false;
  }
  else{
    return true;
  }
}

bool Agency::check_visit (int ref_visit){
  if (VisitList.find(ref_visit) ==  VisitList.end()){
    return false;
  }
  else{
    return true;
  }
}


void Agency::client_creator(){ //function to add a new Client to the Agency
  bool flag;
  string name;
  string adress;
  int choice;
  int validation;
  cout  << "What is the Client's name ?" << endl;
  cin.ignore();
  getline(cin, name);
  cout  << "\nName is : \"" << name << "\", is it alright ? \n\t1 - Yes \n\t2 - No" << endl;
  cin >> validation;
  if (validation == 2) {
    cout << "Please enter a new name." << endl;
    cin.ignore();
    getline(cin, name);
  }
  cout  << "What is the Client's adress ?" << endl;
  cin.ignore();
  getline(cin, adress);
  cout  << "\nAdress is : \"" << adress << "\", is it alright ? \n\t1 - Yes \n\t2 - No" << endl;
  validation=0;
  cin >> validation;
  if (validation == 2) {
    cout << "Please enter a new adress." << endl;
    cin.ignore();
    getline(cin, adress);
  }

  cout << "Is the Client : \n\t1 - a Buyer \n\t2 - a Seller" << endl;
  cin  >>  choice;
  while (choice != 1 and choice !=2) {
    cout << "Please enter a valid answer." << endl;
    cout << "Is the Client : \n\t1 - a Buyer \n\t2 - a Seller" << endl;
    cin.ignore();
    cin  >>  choice;
  }
  if (choice==1){
    flag = check_buyer(name);
    if (flag == true){
      cout<<"Sorry, a buyer with that name already exists.";
      return;
    }
    char type= 'b';
    BuyerList[name] = new Buyer(name, adress, type);
    cout<<"Buyer successfully added !"<<endl;
    }
  else if (choice ==2){
    flag = check_seller(name);
    if (flag == true){
      cout<<"Sorry, a seller with that name already exists.";
      return;
    }
    char type= 's';
    SellerList[name] = new Seller(name, adress, type);
    cout<<"Seller successfully added !"<<endl;
  }
}


void Agency::good_creator(){ //function to add a new Good to the Agency
  string sellername;
  int price;
  string adress;
  int surface;
  int id;
  char type;

  cout << "Who is selling the good ?" << endl;
  cin.ignore();
  getline(cin, sellername); //Seller Reference

  bool flag = check_seller(sellername);
  if (flag == false){
    cout << "It seems this seller isn't in our database" << endl;
    return;
  }

  cout << "What is the adress of the good ?" << endl;
  cin.ignore();
  getline(cin, adress); //Good Adress
  cout << "What is the surface in square meters ?" << endl;
  cin >> surface;
  id=good_cpt++; //ID increment
  cout << "What is the price of the good ?" << endl;
  cin >> price;
  cout << "What type of good is it ? \n\th - House \n\ta - Appartment \n\tl - Land \n\tb - Business space" << endl;
  cin >> type;
  while (type !='a' and type !='h' and type !='l' and type !='b'){
    cout << "Please enter a valid response." << endl;
    cout << "What type of good is it ? \n\th - House \n\ta - Appartment \n\tl - Land \n\tb - Business space" << endl;
    cin >> type;
  }

  if (type == 'h'){ //if the Good is a House
    int roomnumber;
    bool garage;
    bool garden;
    bool pool;
    string temp="";
    cout << "How many rooms are there in the house ?" << endl;
    cin >> roomnumber;
    cout << "Is there a garage ? yes/no" << endl;
    cin >> temp;
    while (temp!="yes" and temp!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a garage ? yes/no" << endl;
      cin >> temp;
    }
    if (temp == "yes"){
      garage=true;
    }
    if (temp == "no"){
      garage = false;
    }

    temp="";

    cout << "Is there a garden ? yes/no" << endl;
    cin >> temp;
    while (temp!="yes" and temp!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a garden ? yes/no" << endl;
      cin >> temp;
    }
    if (temp == "yes"){
      garden=true;
    }
    if (temp == "no"){
      garden = false;
    }

    temp="";

    cout << "Is there a pool ? yes/no" << endl;
    cin >> temp;
    while (temp!="yes" and temp!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a pool ? yes/no" << endl;
      cin >> temp;
    }
    if (temp == "yes"){
      pool=true;
    }
    if (temp == "no"){
      pool = false;
    }
    GoodsList[id] = new House(price,adress,surface,id,type,roomnumber,garage,garden,pool,sellername);
    cout << "\nNew House successfully added !\nHere are the info you entered :" << endl;
    SellerList[sellername]->add_good(id);
    GoodsList[id]->display(); //THIS SHOULD WORK
    //House.display();
  }

  if (type == 'a'){ //if the Good is an Appartment
    int room_nb;
    int cur_floor;
    bool garage;
    bool cellar;
    bool balcony;
    int total_appart_nb;
    string temp2;

    cout << "How many rooms does the appartment have ?" << endl;
    cin >> room_nb;
    cout << "At what floor is the appartment located ?" << endl;
    cin >> cur_floor;
    cout << "How many other appartments are there in the building ?" << endl;
    cin >> total_appart_nb;

    cout << "Is there a garage ? yes/no" << endl;
    cin >> temp2;
    while (temp2!="yes" and temp2!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a garage ? yes/no" << endl;
      cin >> temp2;
    }
    if (temp2 == "yes"){
      garage=true;
    }
    if (temp2 == "no"){
      garage = false;
    }

    temp2="";

    cout << "Is there a cellar ? yes/no" << endl;
    cin >> temp2;
    while (temp2!="yes" and temp2!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a cellar ? yes/no" << endl;
      cin >> temp2;
    }
    if (temp2 == "yes"){
      cellar=true;
    }
    if (temp2 == "no"){
      cellar = false;
    }

    temp2="";

    cout << "Is there a balcony ? yes/no" << endl;
    cin >> temp2;
    while (temp2!="yes" and temp2!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a balcony ? yes/no" << endl;
      cin >> temp2;
    }
    if (temp2 == "yes"){
      balcony=true;
    }
    if (temp2 == "no"){
      balcony = false;
    }
    GoodsList[id] = new Appart(price,adress,surface,id,type,room_nb,cur_floor,garage,cellar,balcony,total_appart_nb,sellername);
    cout << "\nNew Appartement successfully added !\nHere are the info you entered :" << endl;
    SellerList[sellername]->add_good(id);
    GoodsList[id]->display();
    //Appart.display();
  }

  if (type == 'l'){ //if the Good is a Land
    bool buildable;
    string temp3;
    cout << "Is the land buildable ? yes/no" << endl;
    cin >> temp3;
    while (temp3!="yes" and temp3!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is the land buildable ? yes/no" << endl;
      cin >> temp3;
    }
    if (temp3 == "yes"){
      buildable=true;
    }
    if (temp3 == "no"){
      buildable = false;
    }
    GoodsList[id] = new Land(price,adress,surface,id,type,buildable,sellername);
    SellerList[sellername]->add_good(id);
    cout << "\nNew good successfully added !\nHere are the info you entered :" << endl;
    GoodsList[id]->display();
    //Land.display();
  }

  if (type == 'b'){ //if the Good is a Business Space
    int storefront_size;
    bool storage_room;
    string temp4;
    cout << "What is the size of the storefront ?" << endl;
    cin >> storefront_size;
    cout << "Is there a storage room ? yes/no" << endl;
    cin >> temp4;
    while (temp4!="yes" and temp4!="no"){
      cout << "Please enter a valid response." << endl;
      cout << "Is there a storage room ? yes/no" << endl;
      cin >> temp4;
    }
    if (temp4 == "yes"){
      storage_room = true;
    }
    if (temp4 == "no"){
      storage_room = false;
    }
    GoodsList[id] = new BusinessSpace(price,adress,surface,id,type,storefront_size,storage_room,sellername);
    SellerList[sellername]->add_good(id);
    cout << "\nNew Business Space successfully added !\nHere are the info you entered :" << endl;
    GoodsList[id]->display();
    //BusinessSpace.display();
  }
}

void Agency::visit_creator(){ //fucnction to add a new Visit
  int ID;
  int ref_good;
  string ref_buyer;
  bool proposition;
  int proposed_price;
  string temp;

  ID=visit_cpt++;
  cout << "Enter the reference for the good being visited." << endl;
  cin >> ref_good;
  bool flag2 = check_good(ref_good);
  if(flag2 == false){
    cout << "This good doesn't exist in our database." << endl;
    return;
  }

  cout << "What is the name of the person visiting ?" << endl;
  cin.ignore();
  getline(cin, ref_buyer);
  bool flag = check_buyer(ref_buyer);
  if (flag == false){
    cout << "It seems this buyer isn't in our database" << endl;
    return;
  }

  cout << "Has a buy offer been proposed ? yes/no" << endl;
  cin >> temp;
  while (temp!="yes" and temp!="no"){
    cout << "Please enter a valid response." << endl;
    cout << "Has a buy offer been proposed ? yes/no" << endl;
    cin >> temp;
  }
  if (temp == "yes"){
    proposition = true;
    cout << "What price was proposed ?"  <<  endl;
    cin >> proposed_price;

    VisitList[ID] = new Visit(ID,proposition,proposed_price,ref_good,ref_buyer);
    //VisitList[ID]=V;
  }
  if (temp == "no"){
    proposition = false;
    proposed_price=0;
    VisitList[ID] = new Visit(ID,proposition,proposed_price,ref_good,ref_buyer);
    //Visit V = Visit(ID,ref_good,ref_buyer);
    //VisitList[ID]=V;
  }
}

/**
                                    DISPLAY FUNCTIONS
**/

void Agency::display_clients(){ //function to display all clients in the database
  cout <<"\n\t\t###########"<<endl;
  cout <<"\t\t# Clients #"<<endl;
  cout <<"\t\t###########\n"<<endl;
  return;
}

void Agency::display_goods(){ //function to display all goods in the database
  cout <<"\n\t\t#########"<<endl;
  cout <<"\t\t# Goods #"<<endl;
  cout <<"\t\t#########\n"<<endl;
  return;
}

void Agency::display_by_price(char type, int pricemax){ //display function for goods under a certain price
  map <int,Good*>::iterator it;
  for (it = GoodsList.begin(); it!=GoodsList.end(); ++it){
    if(it->second->getType()==type and it->second->getPrice()<=pricemax){
      it->second->display();
    }
  }
}

void Agency::display_goods_by_client(string clientID){
  bool flag = check_seller(clientID);
  map <int, Good*>::iterator ter;
  if (flag==false){
    cout<<"Sorry, it seems this name isn't in our sellers database."<<endl;
    return;
  }
  vector<int> listID = SellerList[clientID]->getGoods_vector();
  for (int i = 0; i < listID.size(); i++) {
    GoodsList[listID[i]]->display();
  }
  /*
  for (ter = GoodsList.begin(); ter!=GoodsList.end();++ter){
    if(ter->second->getRefseller()==clientID){
      it->second->display();
    }
  }
  */
}


/*
                                    SALE FUNCTIONS
*/

void Agency::good_sale(int Good_id){
  vector<int> Visit_ids;
  string name;
  string Choice_name;
  int price;
  map<string,int> Table;
  map<string,int>::iterator it;
  map<int, Visit*>::iterator Visit_it;
  bool proposition_flag;
  bool flag = check_good(Good_id);
  if (flag==false){
    cout<<"Sorry, this good doesn't exist."<<endl;
    return;
  }

  for (Visit_it = VisitList.begin();Visit_it != VisitList.end();++Visit_it){
    if (Visit_it->second->get_ref_good()==Good_id){
      Visit_ids.push_back(Visit_it->first);
      proposition_flag = Visit_it->second->get_Proposition_status();
      if (proposition_flag==true){
        name=Visit_it->second->get_ref_buyer();
        price=Visit_it->second->get_proposed_price();
        Table[name]=price;
      }
    }
  }
  if (Table.empty()==true){
    cout<<"It seems no buyer has ever visited this good, or no buy offer has been made. Organize a visit before you can sell it."<<endl;
    return;
  }
  cout<<"List of Buyers interested in buying this good : "<<endl;
  for (it=Table.begin(); it!=Table.end();++it){
    cout<<"Name : "<<it->first<<" Price offered : "<<it->second<<endl;
  }
  cout<<"Who does the seller want to sell to ?"<<endl;
  cin.ignore();
  getline(cin, Choice_name);
  while(Table.find(Choice_name)==Table.end()){
    cout<<"This name isn't part of the clients displayed."<<endl;
    cin.ignore();
    getline(cin, Choice_name);
  }
  cout<<"Sale confirmed to "<<Choice_name<<endl;
  GoodsList.erase(Good_id);
  for (int i = 0;i <Visit_ids.size();i++){
  VisitList.erase(Visit_ids[i]);
  }
  cout<<"Sale done, data deleted."<<endl;
}


/**
                                    SAVE AND LOAD FUNCTIONS
**/

/** NON FUNCTIONAL

void Agency::save_good(){ //fucnction to save the list of Good objects
  ofstream fichier("Good.txt", ios::out - ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
  map <int,Good>::iterator ter;
    if(fichier){
      for (ter = GoodsList.begin(); ter!=GoodsList.end();++ter){
        fichier << ter -> second->getType() << ter -> second->getPrice() << ter -> second->getAdress() << ter -> second.getSurface() << ter -> second->getID() << ter -> second->getRefseller();
        if(ter -> second->getType() == 'a')
          fichier << ter -> second->getNbRoom() << ter -> second->getFloor() << ter -> second->getGarage() << ter -> second->getCellar() << ter -> second->getBalcony() << ter -> second->getAppartNumber() << endl;
        else if(ter -> second->getType() == 'b')
          fichier << ter -> second->getStoresize() << ter -> second->getStorageroom() << endl;
        else if(ter -> second->getType() == 'h')
          fichier << ter -> second->getRoomNb() << ter -> second->getGarage() << ter -> second->getGarden() << ter -> second->getPool() << endl;
        else if(ter -> second->getType() == 'l')
          fichier << ter -> second->getBuildable() << endl;
        }
      fichier.close();
    }
    else{cerr << "/!/ cannot open file /!/" << endl;}
}

void Agency::load_good(){ //fucnction to load the list of Good objects
    ifstream fichier("Good.txt", ios::in);

    if(fichier)
    {
      bool flag
      char type;
      int nb_room, floor, total_appart_nb, price, surface, ID, storefront_size, room_nb;
      bool garage, cellar, balcony, storage_room, garden, pool, buildable;
      string adress, ref_seller;
      fichier >> type >> price >> adress >> surface >> ID >> ref_seller;
      flag = check_good(ID);
      if (flag == true){
        cout<<"This ID already exists."<<endl;
        return;
      }
      if (type == 'a'){
        fichier >> nb_room  >> floor >> garage >> cellar >> balcony >> total_appart_nb;
        GoodsList[ID] = new Appart(price, adress, surface, compt, type, room_nb, floor, garage, cellar, balcony, total_appart_nb, ref_seller);
      }
      else if(type == 'b'){
        fichier >> storefront_size >> storage_room;
        GoodsList[ID] = new BusinessSpace(price, adress, surface, compt, type, storefront_size, storage_room, ref_seller);
      }
      else if(type == 'h'){
        fichier >> room_nb >> garage >> garden >> pool;
        GoodsList[ID] = new House(price, adress, surface, compt, type, room_nb, garage, garden, pool, ref_seller);
      }
      else if(type == 'l'){
        fichier >> buildable;
        GoodsList[ID] = new Land(price, adress, surface, compt, type, buildable, ref_seller);
      }
fichier.close();
    }
    else{cerr << "/!/ cannot open file /!/" << endl;}
}

void Agency::save_buyer(){ //fucnction to save the list of Buyer objects
  ofstream fichier("Buyer.txt", ios::out - ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
  map <string,Buyer>::iterator ator;
    if(fichier){
      for (ator =BuyerList.begin();ator=BuyerList.end();++ator){
        //Buyer p = ator->second;
        fichier << ator->second->getType() << ator->second->getName() << ator->second->getCAdress() endl;
      }
      fichier.close();
    }
    else
    cerr << "/!/ cannot open file /!/" << endl;
}

void Agency::load_buyer(){ //fucnction to load the list of Buyer objects
  bool flag3;
  ifstream fichier("Buyer.txt", ios::in);
  if(fichier){
    char type;
    string name,adress;
    fichier >> type >> name >> adress;
    flag3 = check_buyer(name);
    if (flag3 == true){
      cout<<"A buyer with this name already exists."
      return;
    }
    else{
      BuyerList[name]= new Buyer(name,adress,type);;
    }
    fichier.close();
  }
  else{
    cerr << "/!/ cannot open file /!/" << endl;
  }
}

void Agency::save_seller(){ //fucnction to save the list of Seller objects
  ofstream fichier("Seller.txt", ios::out - ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
  map <string,Seller>::iterator hator;
    if(fichier){
      for (hator =SellerList.begin();hator=SellerList.end();++hator){
        Seller p = hator->second;
      fichier << hator->second->getType() << hator->second->getName() << hator->second->getCAdress() endl;
    }
      fichier.close();
    }
    else{cerr << "/!/ cannot open file /!/" << endl;}
}

void Agency::load_seller(){ //fucnction to load the list of Seller objects
  bool flag4;
  ifstream fichier("Seller.txt", ios::in);

    if(fichier)
    {

      char type;
      string name,adress;
      fichier >> type >> name >> adress;
      flag4 = check_seller(name);
      if (flag4 == true){
        cout<<"A seller with this name already exists."
        return;
      }
      else{
        Seller S = Seller(name,adress,type);
        SellerList[name]= new Seller(name,adress,type);
      }
      fichier.close();
    }
    else{cerr << "/!/ cannot open file /!/" << endl;}
}


void Agency::save_visit(){ //fucnction to save the list of Visit objects

  ofstream fichier("visit.txt", ios::out - ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

    if(fichier){
      map <int,Visit>::iterator hattori;
        if(fichier){
          for (hattori = VisitList.begin(); hattori= VisitList.end(); ++hattori){
            Visit p = hattori->second;
      fichier << hattori->second->getID() << hattori->second->get_Proposition_status() << hattori->second_>get_proposed_price() << hattori->second->get_ref_good() << hattori->second->get_ref_buyer() << endl;
    }
      fichier.close();
    }
    else{cerr << "/!/ cannot open file /!/" << endl;}
  }
}

 void Agency::load_visit(){ //fucnction to load the list of Visit objects
   ifstream fichier("visit.txt", ios::in);

   if(fichier){
     int ID_visit;
     bool proposition;
     int proposed_price, ref_good;
     string ref_buyer;
     fichier >> ID_visit >> proposition >> proposed_price >> ref_good >> ref_buyer;
     //Visit V1 = Visit(ID_visit, proposition, proposed_price, ref_good, ref_buyer);
     VisitList[ID_visit] =  new Visit(ID_visit, proposition, proposed_price, ref_good, ref_buyer);
     fichier.close();
   }
   else{cerr << "/!/ cannot open file /!/" << endl;}
 }
**/
