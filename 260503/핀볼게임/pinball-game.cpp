#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1}; // NSEW

int move(vector<vector<int>>& grid, int r, int c, int dir, int time) {
    int n = grid.size();
    time++;
    if(grid[r][c] == 1) 
        dir = (dir + 2) % 4;
    else if(grid[r][c] == 2) 
        dir = (dir ^ 1 + 2) % 4;

    int nr = r + dx[dir];
    int nc = c + dy[dir];
    if(nr < 0 || nr >= n || nc < 0 || nc >= n) return ++time;
    return move(grid, nr, nc, dir, time);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0)); 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int max_time = 0;
    for(int i = 0; i < n; i++) {
        int time = 0;
        max_time = max({max_time, move(grid, 0, i, 1, time), move(grid, i, 0, 2, time),
                        move(grid, n - 1, i, 0, time), move(grid, i, n - 1, 3, time)});
    }
    cout << max_time << "\n";
    return 0;
}