#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;

    for(int i = 0;i < n;i++) {
        ll num;
        cin >> num;
        ans += max(num, ll(1));
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}