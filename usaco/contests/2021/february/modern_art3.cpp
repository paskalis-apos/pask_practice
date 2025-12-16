#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0;i < n;i++){ 
        dp[i][i] = 1;
    }

    for(int i = 1;i  < n ;i++) {
        for(int j = 0;j < n - i; j++) {
            dp[j][j + i] = dp[j + 1][j + i] + 1;
            for(int k = 0; k < i; k++) {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k + j] + dp[k + j + 1][i + j] - (v[j] == v[i + j]));
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}