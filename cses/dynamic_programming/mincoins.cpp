#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , x;
    cin >> n >> x;

    vector<int>coins(n);
    for(auto &x : coins) {
        cin >> x;
    }
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0 ;i < x; i++) {
        if(dp[i] == INT_MAX) {
            continue;
        }
        for(auto &p : coins) {
            if(i + p <= x) {
                dp[i + p] = min(dp[i + p], dp[i] + 1);
            }
        }
    }

    if(dp[x] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << dp[x];
    }

    cout << endl;

}