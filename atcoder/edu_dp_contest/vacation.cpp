#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int>> activities(n , vector<int>(3));
    for(int i = 0 ;i < n; i++) {
        cin >> activities[i][0] >> activities[i][1] >> activities[i][2];
    }

    vector<vector<int>> dp(n + 1, vector<int>(3));

    for(int i = 0 ;i < n;i++) {
        for(int j = 0 ;j < 3; j++) {
            if(j != 0) {
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + activities[i ][0]);
            }
            if(j != 1) {
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + activities[i ][1]);
            }
            if(j != 2) {
                dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + activities[i ][2]);
            }
        }
    }

    int answer = max(dp[n][0], max(dp[n][1] , dp[n][2]));
    cout << answer << endl;
}