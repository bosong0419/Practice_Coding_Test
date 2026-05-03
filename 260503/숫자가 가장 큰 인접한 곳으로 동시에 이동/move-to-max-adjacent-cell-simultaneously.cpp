#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; // NSWE

void move(vector<vector<int>>& grid, vector<vector<int>>& copy_count, int r, int c) {
    int n = grid.size();
    int max = -1e9;
    int max_dir;
    for(int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

        if(max < grid[nr][nc]) {
            max = grid[nr][nc];
            max_dir = i;
        }
    }
    copy_count[r + dx[max_dir]][c + dy[max_dir]]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> grid(n, vector<int>(n, 0)); 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    vector<vector<int>> count(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        count[r - 1][c - 1] = 1;
    }

    for(int i = 0; i < t; i++) {
        vector<vector<int>> copy_count(n, vector<int>(n, 0));
        for(int row = 0; row < n; row++) 
            for(int col = 0; col < n; col++) 
                if(count[row][col]) move(grid, copy_count, row, col);

        for(int row = 0; row < n; row++) 
            for(int col = 0; col < n; col++) {
                if(copy_count[row][col] >= 2) copy_count[row][col] = 0;
                count[row][col] = copy_count[row][col];
            }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(count[i][j] == 1) cnt++;
    cout << cnt << "\n";
}