#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);
    int n;
    cin >> n;

    vector<int> id1(n);
    vector<int> id2(n);

    for(auto &x : id1){
        cin >> x;
    }
    for(auto &x : id2){
        cin >> x;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for(int i = 1 ;i <= n;i++) {
        for(int j = 1; j <= n ; j++) {
            bool valid = abs(id1[i - 1] - id2[j -1]) <= 4;
            dp[i][j] = max(dp[i][j], dp[i -1][j -1] + valid);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j -1]);
        }
    } 

    cout << dp[n][n];
}