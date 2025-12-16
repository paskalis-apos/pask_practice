#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m , k;
    cin >> n >> m>> k;

    int grid[n + 1][m + 1];
    vector<pair<int,int>> emptycells;
    int totalgold = 0;
    for(int i = 0;i <= n;i++) {
        grid[i][0] = 0;
    }
    for(int j = 0; j<= m; j ++) {
        grid[0][j] = 0;
    }
    for(int i = 1; i<= n; i++) {
        for(int j = 1; j<= m; j++) {
            char c;
            cin >> c;
            grid[i][j] = grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
            if(c == 'g') {
                grid[i][j]++;
                totalgold++;
            }
            else if(c == '.') {
                emptycells.push_back({i , j});
            }
        }
    }

    int minlost = INT_MAX;
    for(auto &x : emptycells) {
        int ismall = max(0, x.first - k );
        int jsmall = max(0 ,x.second - k);
        int ibig = min(n , x.first + k - 1);
        int jbig = min(m , x.second + k - 1);
        int cur= grid[ibig][jbig] - grid[ibig][jsmall] - grid[ismall][jbig] + grid[ismall][jsmall];
        minlost = min(minlost, cur);
    }

    int ans = totalgold - minlost;
    cout << ans << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}