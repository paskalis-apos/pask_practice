#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define TOMOD int(1e9 + 7);

int main() {
    int n , x;
    cin >> n >> x;

    vector<int> coins(n);
    for(auto &x : coins) {
        cin >> x;
    }

    vector<ll> dp(1e6 + 1);

    dp[0] = 1;
    for(int i = 0 ;i < n ;i ++) {
        for(int j = 0; j <= x; j++) {
            dp[j] %= TOMOD;
            if(j + coins[i] <= x) {
                dp[j + coins[i]] += dp[j];
            }
        }
    }

    cout << dp[x] << endl;
}