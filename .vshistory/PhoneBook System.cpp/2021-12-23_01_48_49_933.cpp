#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Phonebook
{
private:
    int srno;
    char name[25], mobile[15], email[30], group[20];

public:
    int getSrNo() { return srno; };
    void storeData()
    {
        cout << "\n..................CREATE NEW PHONE RECORD................\n";
        cout << "Enter your serial number : ";
        cin >> srno; cin.ignore();

        cout << "Enter Record Name    : "; 
        cin.getline(name, 25);
        cout << "Enter Mobile Number : ";
        cin.getline(mobile, 15);

        cout << "Enter E-Mail address : ";
        cin.getline(email, 30);

        cout << "Enter Record Group : ";
        cin.getline(group, 20);
        cout << endl;
    }

    void showData()
    {


    }


void menu()
{
    int ch;

    do
    {
        
    }
}

int main()
{
    
}

