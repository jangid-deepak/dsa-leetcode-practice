#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<string> split(string sentence) {
    vector<string> tokens;
    size_t start = 0, end;
    
    while ((end = sentence.find(' ', start)) != string::npos) {
        tokens.push_back(sentence.substr(start, end-start));
        start = end + 1;
    }
    tokens.push_back(sentence.substr(start));
    return tokens;
}


int main() {
    // initialization
    string str1 = "Hello";
    string str2("World!");
    char str3[] = "C-style string";
    cout << str1 << " " << str2 << endl;
    cout << str3 << endl;

    // concatenation
    string str4 = str1 + " " + str2;
    cout << str4 << endl;

    // substring
    size_t pos = str4.find("World");
    if (pos != string::npos) {
        cout << "Found at index: " << pos << endl;
    }

    // extracting
    string str5 = str4.substr(6,5);
    cout << str5 << endl;

    //replacing 
    string str6 = str4.replace(6, 5, "C++");
    cout << str6 << endl;

    // erasing a part
    string str7 = str4.erase(6, 5);
    cout << str7 << endl;

    // converting string to uppercase/ lowercase
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout << str1 << " " << str2 << endl;

    

    return 0;
}