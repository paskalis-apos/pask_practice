#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("248.in","r",stdin);
    freopen("248.out","w", stdout);
    int n;
    cin >> n;
    vector<int>v(n);
    int ans = 0;
    for(auto &x : v) {
        cin >> x;
        ans = max(0, x);
    }
    vector<vector<int>> dp(249, vector<int>(249));
    for(int i = 0;i < n; i++) {
        dp[i][i] = v[i];
    }
    for(int d =1 ; d < n; d++) {
        for(int i = 0;i < n - d; i++) {
            for(int j = i; j < i + d; j++) {
                if(dp[i][j] != 0 && dp[i][j] == dp[j + 1][i + d]) {
                    dp[i][i + d] = dp[i][j] + 1;
                    ans = max(ans, dp[i][i + d]);
                }
            }
        }
    }

    cout << ans << endl;
}