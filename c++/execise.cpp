#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::cin;

/////
class Product{
 protected:
 string name;
 double price;
 int stock;
 
 public:
    Product(string, double, int);
    virtual ~Product();
 
 //Method
 virtual void showProdut();
 
 //getters
 string getName(){
  return name;
 };
 double getPrice(){
  return price;
 };
 int getStock(){
  return stock;
 };
};

//Constructor
Product::Product(string _name, double _price, int _stock) : name(_name), price(_price), stock(_stock) {}
//Destructor
Product::~Product(){
}
//Methods
void Product::showProdut(){
 cout<<"Name: "<<name<<" |Price: "<<price<<" |Stock: "<<stock<<endl;
}
///
void closeOptions();
void addProduct(vector<Product*>& products);

void showTotalInventaryPrice(vector<Product*>& products);
void showFullInventary(vector<Product*>& products);


void showSimpleSentence(string message){
 cout<<message;
};

vector<Product*> products;

int main(){
 int newProducts;
 int mainMenuObtions;
 
 
 showSimpleSentence("What do you want to do? \n");
 showSimpleSentence("Option 1: add a new product\n");
 showSimpleSentence("Option 2: show all the inventary\n");
 showSimpleSentence("Option 3: show total inventary price\n");
 showSimpleSentence("Anything else to close\n");
 try
 {
     cin>>mainMenuObtions;
    
 }
 catch(const std::exception& e)
 {
    showSimpleSentence("Input Error");
    std::cerr << e.what() << '\n';
 }
 
 cin.ignore();
 switch (mainMenuObtions)
 {
 case 1:
     addProduct(products);
     break;
 case 2:
     showFullInventary(products);
     break;
 case 3:
     showTotalInventaryPrice(products);
     break;
 default:
     for (auto& product : products)
     {
         product->~Product();
     }
     break;
 }
 return 0;
}


void closeOptions(){
 int closeOption;
 showSimpleSentence("Write 1 to go back to main menu: ");
 cin>>closeOption;
 if(closeOption == 1){
     main();
 }
 else{
     exit(0);
 }
 return;
};


void addProduct(vector<Product*>& products){
 int newProducts;
 showSimpleSentence("How many products you would like add? ");
 try
 {
  cin>>newProducts;
 }
 catch(const runtime_error& e)
 {
  cout<<e.what();
  showSimpleSentence("Must be numbers only...");
  closeOptions();
  return;
 };
 for ( int i = 0; i < newProducts; i++)
 {   
   cin.ignore();
   string newProductName;
   double newProductPrice;
   int newProductStock;
   cout<<"What is the name for the product number "<<i + 1<<"? :";
   getline(cin, newProductName);
   cout<<"What is the price for the product number "<<i + 1<<"? :";
   cin>>newProductPrice;
   cout<<"What is the new units stock for the product number "<<i + 1<<"? :";
   cin>>newProductStock;
   products.push_back(new Product(newProductName, newProductPrice, newProductStock));
   if (i == newProducts - 1)
   {
    showSimpleSentence("Product/s has been add\n");
    cout<<"number of products in stock "<<products.size()<<endl;
   }
   
 }
 closeOptions();
 return;
};

void showFullInventary(vector<Product*>& products){
    for(auto& product : products){
        product->showProdut();
    }
    closeOptions();
}

void showTotalInventaryPrice(vector<Product*>& products){
    double totalInventary = 0;
    if (products.size() == 0)
    {
        cout<<"There are not products";
        closeOptions();
    }
    
    for (auto& product : products)
    {
        totalInventary += product->getPrice() + product->getStock();
        
    }
    cout<<"Total inventary value is :"<<(double)totalInventary<<endl;
    closeOptions();
};