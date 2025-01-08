/*

Enter a number = 6
Enter character to Print = 6

     666666
    66666666
   6666666666
  666666666666
 66666666666666
6666666666666666
 66666666666666
  666666666666
   6666666666
    66666666
     666666


*/



#include <iostream>
using namespace std;

int main() {

    int num;
    char c;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<"Enter the character to Print: ";
    cin>>c;

    for(int i = 0; i < num; i++){

        for(int s = 0; s < num - (i + 1); s++){
            cout<<" ";
        }
        
        for(int j = 0; j < num + 2*i; j++){
            cout<<c;
        }
        cout<<endl;
    }

    for(int i = 0; i < num - 1; i++){
        for(int s = 0; s <= i ; s++){
            cout<<" ";
        }
        for(int j = 0; j < num + 2*(num - (i+2)); j++){
            cout<<c;
        }
        cout<<endl;
    }
    
    return 0;
}