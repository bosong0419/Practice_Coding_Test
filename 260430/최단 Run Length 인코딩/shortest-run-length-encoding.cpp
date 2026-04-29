#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int run_length_encoding(const string& str) {
    string encoding_str;
    bool new_variable = true;
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        if(new_variable) {
            encoding_str += str[i];
            new_variable = false;
        }
        count++;
        if(i == str.length() - 1 || str[i] != str[i + 1]) {
            encoding_str += to_string(count);
            count = 0;
            new_variable = true;
        }
    }
    return encoding_str.length();
}

int main() {
    string str;
    cin >> str;
    int min_length = 1e9;
    for(int i = 0; i < str.length(); i++) {
        min_length = min(min_length, run_length_encoding(str));
        rotate(str.begin(), str.begin() + 1, str.end());
    }
    cout << min_length << "\n";
}