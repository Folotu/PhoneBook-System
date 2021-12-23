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
        cout << "\n............PHONE BOOK RECORD...........\n";
        cout << "Sr. No.              : " << srno << endl;
        cout << "Name                 : " << name << endl;
        cout << "Mobile No.           : " << mobile << endl;
        cout << "E-Mail Address       : " << email << endl;
        cout << "Group                : " << group << endl;
    }

}b;
    
    void AddNumber()
    {
        ofstream fout;
        fout.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
        b.storeData();

        fout.write((char*)&b, sizeof(b));
        fout.close();
        cout << "\nRecord Saved to File.........\n";
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

