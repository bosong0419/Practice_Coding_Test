#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> v(n * 3);
    for(int i = 0; i < n * 3; i++)
        cin >> v[i];

    rotate(v.rbegin(), v.rbegin() + t % (3 * n), v.rend());

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[j + n * i] << " "; 
        }
        cout << "\n";
    }
}