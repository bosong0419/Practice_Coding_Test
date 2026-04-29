#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rect {
    int r1, c1, r2, c2;
    int sum;
};

bool is_overlapped(const Rect& a, const Rect& b) {
    if(a.r1 > b.r2 || a.r2 < b.r1 || a.c1 > b.c2 || a.c2 < b.c1) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<Rect> rects;
    for(int x1 = 0; x1 < m; x1++)
        for(int x2 = x1; x2 < m; x2++)
            for(int y1 = 0; y1 < n; y1++)
                for(int y2 = y1; y2 < n; y2++) {
                    int current_sum = 0;
                    for(int i = y1; i <= y2; i++)
                        for(int j = x1; j <= x2; j++) {
                            current_sum += grid[i][j];
                        }
                    rects.push_back({y1, x1, y2, x2, current_sum});
                }

    int max_sum = -1e9;

    for(int i = 0; i < rects.size(); i++)
        for(int j = i + 1; j < rects.size(); j++)
            if(!is_overlapped(rects[i], rects[j]))
                max_sum = max(max_sum, rects[i].sum + rects[j].sum);
    cout << max_sum;
}