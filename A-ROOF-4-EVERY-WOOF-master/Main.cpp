#include <iostream>
#include "Good.hpp"
#include "House.hpp"
#include "Appart.hpp"
#include "Land.hpp"
#include "BusinessSpace.hpp"
#include "Client.hpp"
#include "Buyer.hpp"
#include "Seller.hpp"
#include "Visit.hpp"
#include "Agency.hpp"
using namespace std;

// Functions declarations
void main_menu();
void creation_menu();
void load_menu();
void search_menu();
void display_menu();
void manage_visit_menu();
void save_load_menu();

Agency A = Agency();

void main_menu(){ // Main navigation menu to access sub-menus

  while (true) {
    int choice;
    cout <<"\t\t#############"<<endl;
    cout <<"\t\t# Main Menu #"<<endl;
    cout <<"\t\t#############"<<endl;
    cout << "\nWhat would you like to do ? \n\t1 - Create new goods or clients \n\t2 - Load from text files \n\t3 - Display goods or clients \n\t4 - Search for goods \n\t5 - Manage the visits and sale of goods \n\t6 - Save or load data \n\t0 - Quit" << endl;
    cin >> choice;
    while (choice !=0 and choice !=1 and choice !=2 and choice !=3 and choice !=4 and choice!=5){ //error management
      cout << "Please enter a valid response.";
      cin >> choice;
    }
    if (choice==0){
      A.~Agency();
      return;
    }

    if (choice==1){
      creation_menu();
    }

    if (choice==2){
      load_menu();
    }

    if (choice==3){
      display_menu();
    }

    if (choice==4){
      search_menu();
    }

    if (choice==5){
      manage_visit_menu();
    }

    if (choice==6){
      save_load_menu();
    }
  }
}


void creation_menu(){ //Navigation menu to create certain data
  cout <<"\t\t#################"<<endl;
  cout <<"\t\t# Creation Menu #"<<endl;
  cout <<"\t\t#################"<<endl;
  while (true) {
    int choice2;
    cout<<"\nWhat would you like to do ? \n\t1 - Create a good \n\t2 - Create a client \n\t0 - Return to previous menu"<<endl;
    cin >> choice2;
    while (choice2 !=0 and choice2 !=1 and choice2 !=2){ //error management
      cout << "Please enter a valid response."<<endl;
      cin >> choice2;
    }

    if (choice2==0){
      return;
    }

    if (choice2==1){
      A.good_creator();
    }

    if (choice2==2){
      A.client_creator();
    }
  }
}

void load_menu(){ //Navigation menu to load all data from the text files
  cout <<"\t\t#############"<<endl;
  cout <<"\t\t# Load Menu #"<<endl;
  cout <<"\t\t#############"<<endl;
//just load everything, don't give em a choice
}

void display_menu(){ //Navigation menu to display data
  cout <<"\t\t############"<<endl;
  cout <<"\t\t# Database #"<<endl;
  cout <<"\t\t############"<<endl;
  while (true) {
    int choice3;
    cout<<"\nWhat would you like to do ? \n\t1 - Display all goods \n\t2 - Display all clients \n\t0 - Return to previous menu"<<endl;
    cin >> choice3;
    while (choice3 !=0 and choice3 !=1 and choice3 !=2){ //error management
      cout << "Please enter a valid response."<<endl;
      cin >> choice3;
    }

    if (choice3==0){
      return;
    }

    if (choice3==1){
      A.display_goods();
    }

    if (choice3==2){
      A.display_clients();
    }
  }
}

void search_menu(){ //Navigation menu to search and display certain data
  cout <<"\t\t###############"<<endl;
  cout <<"\t\t# Search Menu #"<<endl;
  cout <<"\t\t###############"<<endl;
  while (true) {
    int choice3;
    cout<<"\nWhat would you like to do ? \n\t1 - Display a type of good under a desired price \n\t2 - Display all the goods sold by a particular client \n\t0 - Return to previous menu"<<endl;
    cin>>choice3;
    while (choice3 !=0 and choice3 !=1 and choice3 != 2){ //error management
      cout<<"Please enter a valid response.";
      cin>>choice3;
    }

    if (choice3==0){
      return;
    }

    if (choice3==1){
      int pricechoice;
      char typechoice;
      cout<<"\nWhat type of good do you want to search for ? \n\th - House \n\ta - Appartment \n\tl - Land \n\tb - Business space"<<endl;
      cin>>typechoice;
      while (typechoice !='a' and typechoice !='h' and typechoice !='l' and typechoice !='b'){ //error management
        cout<<"Please enter a valid response."<<endl;
        cout<<"\nWhat type of good is it ? \n\th - House \n\ta - Appartment \n\tl - Land \n\tb - Business space"<<endl;
        cin>>typechoice;
      }

      cout<<"\nWhat is the maximum price of the goods you want displayed ?"<<endl;
      cin>>pricechoice;
      A.display_by_price(typechoice, pricechoice);
    }

    if (choice3==2){
      bool flag;
      string ref_seller;
      cout<<"Enter the name of the seller whose goods you want displayed."<<endl;
      cin.ignore();
      getline(cin, ref_seller);
      A.display_goods_by_client(ref_seller);
    }
  }
}

void manage_visit_menu(){
  cout <<"\t\t###############"<<endl;
  cout <<"\t\t# Visit and Sale Menu #"<<endl;
  cout <<"\t\t###############"<<endl;
  int choice4;
  cout<<"\nWhat would you like to do ? \n\t1 - Create a Visit \n\t2 - Add a buy offer to an existing visit \n\t3 - Sell a good \n\t0 - Return to previous menu"<<endl;
  cin>>choice4;

  while (choice4 !=0 and choice4 !=1 and choice4 != 2 and choice4 !=3){ //error management
    cout<<"Please enter a valid response.";
    cin>>choice4;
  }

  if (choice4==0){
    return;
  }

  if (choice4==1){
    A.visit_creator();
  }

  if (choice4==2){
    A.add_buyoffer();
  }

  if (choice4==3){
    int Good_id;
    cout<<"Enter the ID of the good to sell."<<endl;
    cin>>Good_id;
    A.good_sale(Good_id);
  }
}

void save_load_menu(){
  cout <<"\t\t###############"<<endl;
  cout <<"\t\t# Load and Save Menu #"<<endl;
  cout <<"\t\t###############"<<endl;
  int choice4;
  cout<<"\nWhat would you like to do ? \n\t1 -Save data \n\t2 - Load data \n\t0 - Return to previous menu"<<endl;
  cin>>choice4;

  while (choice4 !=0 and choice4 !=1 and choice4 != 2){ //error management
    cout<<"Please enter a valid response.";
    cin>>choice4;
  }

  if (choice4==0){
    return;
  }

  if (choice4==1){
    A.save_good();
    A.save_buyer();
    A.save_seller();
    A.save_visit();

  }

  if (choice4==2){
    A.load_good();
    A.load_buyer();
    A.load_seller();
    A.load_visit();
  }
}

int main() { //Main, launches all the navigation menus
  int cmpt=0;

  cout <<"\t#################################################"<<endl;
  cout <<"\t# Hi ! Welcome to the app for aROOF4everyWOOF ! #"<<endl;
  cout <<"\t#################################################\n\n"<<endl;
/*
  Appart A1= Appart(cmpt++, 'a' , "Jean-Claude");
  Appart A2= Appart(cmpt++, 'a', "Marcus");
  Appart A3 = Appart(A2);
  House H1= House(cmpt++, 'h', "Fabrice");
  Land L1= Land(cmpt++, 'l', "Giselle");
  BusinessSpace BS1= BusinessSpace(cmpt++, 'b', "Hector");
  Land L2= Land(50000, "42, Meaning Street", 60, cmpt++, 'l', true, "Josef");

  Buyer C2= Buyer("Médor", "46, Ulna Boulevard", 'b');
  Seller C3= Seller("Rex", "85, Metacarpus Avenue", 's');
  Seller C4= Seller("Filibert", "91, Patella St.", 's');
  Buyer C5= Buyer("Dale", "1408, Cooper Street", 'b');
 */
  main_menu();
  return 0;
}
