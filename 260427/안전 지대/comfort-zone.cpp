#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1}; // NWSE



void dfs(int x, int y, const vector<vector<int>>& graph, vector<vector<bool>>& visit, const int n, const int m, const int p) {
    
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
        if(!visit[new_x][new_y] && graph[new_x][new_y] > p) {
            visit[new_x][new_y] = true;
            dfs(new_x, new_y, graph, visit, n, m, p);
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    int K = 0;
    for(auto& row: graph) {
        for(auto& a: row) {
            cin >> a;
            if(K < a) K = a; // max
        }
    }
    

    int max_K = 0;
    int max_count = 0;
    for(int p = K - 1; p >= 1; p--) { // K == 1일때 확인
        int count = 0;
        visit.assign(n, vector<bool>(m, false));
 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visit[i][j] && graph[i][j] > p) {
                    count++;
                    visit[i][j] = true;
                    dfs(i, j, graph, visit, n, m, p);
                }
            }
        }
        if(count >= max_count) {
            max_count = count;
            max_K = p;
        }
    }

    cout << max_K  << " " << max_count << "\n";
    
    return 0;
}