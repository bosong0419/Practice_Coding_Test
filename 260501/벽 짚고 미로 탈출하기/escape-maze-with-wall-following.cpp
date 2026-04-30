#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 시작 위치에는 벽이 없고 (x+1, y)에는 항상 벽이 주어진다는 조건
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    x--; y--;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dir = 0;
    int time = 0;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(4, false)));
    while(1) {
        if(visited[x][y][dir]) {
            cout << "-1\n";
            return 0;
        }
        visited[x][y][dir] = true;
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];
        int x_right = x + dx[(dir + 1) % 4];
        int y_right = y + dy[(dir + 1) % 4];
        if(grid[x_right][y_right] == '#') {
            if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
                time++;
                cout << time;
                return 0;
            }
            if(grid[new_x][new_y] == '#') {
                dir = (dir + 3) % 4;
                continue;
            }
            x = new_x;
            y = new_y;
            time++;
        }
        else {
            dir = (dir + 1) % 4;
            x += dx[dir];
            y += dy[dir];
            time++;
        }
    }
}