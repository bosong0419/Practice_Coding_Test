#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

int get_rectangle_sum(int x, int y, int width, int height, const vector<vector<int>>& grid) {
    int sum = 0;
    int curr_x = x;
    int curr_y = y;
    for(int i = 0; i < height; i++) {
        curr_x += dx[0];
        curr_y += dy[0];
        sum += grid[curr_x][curr_y];
    }
    for(int i = 0; i < width; i++) {
        curr_x += dx[1];
        curr_y += dy[1];
        sum += grid[curr_x][curr_y];
    }
    for(int i = 0; i < height; i++) {
        curr_x += dx[2];
        curr_y += dy[2];
        sum += grid[curr_x][curr_y];
    }
    for(int i = 0; i < width; i++) {
        curr_x += dx[3];
        curr_y += dy[3];
        sum += grid[curr_x][curr_y];
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
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int w = 1; w < n; w++) {
                for(int h = 1; h < n; h++) {
                    int new_i_h = i + dx[0] * h;
                    int new_j_h = j + dy[0] * h;
                    if(new_i_h < 0 || new_i_h >= n || new_j_h < 0 || new_j_h >= n) continue;
                    int new_i_w = new_i_h + dx[1] * w;
                    int new_j_w = new_j_h + dy[1] * w;
                    if(new_i_w < 0 || new_i_w >= n || new_j_w < 0 || new_j_w >= n) continue;
                    int new_i_h2 = new_i_w + dx[2] * h;
                    int new_j_h2 = new_j_w + dy[2] * h;
                    if(new_i_h2 < 0 || new_i_h2 >= n || new_j_h2 < 0 || new_j_h2 >= n) continue;
                    int current_sum = get_rectangle_sum(i, j, w, h, grid);
                    max_sum = max(current_sum, max_sum);
                }
            }
        }
    }
    cout << max_sum << "\n";
}