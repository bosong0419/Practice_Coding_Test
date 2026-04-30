#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combine (vector<vector<int>>& grid, const char dir) {
    if(dir == 'L') {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(!grid[i][j]) continue;
                if(grid[i][j] == grid[i][j + 1]) {
                    grid[i][j] *= 2;
                    grid[i][j + 1] = 0;
                }
            }
        }
    }
    else if(dir == 'R') {
        for(int i = 0; i < 4; i++) {
            for(int j = 3; j > 0; j--) {
                if(!grid[i][j]) continue;
                if(grid[i][j] == grid[i][j - 1]) {
                    grid[i][j] *= 2;
                    grid[i][j - 1] = 0;
                }
            }
        }
    }
    else if(dir == 'U') {
        for(int j = 0; j < 4; j++) {
            for(int i = 0; i < 3; i++) {
                if(!grid[i][j]) continue;
                if(grid[i][j] == grid[i + 1][j]) {
                    grid[i][j] *= 2;
                    grid[i + 1][j] = 0;
                }
            }
        }
    }
    else if(dir == 'D') {
        for(int j = 0; j < 4; j++) {
            for(int i = 3; i > 0; i--) {
                if(!grid[i][j]) continue;
                if(grid[i][j] == grid[i - 1][j]) {
                    grid[i][j] *= 2;
                    grid[i - 1][j] = 0;
                }
            }
        }
    }
}

void gravity (vector<vector<int>>& grid, const char dir) {
    if(dir == 'L') {
        for(int i = 0; i < 4; i++) {
            int write_index = 0;
            for(int j = 0; j < 4; j++) {
                if(grid[i][j]) { 
                    if(j != write_index) {
                        grid[i][write_index] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    write_index++;
                }
            }
        }
    }
    else if(dir == 'R') {
        for(int i = 0; i < 4; i++) {
            int write_index = 3;
            for(int j = 3; j >= 0; j--) {
                if(grid[i][j]) { 
                    if(j != write_index) {
                        grid[i][write_index] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    write_index--;
                }
            }
        }
    }
    else if(dir == 'U') {
        for(int j = 0; j < 4; j++) {
            int write_index = 0;
            for(int i = 0; i < 4; i++) {
                if(grid[i][j]) { 
                    if(i != write_index) {
                        grid[write_index][j] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    write_index++;
                }
            }
        }
    }
    else if(dir == 'D') {
        for(int j = 0; j < 4; j++) {
            int write_index = 3;
            for(int i = 3; i >= 0; i--) {
                if(grid[i][j]) { 
                    if(i != write_index) {
                        grid[write_index][j] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    write_index--;
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> grid(4, vector<int>(4));
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> grid[i][j];
    char dir;
    cin >> dir;

    gravity(grid, dir);
    combine(grid, dir);
    gravity(grid, dir);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}