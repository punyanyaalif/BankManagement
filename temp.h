#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class temp{
    int AccNumber;
    char Name[25];
    char ParentsName[25];
    char CitizenID[25];
    char PhoneNumber[25];
    char Email[25];
    float Amount;
    int NewAmount;
    fstream file, file1;

    public:
        int search;
        void CreateAccount();
        void DepositMoney();
        void WithdrawMoney();
        void YourBalance();
}obj;

void temp :: CreateAccount(){
    srand(time(0));

    AccNumber = rand()*rand()+rand()*rand();

    cout <<"Enter Your Name : ";
    cin >> Name;

    cout << "Enter Your Parents Name : ";
    cin >> ParentsName;

    cout << "Enter Your Citizen ID : ";
    cin >> CitizenID;

    cout << "Enter Your Phone Number : ";
    cin >> PhoneNumber;

    cout << "Enter Your Email : ";
    cin >> Email;

    cout << "Enter Amount : ";
    cin >> Amount;

    cout << "This is your account number : " << AccNumber << endl;
    cout << "Save your account number in somewhere secure...";

    file.open("clientdata.txt", ios :: out | ios :: app);
    file << AccNumber << "\t" << Name << "\t" << ParentsName << "\t" << CitizenID << "\t" << PhoneNumber << "\t" << Email << "\t" << Amount << endl;
    file.close();
}

void temp :: DepositMoney(){
    cout << "Enter Amount to Deposit : ";
    cin >> NewAmount;

    file.open("clientdata.txt", ios :: in);
    file1.open("dummydata.txt", ios :: out | ios :: app);
    file >> AccNumber >> Name >> ParentsName >> CitizenID >> PhoneNumber >> Email >> Amount;

    while(!file.eof()){
        if(AccNumber == search){
            cout << "\nYour Balance : " << Amount;
            Amount = Amount + NewAmount;
            cout << "\nUpdated Balance : " << Amount << endl;

            file1 << AccNumber << "\t" << Name << "\t" << ParentsName << "\t" << CitizenID << "\t" << PhoneNumber << "\t" << Email << "\t" << Amount << endl;
        } else {
            file1 << AccNumber << "\t" << Name << "\t" << ParentsName << "\t" << CitizenID << "\t" << PhoneNumber << "\t" << Email << "\t" << Amount << endl;
        }
        file >> AccNumber >> Name >> ParentsName >> CitizenID >> PhoneNumber >> Email >> Amount;
    }
    file.close();
    file1.close();
    remove("clientdata.txt");
    rename("dummydata.txt", "clientdata.txt");
}

void temp :: WithdrawMoney(){
    cout << "Enter Amount to Withdraw : ";
    cin >> NewAmount;

    file.open("clientdata.txt", ios :: in);
    file1.open("dummydata.txt", ios :: out | ios :: app);
    file >> AccNumber >> Name >> ParentsName >> CitizenID >> PhoneNumber >> Email >> Amount;

    while(!file.eof()){
        if(AccNumber == search){
            cout << "\nYour Balance : " << Amount;
            Amount = Amount - NewAmount;
            cout << "\nUpdated Balance : " << Amount << endl;

            file1 << AccNumber << "\t" << Name << "\t" << ParentsName << "\t" << CitizenID << "\t" << PhoneNumber << "\t" << Email << "\t" << Amount << endl;
        } else {
            file1 << AccNumber << "\t" << Name << "\t" << ParentsName << "\t" << CitizenID << "\t" << PhoneNumber << "\t" << Email << "\t" << Amount << endl;
        }
        file >> AccNumber >> Name >> ParentsName >> CitizenID >> PhoneNumber >> Email >> Amount;
    }
    file.close();
    file1.close();
    remove("clientdata.txt");
    rename("dummydata.txt", "clientdata.txt");
}

// Checking Balance
void temp :: YourBalance(){
    file.open("clientdata.txt", ios :: in);

    if(!file){
        cout << "THROW ERROR! File cannot be opened...";
    }
    
    file >> AccNumber >> Name >> ParentsName >> CitizenID >> PhoneNumber >> Email >> Amount;

    while(!file.eof()){
        if(AccNumber == search){
            cout << "\n------------------------\n";
            cout << "\t... Account Number ...";
            cout << "\t  " << AccNumber << endl;
            cout << "\t... Client Name ...";
            cout << "\t  " << Name << endl;
            cout << "\t... Parents Name ...";
            cout << "\t  " << ParentsName << endl;
            cout << "\t... Citizen ID ...";
            cout << "\t  " << CitizenID << endl;
            cout << "\t... Phone Number ...";
            cout << "\t  " << PhoneNumber << endl;
            cout << "\t... Email ...";
            cout << "\t  " << Email << endl;
            cout << "\t... Amount ...";
            cout << "\t  " << Amount << endl;
        }
        file >> AccNumber >> Name >> ParentsName >> CitizenID >> PhoneNumber >> Email >> Amount;
    }
    file.close();
}