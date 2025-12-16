#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int>coins(n);
    for(auto &x: coins) {
        cin >> x;
    }

    vector<vector<bool>>dp(n + 1, vector<bool>(n * 1000 + 1));
    dp[0][0] = true;
    for(int i = 1 ; i <= n; i++) {
        for(int j = 0; j<= n * 1000; j++) {
            if(dp[i - 1][j] == true) {
                dp[i][j] = true;
                
            }
            if(j - coins[i - 1] >= 0) {
                if(dp[i -1][j - coins[i -1]] == true) {
                    dp[i][j] = true;
                }
            }
        }
    }
    int answer = 0;
    for(int i = 1 ;i <= n * 1000; i++) {
        if(dp[n][i] == true) {
            answer++;
        }
    }
    cout << answer << endl;
    for(int i = 1 ;i <= n * 1000; i++) {
        if(dp[n][i] == true) {
            cout << i << endl;
        }
    }



}