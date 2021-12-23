#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;
using std::cout;

void menu();
void DisplayRecord();
void SearchBySrNo();
void deleteRecord();
void modifyRecord();

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
        cout << "Enter Serial Number of Record to Display: ";
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

    void DeleteRecord()
    {
        ifstream fin;
        int n, flag(0);

        fin.open("PhoneBook.dat", ios::out | ios::binary | ios::app);
        fout.open("temp.dat", ios::out | ios::binary);
        cout << "Enter Serial Number of Record to delete : ";
        cin >> n;
        
        while (fin.read((char*)&b, sizeof(b)))
        {
            if (n == b.getSrNo())
            {
                cout << "\nThe following record is deleted.........\n";
                b, showData();
                flag = flag + 1;
            }
            else
            {
                fout.write((char*)&b, sizeof(b));
            }
        }
        fin.close();
        fout.close();

        if (flag == 0)
            cout << "\The Record of Serial Number " << n << " is not in file........\n";
        cout << "\nReading of Data file Completed..........\n";
        remove("PhoneBook.dat");
        rename("temp.dat", "PhoneBook.dat");
    }

    void modifyRecord()
    {
        fstream fio;
        int, flag(0), pos;
        fio.open("PhoneBook.dat", ios::out | ios::binary | ios::in);

        cout << "Enter Serial Number of Record To modify: ";
        cin >> n;

        while (fio.read((char*)&b, sizeof(b)))
        {
            pos = fio.tellg();
            if (n == b.getSrNo())
            {
                cout << "\nThe following record will be modified......\n";
                b.showData();
                flag++;
                cout << "\nRe-Enter the New Details.............\n";
                b.storeData();
                fio.seekg(pos - sizeof(b));
                fio.write((char*)&b, sizeof(b));
                cout << "\n.......Data Modified Successfully..........\n";
            }
        }
        fio.close();
        if (flag == 0)
            cout << "\nThe Record of Serial Number " << n << " is not in file........\n";
            cout << "\n Reading of Data file Completed...........\n";
        
    }


void menu()
{
    int ch;

    do
    {
        clrscr();

        cout << "........................................................................\n";
        cout << "                                  PHONE BOOK MANAGEMENT\n";

        cout << ".........................................................................\n";
        cout ":::::::::::::::::::::::::::::::::::::::::::PROGRAM MENU:::::::::::::::::::::::::\n";
        cout << "0. Exit\n";
        cout << "1. Save New Phone Record\n";
        cout << "2. Display All Saved Records\n";
        cout << "3. Search specific Record\n";
        cout << "4. Delete Specific Record\n";
        cout << "5. Modify Existing Record\n";
        cin >> ch;
        clrscr();

        switch (ch)
        {
        case 1: AddNumber();
            break;

        case 2: DisplayRecords();
            break;

        case 3: SearchBySrNo();
            break;

        case 4: DeleteRecord()
            break;

        case 5: modifyRecord()
            break;

        }
        getch();

    } while (ch);
}

int main()
{
    menu();
}

