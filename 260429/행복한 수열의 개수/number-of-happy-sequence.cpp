#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for(auto& row: v)
        for(auto& a: row)
            cin >> a;
    
    if(m == 1) {
        cout << 2 * n << "\n";
        return 0;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        int row_consec = 1;
        int col_consec = 1;
        bool row_counted = false;
        bool col_counted = false;
        for(int j = 0; j < n - 1; j++) {
            if(!row_counted) {
                if(v[i][j] == v[i][j + 1]) {
                    row_consec++;
                    if(row_consec >= m) {
                        count++;
                        row_counted = true;
                    }
                }
                else row_consec = 1;
            }

            if(!col_counted) {
                if(v[j][i] == v[j + 1][i]) {
                    col_consec++;
                    if(col_consec >= m) {
                        count++;
                        col_counted = true;
                    }
                }
                else col_consec = 1;
            }
        }
    }
    cout << count << "\n";
}