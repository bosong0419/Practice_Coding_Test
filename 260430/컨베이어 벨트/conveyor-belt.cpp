#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> v(n * 2);
    for(int i = 0; i < n * 2; i++)
        cin >> v[i];

    rotate(v.rbegin(), v.rbegin() + t % (2 * n), v.rend());

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[j + n * i] << " "; 
        }
        cout << "\n";
    }
}