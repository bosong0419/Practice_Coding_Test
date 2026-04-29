#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int s1, e1, s2, e2;
    cin >> s1 >> e1 >> s2 >> e2;
    s1--; e1--; s2--; e2--;
    v.erase(v.begin() + s1, v.begin() + e1 + 1);
    v.erase(v.begin() + s2, v.begin() + e2 + 1);
    cout << v.size() << "\n";
    for(int n: v)
        cout << n << "\n";
}