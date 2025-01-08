/*

Write a program in C++ to print a circle.

*/

#include <iostream>
#include<math.h>
using namespace std;

int main() {
    
    int rad, diameter;

    cout<<"Enter the radius of the circle: ";
    cin>>rad;

    diameter = 2 * rad;

    for(int i = 0; i <= diameter; i++){
        for(int j = 0; j <= diameter; j++){
            
            int dist = (float) sqrt(pow(i - rad, 2) + pow(j - rad, 2));

            if ( dist == rad) {
                cout<<"**";
            } else {
                cout<<"  ";
            }

        }
            cout<<endl;
    }


    
    return 0;
}