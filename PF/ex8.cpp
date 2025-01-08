/*
    Factorial and Combinatorics Calculator

    This program implements several functions to calculate the factorial of a number, permutations,
    and combinations using factorials. The program also includes a main menu that allows the user
    to select different operations based on input.

    TASKS:
    
    1. Factorial Calculation:
       - Write a function that returns the factorial of a non-negative integer.
       - The factorial of a number n is the product of all positive integers from 1 up to n.
       - Example: 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720. Note that 0! = 1 by definition.

    2. Permutation Calculation (nPr):
       - Write a function that takes two inputs, n and r, and calculates the number of permutations.
       - Formula: nPr = n! / (n - r)!
       - Use the factorial function from Task 1 to compute this.

    3. Combination Calculation (nCr):
       - Write a function that takes two inputs, n and r, and calculates the number of combinations.
       - Formula: nCr = n! / ((n - r)! * r!)
       - Use the factorial function from Task 1 to compute this.

    4. Combination Calculation with Permutations (nCr(n,r)):
       - Write a function that takes two inputs, n and r, and calculates the number of combinations
         where nCr(n, r) = nPr(n, r) / r!.
       - Use the factorial function from Task 1 and the permutation function from Task 2 to compute this.

    5. Main Menu Function:
       - Design a main menu function that prompts the user for an operation based on input:
         a. On input '1': Calculate and display the factorial of a number.
         b. On input '2': Calculate and display nPr (permutations) of two numbers.
         c. On input '3': Calculate and display nCr (combinations) of two numbers.
         d. On input '4': Calculate and display nCr(n,r) using permutations.
         e. On input '5': Exit the program.
       - All input and output should occur in the main menu function.
*/


#include <iostream>
using namespace std;

int factorial(int num){
    if (num == 0 || num == 1){
        return 1;
    }
    return num * factorial(num - 1);
}

int permutation(int n, int r){
    return factorial(n)/factorial(n - r);
}

int combination(int n, int r){
    return factorial(n)/(factorial(n - r) * factorial(r));
}

int combination2(int n, int r){
    return permutation(n, r)/factorial(r);
}

int main() {
    
    int n, r, option;
    bool exitLoop = false;

    while (!exitLoop){
        cout<<"Enter 1 for factorial of a number"<<endl<<"Enter 2 for permutation"<<endl<<"Enter 3 or 4 for combination"<<endl<<"Enter 5 to exist"<<endl;

        if (!(cin >> option)) {        // Checks if input failed
            option = 6;                // Set default value if input is invalid
            cin.clear();               // Clear the error state
            cin.ignore(1000, '\n');    // Discard invalid input
        }

        switch (option)
        {
        case 1:
            cout<<"Enter the number to get its factoial: "<<endl;
            cin>>n;
            cout<<"The factorial of "<<n<<" is "<< factorial(n)<<endl;
            break;
        case 2:
            cout<<"Enter n and r to get its permutation: "<<endl;
            cin>>n>>r;
            cout<<"The permutation is "<< permutation(n, r)<<endl;
            break;
        case 3:
            cout<<"Enter n and r to get its combination: "<<endl;
            cin>>n>>r;
            cout<<"The comnination is "<< combination(n, r)<<endl;
            break;
        case 4:
            cout<<"Enter n and r to get its combination: "<<endl;
            cin>>n>>r;
            cout<<"The comnination is "<< combination2(n, r)<<endl;
            break;
        case 5:
            cout<<"existing the program"<<endl;
            exitLoop = true;
            break;
        
        default:
            cout<<"Invalid!!!"<<endl;
            break;
        }
        
        cout<<endl;
    }
    
    return 0;
}