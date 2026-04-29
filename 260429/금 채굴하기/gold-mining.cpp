#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void bfs(int x, int y, int n, int current_depth, int target_depth, const vector<vector<int>>& grid, vector<vector<int>>& visit, int& gold_count) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1}; // NESW
    if(current_depth > target_depth) return;

    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
        if(visit[new_x][new_y]) continue;
        visit[new_x][new_y] = 1;
        if(grid[new_x][new_y]) gold_count++;
        bfs(new_x, new_y, n, current_depth + 1, target_depth, grid, visit, gold_count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> visit(n, vector<int>(n, 0));
    int max_gold = 0;
    for(int K = 1; K <= n; K++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int gold_count = 0;
                visit[i][j] = 1;
                if(grid[i][j]) gold_count++;
                bfs(i, j, n, 1, K, grid, visit, gold_count);
                visit.assign(n, vector<int>(n, 0));

                if((pow(K, 2) + pow(K + 1, 2) <= gold_count * m)) max_gold = max(max_gold, gold_count);
            }
        }
    }
    cout << max_gold << "\n";
}