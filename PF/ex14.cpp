/*

    -String Length
    -String Reverse
    -Check Palindrome -> Check if a string is a palindrome (reads the same backward as forward).
    -Count Vowels and Consonants
    -Convert Case -> Upper and lower case

*/

#include <iostream>
#include <cctype>  // For isalpha() function
using namespace std;


int stringLength(string str){
    int count = 0;
    while(true){
        if(str[count] == '\0' ){
            break;
        }
        count++;
    }
    return count;
}

string stringReverse(string str){

    int len = stringLength(str);
    string newstr(len, '\0');

    for(int i = 0; i < len; i++){
        newstr[i] = str[len - i - 1];
    }

    return newstr;
}

void checkPalindrome(string str){
    int len = stringLength(str);
    string reverseStr = stringReverse(str);

    for(int i = 0; i < len; i++){
        if(str[i] != reverseStr[i]){
            cout << "The string \"" << str << "\" is not palindrome" << endl;
            return;
        }
    }
    
    cout << "The string \"" << str << "\" is palindrome" << endl;
    return;  
}

string toLowerCase(string str);

int vowels(string str){
    int count = 0, len = str.length();  // in-build function
    char ch[5] = {'a', 'e', 'i', 'o', 'u'};

    str = toLowerCase(str);
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < len; j++){

            if(ch[i] != str[j]) continue;
            count++;
        }
    }
    return count;
}

int consonants(string str){

    int count = 0;

    // Iterate through each character in the string
    for(char c : str){
        c = tolower(c);
        if(isalpha(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')  count++;
    }

    return count;
}

string toUpperCase(string str){
    int asciiValue, len = str.length();
    char ch;

    for(int i = 0; i < len; i++){
        ch = str[i];
        asciiValue = (int) ch;

        if(asciiValue >= 97 && asciiValue <= 122)   str[i] = (char)(asciiValue -= 32);

    }
    return str;
}

string toLowerCase(string str){
    int asciiValue, len = str.length();
    char ch;

    for(int i = 0; i < len; i++){
        ch = str[i];
        asciiValue = (int) ch;

        if(asciiValue >= 65 && asciiValue <= 90)   str[i] = (char)(asciiValue += 32);

    }
    return str;
}




int main() {
    string str;

    cout<<"Enter the string: ";
    getline(cin, str);

    cout<<"The Length of the Input String is: "<<stringLength(str)<<endl;
    cout<<"The Reverse of the Input String is: "<<stringReverse(str)<<endl;
    checkPalindrome(str);
    cout<<"The number of the Vowels in the String is: "<<vowels(str)<<endl;
    cout<<"The number of the Consonants in the String is: "<<consonants(str)<<endl;
    cout<<"Changeing the Input String to Upper case: "<<toUpperCase(str)<<endl;
    cout<<"Changeing the Input String to lower case: "<<toLowerCase(str)<<endl;


    return 0;
}