#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> v(n * 2);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++) {
            cin >> v[j + n * i];
        }

    for(int i = 0; i < (t % (2 * n)); i++) {
        int temp = v[2 * n - 1];
        for(int j = 2 * n - 1; j > 0; j--) {
            v[j] = v[j - 1];
        }
        v[0] = temp;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[j + n * i] << " "; 
        }
        cout << "\n";
    }
}