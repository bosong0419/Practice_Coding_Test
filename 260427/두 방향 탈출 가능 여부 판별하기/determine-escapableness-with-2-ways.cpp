#include <iostream>
#include <vector>
using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1}; // 0 -> 남쪽, 1 -> 동쪽



void dfs(int x, int y, const vector<vector<int>>& graph, vector<vector<bool>>& visit, const int& n, const int& m) {
    
    for(int i = 0; i < 2; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
        if(!visit[new_x][new_y] && graph[new_x][new_y]) {
            visit[new_x][new_y] = true;
            dfs(new_x, new_y, graph, visit, n, m);
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    for(auto& row: graph) {
        for(auto& a: row)
            cin >> a;
    }
    if(!graph[0][0]) {
        cout << "0" << "\n";
        return 0;
    }
    visit[0][0] = true;
    dfs(0, 0, graph, visit, n, m);
    if(visit[n - 1][m - 1])
        cout << "1" << "\n";
    else
        cout << "0" << "\n";

    return 0;
}