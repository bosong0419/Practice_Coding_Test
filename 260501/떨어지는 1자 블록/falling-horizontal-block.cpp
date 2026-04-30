#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    k--;
    // 1번째 행은 모두 0으로 주어진다고 조건에 제시
    for(int i = 0; i < n; i++) {
        bool can_insert = true;
        for(int j = k; j < k + m; j++) {
            if(grid[i][j]) {
                can_insert = false;
                break;
            }
        }
        if(!can_insert) {
            for(int j = k; j < k + m; j++)
                grid[i - 1][j] = 1;
            break;
        }
        if(i == n - 1) {
            for(int j = k; j < k + m; j++)
                grid[i][j] = 1;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}