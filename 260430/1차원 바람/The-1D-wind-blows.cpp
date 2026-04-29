#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_exist(int a, int b, int m, const vector<vector<int>>& building) {
    for(int i = 0; i < m; i++)
        if(building[a][i] == building[b][i]) return true;
    return false;
}

void rotate_building(int row, int direction, vector<vector<int>>& building) {
    if(direction == 1) 
        rotate(building[row].begin(), building[row].begin() + 1, building[row].end());
    else if(direction == -1)
        rotate(building[row].rbegin(), building[row].rbegin() + 1, building[row].rend());
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> building(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> building[i][j];
    vector<int> first_wind_row(q);
    vector<char> dir(q);
    for(int i = 0; i < q; i++)
        cin >> first_wind_row[i] >> dir[i];

    int iter = 0;
    while(iter < q) {
        int curr_row = first_wind_row[iter] - 1;
        int curr_dir = 0;

        if(dir[iter] == 'L') curr_dir = -1;
        else if(dir[iter] == 'R') curr_dir = 1;
        rotate_building(curr_row, curr_dir, building);
        
        int curr_row_up = curr_row;
        int curr_row_down = curr_row;
        bool up_flag = true;
        bool down_flag = true;
        while(up_flag || down_flag) {
            curr_dir = -curr_dir;
            if(up_flag) {
                if(curr_row_up - 1 < 0 || !is_exist(curr_row_up, curr_row_up - 1, m, building)) 
                    up_flag = false;
                curr_row_up--;
                if(up_flag) rotate_building(curr_row_up, curr_dir, building);
            }
            if(down_flag) {
                if(curr_row_down + 1 >= n || !is_exist(curr_row_down, curr_row_down + 1, m, building)) 
                    down_flag = false;
                curr_row_down++;
                if(down_flag) rotate_building(curr_row_down, curr_dir, building);
            }
        }
        iter++;
    }
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << building[i][j] << " ";
        }
        cout << "\n";
    }
}