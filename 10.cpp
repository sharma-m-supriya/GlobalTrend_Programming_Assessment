#include <iostream>
#include <string>
using namespace std;

bool isAlphabetic(const string& str) {
    for (char c : str) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {
    string s = "HelloWorld";
    cout << "String \"" << s << "\" contains only alphabetic characters: " << boolalpha << isAlphabetic(s) << endl;
    
    s = "Hello123";
    cout << "String \"" << s << "\" contains only alphabetic characters: " << boolalpha << isAlphabetic(s) << endl;
    
    return 0;
}
