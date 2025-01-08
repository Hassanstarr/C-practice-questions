/*

Enter a Number = 8

123456787654321
1234567 7654321
123456   654321
12345     54321
1234       4321
123         321
12           21
1             1
12           21
123         321
1234       4321
12345     54321
123456   654321
1234567 7654321
123456787654321

*/


#include <iostream>
using namespace std;

int main() {

    int num;

    cout<<"Enter a number: ";
    cin>>num;



    for(int i = 0; i < num; i++){
            
            for(int j = 1; j <= (num - i); j++){
                cout<<j;
            }

            for(int j = 0; j < (2*i - 1); j++){
                cout<<" ";
            }

            for(int j = num - i; j > 0; j--){
                if(j == num) continue;
                cout<<j;
        }

        cout<<endl;

    }

    for(int i = 0; i < num - 1; i++){

        for(int j = 1; j <= i + 2; j++){
            cout<<j;
        }

        for(int j = (2*num - 3) - 2*(i + 1); j > 0; j --){
            cout<<" ";
        }

        for(int j = i + 2; j > 0; j--){
            if(j == num) continue;
            cout<<j;
        }

        cout<<endl;

    }


    
    
    return 0;
}