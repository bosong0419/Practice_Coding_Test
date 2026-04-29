#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int get_rectangle_sum(int x, int y, int width, int height, int n, const vector<vector<int>>& grid) {
    int sum = 0;
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, -1, 1};
    int move[4] = {height, width, height, width};
    
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < move[i]; j++) {
            x += dx[i];
            y += dy[i];

            if(x < 0 || x >= n || y < 0 || y >= n)
                return 0;

            sum += grid[x][y];
        }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int max_sum = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            for(int w = 1; w < n; w++) 
                for(int h = 1; h < n; h++) 
                    max_sum = max(get_rectangle_sum(i, j, w, h, n, grid), max_sum);
    cout << max_sum << "\n";
    return 0;
}