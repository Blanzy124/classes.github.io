#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::cin;

class Product{
 private:
  string name;
  double price;
  int stock;

 public:
 Product(string, double, int);
 ~Product();
 void

};

//Constructor
Product::Product(string _name, double _price, int _stock) : name(_name, _price, _stock){
}
//Destructor
Product::~Product(){
}
