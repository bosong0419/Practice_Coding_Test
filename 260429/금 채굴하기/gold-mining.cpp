#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> golds;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int value;
            cin >> value;
            if(value) golds.push_back({i, j});
        }

    int max_gold = 0;
    for(int K = 0; K <= n; K++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int gold_count = 0;
                for(const auto& gold: golds) {
                    int dist = abs(gold.first - i) + abs(gold.second - j);
                    if(dist <= K) gold_count++;
                }
                if((pow(K, 2) + pow(K + 1, 2) <= gold_count * m)) max_gold = max(max_gold, gold_count);
            }
        }
    }
    cout << max_gold << "\n";
}