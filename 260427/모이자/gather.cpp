#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto& a: A)
        cin >> a;
    
    int min_sum = 1e9;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++){
            sum += A[j] * abs(i - j);
        }
        min_sum = min(min_sum, sum);
    }
    cout << min_sum << "\n";
}