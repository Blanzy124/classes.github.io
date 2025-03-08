#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::cin;
struct products{
    string name;
    double price;
    int stock;
};

void closeOptions();
void addProduct(vector<products>* product);
void showTotalInventaryPrice(vector<products>& products);

void showSimpleSentence(string message){
    cout<<message;
};


void showFullInventary(vector<products>& product){
    cout<<"number of products in stock "<<product.size()<<endl;
    for (const auto &p : product)
    {
        cout<<"Name: "<<p.name<<"  "<<"Price: "<<p.price<<"  "<<"Stock: "<<p.stock<<endl;
    }
    closeOptions();
    return;
};

int main(){
    int newProducts;
    int mainMenuObtions;
    static vector<products> product;
    showSimpleSentence("What do you want to do? \n");
    showSimpleSentence("Option 1: add a new product\n");
    showSimpleSentence("Option 2: show all the inventary\n");
    showSimpleSentence("Option 3: show total inventary price\n");
    showSimpleSentence("Option 4: close program\n");
    cin>>mainMenuObtions;
    cin.ignore();
    switch (mainMenuObtions)
    {
    case 1:
        addProduct(&product);
        break;
    case 2:
        showFullInventary(product);
        break;
    case 3:
        showTotalInventaryPrice(product);
        break;
    case 4:
        break;
    default:
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
        exit(1);
    }
    return;
};



void addProduct(vector<products>* product){
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
        products p;

        cout<<"What is the name for the product number "<<i + 1<<"? :";
        getline(cin, p.name);
        cout<<"What is the price for the product number "<<i + 1<<"? :";
        cin>>p.price;
        cout<<"What is the new units stock for the product number "<<i + 1<<"? :";
        cin>>p.stock;
        product->push_back(p);
    }
    showSimpleSentence("Product/s has been add\n");
    cout<<"number of products in stock "<<product->size()<<endl;
    closeOptions();
    return;
};

void showTotalInventaryPrice(vector<products>& products){
    double totalInventary = 0;
    if (products.size() == 0)
    {
        cout<<"There are not products";
        closeOptions();
    }
    
    for (int i = 0; i < products.size(); i++ )
    {
        totalInventary = totalInventary + products[i].price;
        if (i == products.size())
        {
            cout<<"Total inventary value is :"<<(double)totalInventary<<endl;
        }
        
    }
    closeOptions();
    
};