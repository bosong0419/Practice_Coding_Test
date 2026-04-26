#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    stack<int> st;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if(s == "push") {
            int value;
            cin >> value;
            st.push(value);
        }
        else if(s == "pop") {
            cout << st.top() << "\n";
            st.pop();
        }
        else if(s == "size") {
            cout << st.size() << "\n";
        }
        else if(s == "empty") {
            cout << st.empty() << "\n";
        }
        else if(s == "top") {
            cout << st.top() <<"\n";
        }
    }
    return 0;
}