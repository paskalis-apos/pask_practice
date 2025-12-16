#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int n , k;
    cin >> n >> k;
    vector<int> snakes(n + 1);

    for(int i = 1 ;i <= n ;i++) {
        cin >> snakes[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    int max_value = 0;
    for(int i = 1; i <= n; i++) {
        max_value = max(max_value, snakes[i]);
        dp[0][i] = max_value * i;
    }

    for(int i = 1; i<= k ;i++) {
        for(int j = 1; j <= n ;j++) {
            dp[i][j] = 1e9;
            int tomult = snakes[j];
            for(int c = j -1; c >= 0; c--) {
                dp[i][j] = min(dp[i][j], dp[i - 1][c] + (j - c) * tomult);
                tomult = max(tomult, snakes[c]);
            }
        }
    }


    int answer = dp[k][n];
    for(int i = 1; i <= n ;i++) {
        answer -= snakes[i];
    }

    cout << answer;


}