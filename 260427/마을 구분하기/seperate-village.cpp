#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1}; // NWSE



int dfs(int x, int y, const vector<vector<int>>& graph, vector<vector<bool>>& visit, const int n, int& person) {
    
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
        if(!visit[new_x][new_y] && graph[new_x][new_y]) {
            person++;
            visit[new_x][new_y] = true;
            dfs(new_x, new_y, graph, visit, n, person);
        }
    }
    return person;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    for(auto& row: graph) {
        for(auto& a: row)
            cin >> a;
    }
    

    int count = 0;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visit[i][j] && graph[i][j]) {
                count++;
                visit[i][j] = true;
                int person = 1;
                person = dfs(i, j, graph, visit, n, person);
                v.push_back(person);
            }
        }
    }
    cout << count << "\n";
    sort(v.begin(), v.end());
    for(auto &a: v)
        cout << a << "\n";

    return 0;
}