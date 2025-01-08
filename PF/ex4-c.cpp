
/*


To loop to show the follwoing patteren

if the input is 4
1
22
333
4444
4444
333
22
1
   1
  22
 333
4444
4444
 333
  22
   1
   1
  222
 33333
4444444


*/


#include <iostream>
using namespace std;

int main() {
    
    int num;

    cout<<"Enter a positive number: ";
    cin>> num;

    if(num < 0){
        cout<<"Error!!! number should be positive"<<endl;;
        return 1;
    } else if (num == 0) {
        cout<<" "<<endl;
        return 0;
    }


    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            cout<<i;
        }
        cout<<endl;
    }

    for(int i = num; i >= 0; i--){
        for(int j = 1; j <= i; j++){
            cout<<i;
        }
        cout<<endl;
    }

    for(int i = 1; i <= num; i++){
        for(int s = 0; s < num - i; s++){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
            cout<<i;
        }
        cout<<endl;
    }

    for(int i = num; i >= 0; i--){
        for(int s = 0; s < num - i; s++){
            cout<<" ";
        }
        for(int j = 1; j <= i; j++){
            cout<<i;
        }
        cout<<endl;
    }

    for(int i = 1; i <= num; i++){
        for(int s = 0; s < num - i; s++){
            cout<<" ";
        }
        for(int j = 1; j <= i*2 - 1; j++){
            cout<<i;
        }
        cout<<endl;
    }


    
    
    return 0;
}

