#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::cin;

struct product{
    string name;
    double price;
    int stock;
};


void showSimpleSentence(string message){
    cout<<message;
};

void closeOptions(){
    int options;
    showSimpleSentence("Main menu enter 1, else close");
    cin.ignore();
    cin>>options;
    if (options == 1)
    {
        cin.ignore();
        exit(1);
    }
    else{
        exit(1);
    }
    
};

void addProduct(vector<product>& product, int stockProductNumber){
    int newProducts;
    showSimpleSentence("How many products you would like add? ");
    try
    {
        cin>>newProducts;
    }
    catch(const string err)
    {
        cout<<err;
        showSimpleSentence("Must be numbers only...");
        closeOptions();
        return;
    }
    for (int i = 0; i < newProducts; i++)
    {
        cin.ignore();
        cout<<"What is the name for the product number "<<i + 1<<"? :\n";
        cin>>product[stockProductNumber + 1].name;
        cout<<"What is the price for the product number "<<i + 1<<"? :\n";
        cin>>product[stockProductNumber + 1].price;
        cout<<"What is the new units stock for the product number "<<i + 1<<"? :\n";
        cin>>product[stockProductNumber + 1].stock;
        cin.ignore();
    }
    showSimpleSentence("Product/s has been add");
    //closeOptions();
    return;
}

void showFullInventary(vector<product>& product, int stockProductNumber){
    for (int i = 0; i < stockProductNumber; i++)
    {
        cout<<"Name: "<<product[i].name<<"Price: "<<product[i].price<<"Stock: "<<product[i].stock<<endl;
    }
    cin.ignore();
    closeOptions();
    return;
}


int main(){
    int newProducts;
    vector<product>  product(newProducts);
    int stockProductNumber = product.size();

    int mainMenuObtions;
    showSimpleSentence("What do you want to do? \n");
    showSimpleSentence("Option 1: add a new product\n");
    showSimpleSentence("Option 2: show all the inventary\n");
    showSimpleSentence("Option 3: show total inventary price\n");
    showSimpleSentence("Option 4: add a new product\n");
    cin>>mainMenuObtions;
    cin.ignore();
    switch (mainMenuObtions)
    {
    case 1:
        addProduct(product, stockProductNumber);
        break;
    case 2:
        showFullInventary(product, stockProductNumber);
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    return 0;
}