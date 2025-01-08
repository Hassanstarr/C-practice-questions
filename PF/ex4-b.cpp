/*

Use loop to print the follwoing pattern

if input is 5

*****   i = 0
*  *    i = 1
* *     i = 2
**      i = 3
*       i = 4

If input is 4

****
* *
**
*



*/

#include <iostream>
using namespace std;

int main() {
    
    int inpvalue = 0;

    cout<<"Enter a positive number"<<endl;
    cin>>inpvalue;

    if (inpvalue < 0){
        cout<<"Error!!! Number not positve";
        return 1;
    } else if (inpvalue == 0) {
        cout<<" "<< endl;
        return 0;
    }

    for (int i = 0; i < inpvalue; i++){
        for(int j = 0; j < (inpvalue - i); j++){
            if(i == 0 || j == 0 || j == (inpvalue - i - 1)){
                cout<<"*";
            } else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}

