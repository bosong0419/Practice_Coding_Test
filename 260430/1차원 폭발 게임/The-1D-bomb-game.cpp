#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_boom(const vector<int>& v, int m) {
    if(v.empty()) return false;
    int consec = 1;
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] == v[i + 1]) {
            consec++;
            if(consec >= m) return true;
        }
        else
            consec = 1;
    }
    return false;
}

void erase_bomb(vector<int>& v, int m) {
    int consec = 1;
    int new_idx = 0;
    vector<pair<int, int>> erase_idx;
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] == v[i + 1]) {
            consec++;
            if(i + 1 == v.size() - 1 && consec >= m) {
                erase_idx.push_back({new_idx, new_idx + consec});
            }
        }
        else {
            if(consec >= m)
                erase_idx.push_back({new_idx, new_idx + consec});
            new_idx = i + 1;
            consec = 1;
        }
    }
    for(int i = v.size() - 1; i >= 0; i--) {
        if(erase_idx.empty()) return;
        if(i == erase_idx.back().first) {
            v.erase(v.begin() + erase_idx.back().first, v.begin() + erase_idx.back().second);
            erase_idx.pop_back();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    if(m == 1) {
        cout << "0" << "\n";
        return 0;
    }

    while(is_boom(v, m)) {
        erase_bomb(v, m);
    }

    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}