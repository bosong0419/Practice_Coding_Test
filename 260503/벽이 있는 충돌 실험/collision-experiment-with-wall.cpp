#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; // NESW

struct Marble {
    int r, c;
    int dir;
};

int get_dir(char c) {
    if(c == 'U') return 0;
    else if (c == 'R') return 1;
    else if (c == 'D') return 2;
    else if (c == 'L') return 3;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        vector<Marble> marbles;
        for(int i = 0; i < m; i++) {
            int r, c;
            char dir;
            cin >> r >> c >> dir;
            r--; c--;
            marbles.push_back({r, c, get_dir(dir)});
        }

        for(int i = 0; i < 2 * n; i++) {
            vector<vector<int>> count(n, vector<int>(n));
            for(auto& m: marbles) {
                int nr = m.r + dx[m.dir];
                int nc = m.c + dy[m.dir];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                    m.dir = (m.dir + 2) % 4;
                else {
                    m.r = nr;
                    m.c = nc;
                }
                count[m.r][m.c]++;
            }

            vector<Marble> next_marbles;
            for(auto& m: marbles) {
                if(count[m.r][m.c] == 1)
                    next_marbles.push_back(m);
            }
            marbles = next_marbles;
        }
        cout << marbles.size() << "\n";
    }
}