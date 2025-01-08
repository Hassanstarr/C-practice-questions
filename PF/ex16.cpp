/*
    -Longest Word ----> Find the longest word in a given sentence.
    -Remove Duplicates ----> Remove all duplicate characters from a string.
    -FindReplace ----> Implement a custom version of findReplace() to replace all occurrences of a substring with another substring.
*/

#include <iostream>
using namespace std;

void longestWord(string str){

    int count = 0, maxcount = 0, index = 0;

    for(int i = 0; i <= str.length(); i++){
        if(str[i] == ' ' || str[i] == '\0'){
            if(count > maxcount){
                maxcount = count;
                index = i - count;
            }
            count = 0;
        } else {
            count++;
        }
        
    }

    // Extract the longest word
    string longest = str.substr(index, maxcount);

    cout<<"The longest word in the string is: "<<longest<<endl;

}

void removeDuplicates(string str){
    int count = 0;
    string newstr(str.length(), '\0');

    for(int i = 0; i < str.length(); i++){
        for(int j = 0; j < newstr.length(); j++){
            if(str[i] == newstr[j] && str[i] != ' '){
                break;
            }
            if(j == newstr.length()-1){
                newstr[count] = str[i];
                count++;
            }
        }
    }
    cout<<"The string without any duplicates is:"<<endl<<newstr<<endl; 
}

// void findReplace(string str, string find, string replace) {
//     size_t pos = str.find(find); // Use built-in `find` function for simplicity

//     if (pos != string::npos) {
//         // Perform the replacement
//         str = str.substr(0, pos) + replace + str.substr(pos + find.length());
//         cout << "Updated string: " << str << endl;
//     } else {
//         cout << "Substring not found!" << endl;
//     }
// }

// findreplace without using built-in `find` function
void findReplace(string str, string find, string replace){
    int index = -1;

    for(int i = 0; i <= str.length() - find.length(); i++){
        bool match = true;
        for(int j = 0; j < find.length(); j++){
            if(str[i+j] != find[j]){
                match = false;
                break;
            }
        }
        if(match){
            index = i;
            break;
        }

    }

        // If substring is not found
    if (index == -1) {
        cout << "Substring not found!" << endl;
        return;
    }

    string newstr= "";

    newstr += str.substr(0, index);
    newstr += replace;
    newstr += str.substr(index + find.length());

    cout << "Updated string: " << newstr << endl;

    
}




int main() {
    
    string str;

    cout<<"Enter the string: ";
    getline(cin, str);

    longestWord(str);
    removeDuplicates(str);

    string find, replace;

    cout << "Enter the substring to find: ";
    getline(cin, find);

    cout << "Enter the replacement string: ";
    getline(cin, replace);

    findReplace(str, find, replace);
    
    return 0;
}