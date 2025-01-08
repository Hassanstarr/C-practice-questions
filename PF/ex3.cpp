/*
    Quadratic Equation Root Calculator

    This program finds the roots of a quadratic equation of the form:
        ax^2 + bx + c = 0, where a ≠ 0.
    
    The program takes three inputs:
      - a (the coefficient of x^2)
      - b (the coefficient of x)
      - c (the constant term)

    It calculates the discriminant (b^2 - 4ac) to determine the type of roots:
      - If b^2 - 4ac > 0, there are two real and distinct roots.
      - If b^2 - 4ac = 0, there is one real repeated root.
      - If b^2 - 4ac < 0, there are two complex roots.
    
    For cases where b^2 - 4ac >= 0, it also calculates and displays the roots.
*/

#include <iostream>
#include <cmath>  // For sqrt function
#include <iomanip> // For formatting output

using namespace std;

int main() {
    double a, b, c;
    
    cout << " Quadratic Equation: a * x^2 + b * x + c = 0" << endl << "Enter coefficient a (non-zero): ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    
    if (a == 0) {
        cout << "Error: 'a' should not be zero. This is not a quadratic equation." << endl;
        return 1;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "The equation has two real and distinct roots:\n";
        cout << "Root 1: " << fixed << setprecision(2) << root1 << endl;
        cout << "Root 2: " << fixed << setprecision(2) << root2 << endl;

    } else if (discriminant == 0) {
        
        double root = -b / (2 * a);
        cout << "The equation has one real repeated root:\n";
        cout << "Root: " << fixed << setprecision(2) << root << endl;

    } else {
        
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);

        cout << "The equation has two complex roots:\n";
        cout << "Root 1: " << fixed << setprecision(2) << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2: " << fixed << setprecision(2) << realPart << " - " << imaginaryPart << "i" << endl;
        
    }

    return 0;
}
