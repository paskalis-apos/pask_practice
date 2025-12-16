#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod int(1e9 + 7)

int main(){
    int n;
    cin >> n;
    vector<string>grid(n);
    for(auto &x : grid) {
        cin >> x;
    }

    vector<vector<ll>> dp(n , vector<ll>(n));
    dp[0][0] = 1;
    if(grid[0][0] == '*') {
        dp[0][0] = 0;
    }
    for(int i = 0 ;i < n;i++) {
        for(int j = 0; j < n;j ++) {
            dp[i][j] %= mod;
            if(grid[i][j] == '*') {
                continue;
            }
            if(j < n - 1 && grid[i][j+1] == '.') {
                dp[i][j+1] += dp[i][j];
            }
            if(i < n - 1 && grid[i + 1][j] == '.') {
                dp[i + 1][j] += dp[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}