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

    auto is_valid_rect = [&](int r1, int c1, int r2, int c2){ 
        for(int i = r1; i <= r2; i++)
            for(int j = c1; j <= c2; j++)
                if(grid[i][j] <= 0) return false;
        return true;
    };

    int max_size = -1;
    for(int x1 = 0; x1 < m; x1++)
        for(int x2 = x1; x2 < m; x2++)
            for(int y1 = 0; y1 < n; y1++)
                for(int y2 = y1; y2 < n; y2++) 
                    if(is_valid_rect(y1, x1, y2, x2)) 
                        max_size = max(max_size, (y2 - y1 + 1) * (x2 - x1 + 1));

    cout << max_size;
}