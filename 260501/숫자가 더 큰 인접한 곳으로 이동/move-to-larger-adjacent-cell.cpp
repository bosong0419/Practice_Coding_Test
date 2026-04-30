#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(int x, int y, const vector<vector<int>>& grid) {
    int n = grid.size();
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int max_value = grid[x][y];
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
        if(max_value < grid[new_x][new_y]) {
            max_value = grid[new_x][new_y];
            cout << max_value << " ";
            find(new_x, new_y, grid);
            return;
        }
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    r--; c--;
    cout << grid[r][c] << " ";
    find(r, c, grid);
}