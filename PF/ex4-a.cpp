
/*

Use loop to create the following output

if w=4, l=3

****
*  *
****

if w=3, l=4

***
* *
* *
***

IF W=2, L=2

**
**

*/


#include <iostream>
using namespace std;

int main() {

    int width = 0, length = 0;

    cout<<"Enter the value of width and length"<<endl;
    cin>>width>>length;

    for (int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || j == 0 || i == (length - 1) || j == (width - 1) ){
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}

