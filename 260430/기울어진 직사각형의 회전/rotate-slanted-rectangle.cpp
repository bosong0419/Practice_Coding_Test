#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_grid(int r, int c, int h, int w, int dir, int n, vector<vector<int>>& grid) {
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, -1, 1};
    int move[4] = {h, w, h, w};
    vector<pair<int, int>> coords;
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < move[i]; j++) {
            r += dx[i];
            c += dy[i];
            coords.push_back({r, c});
        }
    }

    vector<int> values;
    for(auto& pos: coords) values.push_back(grid[pos.first][pos.second]);
    if(dir) rotate(values.begin(), values.begin() + 1, values.end());
    else rotate(values.rbegin(), values.rbegin() + 1, values.rend());
    for(int i = 0; i < coords.size(); i++)
        grid[coords[i].first][coords[i].second] = values[i];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    int r, c, h1, w1, h2, w2, dir;
    cin >> r >> c >> h1 >> w1 >> h2 >> w2 >> dir;

    rotate_grid(r - 1, c - 1, h1, w1, dir, n, grid);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}