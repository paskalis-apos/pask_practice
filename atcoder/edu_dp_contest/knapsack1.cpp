#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n , w;
    cin >> n >> w;

    vector<pair<int,int>> items(n);
    for(auto &x : items) {
        cin >> x.first >> x.second;
    }

    vector<vector<ll>>dp (n + 1, vector<ll>(w+ 1));

    for(int i = 1 ;i <= n; i++) {
        for(int j = 0 ;j <= w; j++) {
            dp[i][j] = dp[i -1][j];
            if(j - items[i - 1].first >= 0) {
                dp[i][j] = max(dp[i][j], dp[i -1][j - items[i -1].first] + items[i - 1].second);
            }
        }
    }

    cout << dp[n][w];


}