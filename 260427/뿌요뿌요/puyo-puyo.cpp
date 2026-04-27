#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; //NESW

void dfs(const int x, const int y, const vector<vector<int>>& graph, vector<vector<bool>>& visit, const int n, const int ans, int& block_size)
{
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
        if(!visit[new_x][new_y] && (graph[new_x][new_y] == ans)) {
            visit[new_x][new_y] = true;
            block_size++;
            dfs(new_x, new_y, graph, visit, n, ans, block_size);
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    for(auto& row: graph)
        for(auto& a: row)
            cin >> a;

    int max_block_size = 0;
    int bomb = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int block_size = 1;
            if(!visit[i][j]) {
                visit[i][j] = true;
                dfs(i, j, graph, visit, n, graph[i][j], block_size);
                if(block_size > max_block_size) max_block_size = block_size;
                if(block_size >= 4) bomb++;
            }
        }
    }
    cout << bomb << " " << max_block_size << "\n";
    return 0;
}