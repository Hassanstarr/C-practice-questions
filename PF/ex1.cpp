/*

Write an C++ code to print a fencepost pattern. Such as "|==|==|==|"
If the user inputs 0 -> print ""
If the user inputs 1 -> print "|==|"
If the user inputs 4 -> print "|==|==|==|==|"
If the user inputs 5 -> print "|==|==|==|==|==|"

*/


#include <iostream>
using namespace std;

int main() {
    
    int inpvalue = 0;

    cout << "Enter a number"<<endl;
    cin>>inpvalue;

    if(inpvalue < 0){
        cout << "Enter an positive integer" << endl ;
        return 0;
    } else if (inpvalue == 0) {
        return 0;
    }

    cout<<"|";

    for (int i = 0; i < inpvalue; i++){
        cout<<"==|";
    }
    
    return 0;
}

