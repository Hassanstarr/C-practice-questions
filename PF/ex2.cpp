/*

Currency Converter
Write a program to converte money from one currency to another

In this problem you are required to write a simple prgram that will take two inputs
- The amount to be converted
- The rate of conversion (rate > 0)
- and then display the amount

*/

#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

int main() {
    float money, rate;

    cout << "Currency Converter"<<endl;
    cout << "Enter the amount you want to convert: ";
    cin >> money;
    
    do {
        cout << "Enter the conversion rate:"<<endl;
        cout << "- For example, use 250 for multiplying, or 0.004 for dividing by 250."<<endl;
        cout << "Conversion Rate: ";
        cin >> rate;
        
        if (rate <= 0) {
            cout << "Invalid input! Conversion rate must be greater than zero."<<endl;
        }
    } while (rate <= 0);

    // Calculate and display the converted amount with 2 decimal place
    cout << fixed << setprecision(2); // Set output precision to 2 decimal places
    cout << "\nIn the target currency, your converted amount is: " << money * rate << endl;

    return 0;
}
