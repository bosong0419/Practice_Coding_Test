#include <iostream>
#include <vector>
using namespace std;

void boom(int r, int c, int n, vector<vector<int>>& grid) {
    int len = grid[r][c];
    for(int i = 0; i < len; i++) {    
        if(r + i < n)  grid[r + i][c] = 0;
        if(r - i >= 0) grid[r - i][c] = 0;
        if(c + i < n)  grid[r][c + i] = 0;
        if(c - i >= 0) grid[r][c - i] = 0;
    }
}

void gravity(int r, int c, int n, vector<vector<int>>& grid) {
    for(int j = 0; j < n; j++) {
        int write_idx = n - 1;
        for(int read_idx = n - 1; read_idx >= 0; read_idx--) {
            if(grid[read_idx][j]) {
                if(write_idx != read_idx) {
                    grid[write_idx][j] = grid[read_idx][j];
                    grid[read_idx][j] = 0;
                }
                write_idx--;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    int r, c;
    cin >> r >> c;
    r--; c--;
    boom(r, c, n, grid);
    gravity(r, c, n, grid);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}