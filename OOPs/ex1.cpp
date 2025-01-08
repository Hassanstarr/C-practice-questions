/*
Bank Account Management:

Create a 'BankAccount' class with private attributes like 'accountNumber', 'balance', and 'ownerName'.

Add public methods for depositing and withdrawing money.
Ensure proper validation (e.g., prevent negative balances).

*/

#include <iostream>
using namespace std;

class BankAccount{
    int accountNumber;
    float balance;
    string ownerName;
    public:
        BankAccount() {}
        BankAccount(string name, int accuntNo, float bal): ownerName(name), accountNumber(accuntNo), balance(bal) {}

        void setData(string, int, float);

        void depositing(float depost){
            balance += depost;
            cout<<"Deposit "<< depost <<" successful"<<endl;
            cout<<"The account number "<<accountNumber<<" current balance is: "<<balance<<endl;
        }

        void withdrawing(float withdr){
            if((balance - withdr) < 0){
                cout<<"Error: Balance insignificant"<<endl;
                cout<<"The account number "<<accountNumber<<" current balance is: "<<balance<<" can't withdraw "<<withdr<<" amount"<<endl;   
                return;
            }
            balance -= withdr;
            cout<<"Withdraw "<< withdr <<" successful"<<endl;
            cout<<"The account number "<<accountNumber<<" current balance is: "<<balance<<endl;   
        }

        void display();

};

void BankAccount:: setData(string name, int accuntNo, float bal){
    ownerName = name;
    accountNumber = accuntNo;
    balance = bal;
}

void BankAccount:: display(){
    cout<<"Name: "<<ownerName<<". Account Number: "<<accountNumber<<". Current balance is: "<<balance<<endl;
}


int main() {
    
    BankAccount Hassan("Hassan", 1234, 100000);

    Hassan.withdrawing(150000);
    Hassan.depositing(100000);
    Hassan.withdrawing(150000);

    Hassan.display();
    
    return 0;
}
