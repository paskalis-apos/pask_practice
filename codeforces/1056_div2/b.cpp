#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k;
    cin >> n >> k;
    int startk = k;
    if(k == n * n - 1) {
        cout << "NO" << endl;
        return;
    }

    vector<vector<char>> grid(n, vector<char>(n));
    grid[0][0] = 'R';
    grid[0][1] = 'L';

    for(int i = n - 1;i >= 0;i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(k > 0) {
                grid[i][j] = 'D';
                k--;
                continue;
            }
            else if(i == 0 && j == 1) {
                break;
            }
            if(i == 0) {
                grid[i][j] = 'L';
            }
            else {
                grid[i][j] = 'U';
            }
        }
    }
    if(startk == n * n) {
        grid[0][0] = grid[0][1] = 'U';
    }
    cout << "YES" << endl;
    for(auto &x : grid) {
        for(auto &y : x) {
            cout << y;
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}