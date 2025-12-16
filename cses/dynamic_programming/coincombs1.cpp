#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define TOMOD 1000000000 + 7

int main() {
    int n , x;
    cin >> n >> x;

    vector<ll> coins(n);
    for(auto &x : coins) {
        cin >> x;
    }
    vector<ll> dp(1000000 + 1);
    dp[0] = 1;

    for(int i = 0; i <= x; i++) {
        dp[i] %= TOMOD;
        for(auto &y :coins) {
            if(i + y <= x) {
                dp[i + y] += dp[i];
            }
        }
    }

    cout << dp[x] << endl;
}