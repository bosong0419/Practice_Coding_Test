#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool move_snake(vector<vector<int>>& grid, char dir, int& time, queue<pair<int, int>>& q) {
    int n = grid.size();
    time++;
    int nr = q.back().first;
    int nc = q.back().second;
    if(dir == 'R') nc++;
    else if(dir == 'L') nc--;
    else if(dir == 'U') nr--;
    else if(dir == 'D') nr++;

    if(nc < 0 || nc >= n || nr < 0 || nr >= n) return true;

    q.push({nr, nc});
    if(grid[nr][nc] == 0 || grid[nr][nc] == -1) {
        grid[q.front().first][q.front().second] = 0;
        q.pop();
    }
    if(grid[nr][nc] == -1) return true;
    grid[nr][nc] = -1;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(n, 0)); 
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        grid[x - 1][y - 1] = 1;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = -1;
    int time = 0;
    for(int i = 0; i < k; i++) {
        char dir;
        int dist;
        cin >> dir >> dist;

        bool is_end = false;
        for(int j = 0; j < dist; j++) {
            is_end = move_snake(grid, dir, time, q);
            if(is_end) {
                cout << time << "\n";
                return 0;
            }
        }
    }
    cout << time << "\n";
    return 0;
}