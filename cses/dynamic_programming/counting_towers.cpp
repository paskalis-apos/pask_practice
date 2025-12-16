#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod int(1e9 + 7);

int main() {
    vector<pair<ll,ll>> dp(1e6 + 1);
    dp[1].first = 1;
    dp[1].second = 1;
    for(int i = 2 ;i  <= 1e6 ;i++) {
        dp[i].first = 2 * dp[i-1].first + dp[i -1].second;
        dp[i].second = dp[i -1].second * 4 + dp[i - 1].first;
        dp[i].first %= mod;
        dp[i].second %= mod;
    }

    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        int x;
        cin >> x;
        int answer = (dp[x].first + dp[x].second) % mod;
        cout << answer << endl;
    }
}