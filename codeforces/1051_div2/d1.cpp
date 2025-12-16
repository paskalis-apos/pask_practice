#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    ll dp[n + 1][n + 1][n + 1];
    for(int i = 0;i <=n ;i++) {
        for(int j = 0; j <= n;j ++) {
            for(int k = 0; k <= n; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for(int i = 0;i < n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= n ;k++) {
                if(v[i] >= j) {
                    dp[i + 1][v[i]][k] = (dp[i + 1][v[i]][k] + dp[i][j][k]) % MOD;
                }
                else if(v[i] < j && v[i] >= k) {
                    dp[i + 1][j][v[i]] =(dp[i + 1][j][v[i]] + dp[i][j][k]) % MOD;
                }
                dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD; 

            }
        }
    }
    ll sum = 0;

    for(int i = 0 ;i <=n ;i++) {
        for(int j = 0;j <= n; j++) {
            sum = (sum + dp[n][i][j]) % MOD;
        }
    }
    cout << sum << endl;
}

int main (){
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}