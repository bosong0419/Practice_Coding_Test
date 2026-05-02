#include <iostream>
#include <vector>
using namespace std;

void roll_dice(char dir, const vector<vector<int>>& grid, int dice[]) {
    int top = dice[0], bot = dice[1], fro = dice[2], bac = dice[3], lef = dice[4], rig = dice[5];
    if(dir == 'R') {
        dice[0] = lef;
        dice[1] = rig;
        dice[4] = bot;
        dice[5] = top;
    }
    else if(dir == 'L') {
        dice[0] = rig;
        dice[1] = lef;
        dice[4] = top;
        dice[5] = bot;
    }
    else if(dir == 'U') {
        dice[0] = fro;
        dice[1] = bac;
        dice[2] = bot;
        dice[3] = top;
    }
    else if(dir == 'D') {
        dice[0] = bac;
        dice[1] = fro;
        dice[2] = top;
        dice[3] = bot;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--; c--;
    vector<vector<int>> grid(n, vector<int>(n));
    int dice[6] = {1, 6, 2, 5, 4, 3}; // Top, Bottom, Front, Back, Left, Right
    grid[r][c] = dice[1];

    for(int i = 0; i < m; i++) {
        char dir;
        cin >> dir;
        int nr = r, nc = c;
        if(dir == 'R') nc++;
        else if(dir == 'L') nc--;
        else if(dir == 'U') nr--;
        else if(dir == 'D') nr++;

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

        r = nr;
        c = nc;
        roll_dice(dir, grid, dice);
        grid[r][c] = dice[1];
    }

    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sum += grid[i][j];
    cout << sum << "\n";
}