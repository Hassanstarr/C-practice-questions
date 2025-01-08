/*
    -Anagrams 
    ----> Check if two strings are anagrams (contain the same characters in any order).

    -Find All Substrings 
    ----> Generate all possible substrings of a given string.
    i.e.,string str = "abc";    // Output: "a", "b", "c", "ab", "bc", "abc"

    -Find Permutations of a String 
    ----> Generate all permutations of a string.
*/



#include <iostream>
#include <algorithm>    // to use sort function
// #include <string>    // The <iostream> header includes <string> in many C++ standard library implementations, so basic will work without explicitly including <string>.
using namespace std;

void checkAnagrams(const string& str1, const string& str2) {
    // Check if lengths are different, directly return if so
    if (str1.length() != str2.length()) {
        cout << "Strings \"" << str1 << "\" and \"" << str2 << "\" are NOT anagrams." << endl;
        return;
    }

    // Create copies of the strings to avoid modifying the original ones
    string sortedStr1 = str1;
    string sortedStr2 = str2;

    // Sort both strings
    sort(sortedStr1.begin(), sortedStr1.end());
    sort(sortedStr2.begin(), sortedStr2.end());

    // Compare sorted strings
    if (sortedStr1 == sortedStr2) {
        cout << "Strings \"" << str1 << "\" and \"" << str2 << "\" ARE anagrams." << endl << endl;
    } else {
        cout << "Strings \"" << str1 << "\" and \"" << str2 << "\" are NOT anagrams." << endl << endl;
    }
}


void findAllSubstrings(string str){
    cout << "All substrings of the string \"" << str << "\":" << endl;

    // substr(i, j): Extracts the substring starting at i with a length of j.
    for(int i = 0; i < str.length(); i++){
        for(int j = 0; j < str.length() + 1 - i; j++){
            cout<<str.substr(i, j)<<endl;
        }
    }
    
}

void findPermutations(string str, int l, int r){

    if(l == 0) cout<<endl<<"The Permutation of the string \"" << str << "\":"<<endl;
    if(l == r){
        cout<<str<<endl;
    } else {  
        for(int i = l; i <= r; i++){
            swap(str[l], str[i]);
            findPermutations(str, l+1, r);
            swap(str[l], str[i]);
        } 
    }

}




int main() {
    
    string str1, str2;

    cout<<"Enter the first string: ";
    getline(cin, str1);
    cout<<"Enter the second string: ";
    getline(cin, str2);

    checkAnagrams(str1, str2);
    findAllSubstrings(str1);
    findPermutations(str1, 0, str1.length()-1);
    
    return 0;
}

