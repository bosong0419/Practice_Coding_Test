#include <iostream>
#include <vector>
using namespace std;

void boom(int r, int c, vector<vector<int>>& copy_grid) {
    int n = copy_grid.size();
    int len = copy_grid[r][c];
    for(int i = 0; i < len; i++) {    
        if(r + i < n)  copy_grid[r + i][c] = 0;
        if(r - i >= 0) copy_grid[r - i][c] = 0;
        if(c + i < n)  copy_grid[r][c + i] = 0;
        if(c - i >= 0) copy_grid[r][c - i] = 0;
    }
}

void gravity(vector<vector<int>>& copy_grid) {
    int n = copy_grid.size();
    for(int j = 0; j < n; j++) {
        int write_idx = n - 1;
        for(int read_idx = n - 1; read_idx >= 0; read_idx--) {
            if(copy_grid[read_idx][j]) {
                if(write_idx != read_idx) {
                    copy_grid[write_idx][j] = copy_grid[read_idx][j];
                    copy_grid[read_idx][j] = 0;
                }
                write_idx--;
            }
        }
    }
}

int count_pair(vector<vector<int>>& copy_grid) {
    int n = copy_grid.size();
    int count = 0;
    if(n == 1) return 0;

    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(copy_grid[i][j] && copy_grid[i][j] == copy_grid[i][j + 1])
                count++;
        }
    }
    for(int j = 0 ; j < n; j++) {
        for(int i = 0; i < n - 1; i++) {
            if(copy_grid[i][j] && copy_grid[i][j] == copy_grid[i + 1][j])
                count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int max_pair = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!grid[i][j]) continue;
            vector<vector<int>> copy_grid = grid;
            boom(i, j, copy_grid);
            gravity(copy_grid);
            max_pair = max(max_pair, count_pair(copy_grid));
        }
    }
    cout << max_pair << "\n";
}