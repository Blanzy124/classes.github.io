#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::cout;
using std::cin;

struct houseMembers
{
    std::string name;
    int age;
    int contribution; 
};

int main(){
    int membersInput;
    cout<<"How many members you would like creatre? ";
    cin>>membersInput;
    cin.ignore();
    vector<houseMembers> member(membersInput);
    for (int i = 0; i < membersInput; i++)
    {
        
        cout<<"Enter name for the member number "<<i + 1<<": \n";
        getline(cin, member[i].name);

        cout<<"Enter age for the member number "<<i + 1<<": \n";
        cin>>member[i].age;

        cout<<"Enter contribution for the member number "<<i + 1<<": \n";
        cin>>member[i].contribution;

        cin.ignore();
    }
    for (int o = 0; o < membersInput; o++)
    {
        std::cout<<"Name: "<<member[o].name<<endl<<"Age: "<<member[o].age<<endl<<"Contribution: "<<member[o].contribution<<endl;
    }
    return 0;
}



