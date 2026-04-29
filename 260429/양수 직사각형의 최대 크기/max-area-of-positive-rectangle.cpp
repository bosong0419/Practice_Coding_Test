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

    int max_size = -1;
    for(int x1 = 0; x1 < m; x1++)
        for(int x2 = x1; x2 < m; x2++)
            for(int y1 = 0; y1 < n; y1++)
                for(int y2 = y1; y2 < n; y2++) {
                    bool is_minus = false;
                    for(int i = y1; i <= y2; i++)
                        for(int j = x1; j <= x2; j++) {
                            if(grid[i][j] < 0) is_minus = true;
                        }
                    if(!is_minus) {
                        max_size = max(max_size, (y2 - y1 + 1) * (x2 - x1 + 1));
                    }
                }
    cout << max_size;
}