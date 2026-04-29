#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];


    int max_sum = 0;
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!(i + 2 >= n)) {
                temp = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                max_sum = (temp > max_sum) ? temp : max_sum;
            }
            if(!(j + 2 >= m)) {
                temp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                max_sum = (temp > max_sum) ? temp : max_sum;
            }
            if(!(i + 1 >= n || j + 1 >= m)) {
                temp = grid[i][j] + grid[i + 1][j] + grid[i + 1][j + 1];
                max_sum = (temp > max_sum) ? temp : max_sum;

                temp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j + 1];
                max_sum = (temp > max_sum) ? temp : max_sum;

                temp = grid[i][j] + grid[i][j + 1] + grid[i + 1][j];
                max_sum = (temp > max_sum) ? temp : max_sum;

                temp = grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1];
                max_sum = (temp > max_sum) ? temp : max_sum;
            }
        }
    }
    cout << max_sum << "\n";
}