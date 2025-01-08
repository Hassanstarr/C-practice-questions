/*

    -Reverse an integer array using pointers.
    -Write a function that takes a string (character array) and a pointer to it, and prints the string in reverse order using only pointers.
    -Write a function to swap two integers using pointer-to-pointer.

*/

#include <iostream>
using namespace std;

// Reverse an integer array using pointers
void reverseInt(int arr[], int size) {
    cout << "Reversed integer array: ";
    for (int* p = arr + size - 1; p >= arr; --p) {
        cout << *p << " ";
    }
    cout << endl;
}

// Reverse a string using a pointer
void reverseString(const string& str) {
    cout << "Reversed string: ";
    for (const char* p = str.c_str() + str.length() - 1; p >= str.c_str(); --p) {
        cout << *p;
    }
    cout << endl;
}

// Swap two integers using a pointer-to-pointer
void swapInt(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    // Reverse integer array
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    reverseInt(arr, size);

    // Reverse string
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    reverseString(str);

    // Swap integers
    int x, y;
    cout << "Enter the value of x and y: ";
    cin >> x >> y;

    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapInt(&x, &y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
