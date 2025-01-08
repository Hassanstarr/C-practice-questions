// Write a C++ program, which input numbers from user until he enters -1, and print all prime numbers input by user

#include <iostream>
using namespace std;

bool isPrime(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2; i < x; i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main() {

    cout<<"Will tell all the prime numbers"<<endl;
    
    while (true)
    {
        int num;

        cout<<"Enter an number: ";
        cin>>num;

        if (num == -1){
            break;
        }

        if(isPrime(num)){
            cout<<num<<" is a prime number"<<endl;
        } else {
            cout<< num << " is not a prime number"<<endl;
        }



        cout<<endl<<"To Exist type -1"<<endl;
    }
    
    cout<<"Exist successfully"<<endl;
    
    return 0;
}