#include <iostream>
#include "temp.h"

using namespace std;

int main(){
    int ans;

    cout << "\n\n\t\t...... May Bank ......";
    cout << "\n\n\t\t Press 1 to Login";
    cout << "\n\n\t\t Press 2 to Create Account";
    cout << "\n\n\t\t Press 3 to Exit";
    cout << "\n\n\t\t......................" << endl;
    cout << "\n\n\t\t Choose number only : ";
    
    cin >> ans;

    switch(ans){
        case 1:
            cout <<"Enter your account number : ";
            cin >> obj.search;
            while(1){
                cout << "\n\n\t\t...... May Bank ......";
                cout << "\n\n\t\t Press 1 to Deposit Money";
                cout << "\n\n\t\t Press 2 to Withdraw Money";
                cout << "\n\n\t\t Press 3 to Your Balance";
                cout << "\n\n\t\t Press 4 to Exit Menu";
                cout << "\n\n\t\t......................" << endl;
                cout << "\n\n\t\t Choose number only : ";
                cin >> ans;

                switch(ans){
                    case 1:
                        cin.ignore();
                        obj.DepositMoney();
                    break;
                    case 2:
                        cin.ignore();
                        obj.WithdrawMoney();
                    break;
                    case 3:
                        cin.ignore();
                        obj.YourBalance();
                    break;
                    case 4:
                        return 0;
                    break;
                    default:
                        cout << "Wrong input.. Try again...";
                }
                system("pause");
                system("cls");
            }
        break;
        case 2:
            cin.ignore();
            obj.CreateAccount();
        break;
        case 3:
            system("exit");
        break;
        default:
            cout << "Wrong Input... Try again...";
    }
    return 0;
}