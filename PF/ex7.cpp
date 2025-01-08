/*
    Babylonian Method for Approximating Square Root

    This function implements the Babylonian (or divide-and-average) method to approximate
    the square root of a given number N.

    METHOD:
    Suppose we want to compute the square root of a number N. We start with an initial guess A,
    where A > 0. A better approximation B can then be calculated using:
        B = (A + N / A) / 2
    
    We repeat this process by taking each improved approximation and using it to generate the next
    approximation until we reach the desired accuracy.

    EXAMPLE:
    For example, to compute the square root of N = 2:
    - Start with an initial guess of 1.
    - The next approximation is (1 + 2 / 1) / 2 = 1.5
    - The next approximation is (1.5 + 2 / 1.5) / 2 = 1.416667
    - The next approximation is (1.416667 + 2 / 1.416667) / 2 = 1.414216
    - And so on.

    As we continue this process, the result converges closer to the true square root of N.
    This is especially useful for irrational numbers where the square root cannot be represented
    exactly in decimal form.

    TASK:
    Write a C++ function named square_root(int n) that implements the Babylonian method to calculate
    the square root of an integer n. The function should perform 10 iterations of approximation
    and then return the calculated square root.
*/


#include <iostream>
using namespace std;

int main() {
    
    float num, res = 1;

    cout<<"Enter the number to get the square root of by Babylonian algorithm: ";
    cin>>num;
    
    for(int i = 0; i < 10; i++){
        res = ( res + num/res ) / 2;
    }

    cout<<res;
    
    return 0;
}