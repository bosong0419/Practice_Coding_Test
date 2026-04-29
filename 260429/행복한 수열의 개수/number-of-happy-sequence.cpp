#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto& row: v)
        for(auto& a: row)
            cin >> a;
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        int conti = 1;
        for(int j = 0; j < n - 1; j++) {
            if(v[i][j] == v[i][j + 1]) conti++;
            else conti = 1;
            if(conti == m) {
                count++;
                break;
            }
        }
    }
    for(int j = 0; j < n; j++) {
        int conti = 1;
        for(int i = 0; i < n - 1; i++) {
            if(v[i][j] == v[i + 1][j]) conti++;
            else conti = 1;
            if(conti == m) {
                count++;
                break;
            }
        }
    }
    cout << count << "\n";
}