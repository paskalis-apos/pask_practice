#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    reverse(v.begin(), v.end());
    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = v[0] - 1;
    for(int i = 2;i < n;i++) {
        dp[i] = min(v[i - 1] - ll(1) + dp[i - 1], v[i - 1] + max(ll(0), v[i - 2] - (n - i + 1)) + dp[i - 2]);
    }
    dp[n] = v[n - 1] + max(ll(0) , v[n - 2] - 1 + dp[n - 2]);


    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}