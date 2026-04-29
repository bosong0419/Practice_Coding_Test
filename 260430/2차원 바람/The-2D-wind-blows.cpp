#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_grid(int r1, int c1, int r2, int c2, int n, int m, vector<vector<int>>& grid) {
    vector<pair<int, int>> coords;
    for(int j = c1; j < c2; j++) coords.push_back({r1, j});
    for(int i = r1; i < r2; i++) coords.push_back({i, c2});
    for(int j = c2; j > c1; j--) coords.push_back({r2, j});
    for(int i = r2; i > r1; i--) coords.push_back({i, c1});

    vector<int> values;
    for(auto& pos: coords) values.push_back(grid[pos.first][pos.second]);
    rotate(values.rbegin(), values.rbegin() + 1, values.rend());
    for(int i = 0; i < coords.size(); i++)
        grid[coords[i].first][coords[i].second] = values[i];
}

int compute_mean(int r, int c, int n, int m, const vector<vector<int>>& grid) { // 동시에
    int sum = grid[r][c];
    int count = 1;
    if(r + 1 < n) {
        count++;
        sum += grid[r + 1][c];
    }
    if(r - 1 >= 0) {
        count++;
        sum += grid[r - 1][c];
    }
    if(c + 1 < m) {
        count++;
        sum += grid[r][c + 1];
    }
    if(c - 1 >= 0) {
        count++;
        sum += grid[r][c - 1];
    }
    return sum / count;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<int> r1(q);
    vector<int> r2(q);
    vector<int> c1(q);
    vector<int> c2(q);
    for(int i = 0; i < q; i++)
        cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];

    int iter = 0;
    while(iter < q) {
        rotate_grid(r1[iter] - 1, c1[iter] - 1, r2[iter] - 1, c2[iter] - 1, n, m, grid);
        vector<vector<int>> new_grid(n, vector<int>(m, 0));

        for(int i = r1[iter] - 1; i <= r2[iter] - 1; i++) 
            for(int j = c1[iter] - 1; j <= c2[iter] - 1; j++) 
                new_grid[i][j] = compute_mean(i, j, n, m, grid);
        for(int i = r1[iter] - 1; i <= r2[iter] - 1; i++) 
            for(int j = c1[iter] - 1; j <= c2[iter] - 1; j++) 
                grid[i][j] = new_grid[i][j];
        iter++;
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}