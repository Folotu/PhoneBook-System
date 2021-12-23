#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;
using std::cout;

void SearchBySrNo();

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

    void DisplayRecords()
    {
        ifstream fin;
        fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
        while (fin.read((char*)&b, sizeof(b)))
        {
            b.showData();
        }
        fin.close();
        cout << "\nReading of Data file completed..........\n";      
    }

    void SearchBySrNo();
    {
        ifstream fin;
        int n, flag(0);

        fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
        cout << "Enter Serical Number of Record to Display: ";
        cin >> n;

        while (fin.read((char*)&b, sizeof(b)))
        {
            if (n == b.getSrNo())
            {
                b.showData();
                flag = flag + 1; 

                cout << "\n\n........Record Found and Displayed...........\n";
            }
        }
        fin.close();
        if (flag == 0)
        {
            cout << "\n The Record of the Serial Number " << n << " is not in file.........\n";
            cout << "\n Reading of Data File Completed..............\n";
        }
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

