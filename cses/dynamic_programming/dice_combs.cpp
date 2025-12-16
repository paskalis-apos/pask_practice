#include<bits/stdc++.h>
using namespace std;
#define TOMODULE 1000000000 + 7;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> dp(1000000 + 7);

    dp[0] = 1;
    for(int i = 0; i < n + 6; i++) {
        dp[i] %= TOMODULE;
        for(int j = i + 1; j <= i + 6; j ++) {
            dp[j] += dp[i];
        }
    }

    cout << dp[n] << endl;
}