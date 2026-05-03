#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void move(int target, vector<vector<int>>& grid) {
    int n = grid.size();
    int r, c;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == target) {r = i; c = j;}


    int max = -1e9;
    int max_r, max_c;
    for(int i = 0; i < 8; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

        if(max < grid[nr][nc]) {
            max = grid[nr][nc];
            max_r = nr;
            max_c = nc;
        }
    }
    swap(grid[r][c], grid[max_r][max_c]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n, 0)); 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n * n; j++) {
            move(j, grid);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
            
}