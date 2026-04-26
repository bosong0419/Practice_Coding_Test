#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    string str;
    cin >> str;
    for(auto& c: str) {
        if(c == '(') {
            s.push(1);
        }
        else if (c == ')') {
            if(s.empty()) {
                cout << "No" << "\n";
                return 0;
            }
            s.pop();
        }
    }
    if(s.empty())
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    return 0;
}