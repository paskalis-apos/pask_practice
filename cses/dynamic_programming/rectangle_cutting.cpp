#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a , b;
    cin >> a >> b;

    vector<vector<ll>>dp(501, vector<ll>(501, 1e9));

    for(int i = 1 ;i <= 500; i++) {
        for(int j = 1; j <= 500; j++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            for(int counter = 1; counter < i; counter++) {
                dp[i][j] = min(dp[i][j], dp[counter][j] + dp[i - counter][j] + 1);
            }
            for(int counter = 1; counter < j; counter++) {
                dp[i][j] = min(dp[i][j], dp[i][counter] + dp[i][j - counter] + 1);
            }
        }
    }

    cout << dp[a][b] << endl;
}