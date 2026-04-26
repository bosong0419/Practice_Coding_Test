#include <iostream>
#include <vector>
using namespace std;

int visit[1001];

void DFS(int n, const vector<vector<int>>& graph, int& count) {
    visit[n] = 1;
    for(const auto& a: graph[n]) {
        if(visit[a]) continue;
        count++;
        DFS(a, graph, count);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    DFS(1, graph, count);
    cout << count << "\n";
    return 0;
}