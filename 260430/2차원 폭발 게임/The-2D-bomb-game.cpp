#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_boom(const vector<vector<int>>& grid, int col, int m) {
    int n = grid.size();
    int consec = 1;
    if(!grid[n - 1][col]) return false;

    for(int i = 0; i < n - 1; i++) {
        if(!grid[i][col]) continue;
        if(grid[i][col] == grid[i + 1][col]) {
            consec++;
            if(consec >= m) return true;
        }
        else
            consec = 1;
    }
    return false;
}

void erase_bomb(vector<vector<int>>& grid, int col, int m) {
    int n = grid.size();
    if(!grid[n - 1][col]) return;
    int consec = 1;
    int new_idx = 0;
    vector<pair<int, int>> erase_idx;

    for(int i = 0; i < n - 1; i++) {
        if(grid[i][col] == grid[i + 1][col]) {
            consec++;
        }
        else {
            if(consec >= m)
                erase_idx.push_back({new_idx, new_idx + consec});
            new_idx = i + 1;
            consec = 1;
        }
    }
    if(consec >= m) {
        erase_idx.push_back({new_idx, new_idx + consec});
    }

    for(int i = 0; i < erase_idx.size(); i++) {
        int start = erase_idx[i].first;
        int end = erase_idx[i].second;
        for(int j = start; j < end; j++)
            grid[j][col] = 0;
    }
}

void gravity(vector<vector<int>>& grid) {
    int n = grid.size();
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

void rotate_90(vector<vector<int>>& grid) {
    int n = grid.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(grid[i][j], grid[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        reverse(grid[i].begin(), grid[i].end());
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    if(m == 1) {
        cout << "0" << "\n";
        return 0;
    }
    for(int i = 0; i < k; i++) {
        for(int col = 0; col < n; col++) {
            while(is_boom(grid, col, m)) {
                erase_bomb(grid, col, m);
                gravity(grid);
            }
        }
        rotate_90(grid);
        gravity(grid);
    }
    
    for(int col = 0; col < n; col++) {
        while(is_boom(grid, col, m)) {
            erase_bomb(grid, col, m);
            gravity(grid);
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            if(grid[i][j]) count++;
    cout << count << "\n";
}