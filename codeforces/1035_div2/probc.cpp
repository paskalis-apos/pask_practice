#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n , l , r , k;
    cin >> n >> l >> r >> k;
    if(n % 2 == 1) {
        cout << l << endl;
        return;
    }
    if(n == 2) {
        cout << -1 << endl;
        return;
    }
    ll cur = 1;
    while(cur <= l) {
        cur *= 2;
    }
    if(cur > r) {
        cout << -1 << endl;
        return;
    }
    if(k <= n - 2) {
        cout << l << endl;
        return;
    }
    cout << cur;
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}