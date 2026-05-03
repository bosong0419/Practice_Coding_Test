#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; // NESW

struct Marble {
    int num, r, c, d, w;
};

struct Cell {
    int count, total_w, max_num, dir;
};

int get_dir(char c) {
    if(c == 'U') return 0;
    else if (c == 'R') return 1;
    else if (c == 'D') return 2;
    else if (c == 'L') return 3;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<Marble> marbles;
    for(int i = 1; i <= m; i++) {
        int r, c, w;
        char d;
        cin >> r >> c >> d >> w;
        r--; c--;
        marbles.push_back({i, r, c, get_dir(d), w});
    }

    for(int i = 0; i < t; i++) {
        vector<vector<Cell>> next_grid(n, vector<Cell>(n, {0, 0, 0, 0}));
        for(auto& m: marbles) {
            int nr = m.r + dx[m.d];
            int nc = m.c + dy[m.d];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) {
                m.d = (m.d + 2) % 4;
                nr = m.r;
                nc = m.c;
            }
            else {
                m.r = nr;
                m.c = nc;
            }
            
            next_grid[nr][nc].count++;
            next_grid[nr][nc].total_w += m.w;

            if(m.num > next_grid[nr][nc].max_num) {
                next_grid[nr][nc].max_num = m.num;
                next_grid[nr][nc].dir = m.d;
            }
        }

        vector<Marble> next_marbles;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(next_grid[r][c].count > 0) {
                    next_marbles.push_back({
                        next_grid[r][c].max_num,
                        r,
                        c,
                        next_grid[r][c].dir,
                        next_grid[r][c].total_w
                    });
                }
            }
        }
        marbles = next_marbles;
    }
    int max_weight = 0;
    for(auto& m : marbles)
        max_weight = max(max_weight, m.w);
    cout << marbles.size() << " " << max_weight << "\n";
    return 0;
}