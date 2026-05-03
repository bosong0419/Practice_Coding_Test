#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void bomb(vector<vector<int>>& grid, int t, int r, int c) {
    int n = grid.size();
    int jump = pow(2, t - 1);
    if(r + jump < n)  grid[r + jump][c] = 1;
    if(r - jump >= 0) grid[r - jump][c] = 1;
    if(c + jump < n)  grid[r][c + jump] = 1;
    if(c - jump >= 0) grid[r][c - jump] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--; c--;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    
    grid[r][c] = 1;
    for(int t = 1; t <= m; t++) {
        vector<pair<int, int>> is_bomb;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) is_bomb.push_back({i, j});
            }
        }
        for(auto& a: is_bomb) {
            bomb(grid, t, a.first, a.second);
        }
        
    }

    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j]) count++;
    cout << count << "\n";
}