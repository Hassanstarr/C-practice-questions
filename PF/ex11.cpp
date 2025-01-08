/*

Enter a number = 7
Enter character to Print = +

      +
     +++
    + + +
   +  +  +
  +   +   +
 +    +    +
+     +     +
      +
      +
      +
      +
      +
      +
      +


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
        for(int s = 0; s < (num - i - 1); s++){
            cout<<" ";
        }
        for(int j = 0; j <= 2*i; j++){
            if( (j % 2 == 0 && (j == 0 || j == 2*i)) || j == i ){
                cout<<c;
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }


    for(int i = 0; i < num; i++){
        for(int s = 0; s < num - 1; s++){
            cout<<" ";
        }
        cout<<c<<endl;
    }
    
    return 0;
}
