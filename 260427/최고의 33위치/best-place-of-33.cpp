#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto& row: v)
        for(auto& a: row)
            cin >> a;
    
    int sum_max = 0;
    for(int i = 0; i <= n - 3; i++) {
        for(int j = 0; j <= n - 3; j++) {
            int sum = 0;
            sum = v[i][j] + v[i][j+1] + v[i][j+2] + v[i+1][j] + v[i+1][j+1] + v[i+1][j+2] +
                  v[i+2][j] + v[i+2][j+1] + v[i+2][j+2];
            sum_max = max(sum_max, sum);
        }
    }
    cout << sum_max << "\n";
    return 0;
}