#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll px , py , qx , qy;
    cin >> px >> py >> qx >> qy;
    ll DIST = (px - qx) * (px - qx) + (py - qy) * (py - qy);
    ll sum = 0;
    ll larger = 0;
    vector<ll> dists(n);
    for(auto &x : dists) {
        cin >> x;
        larger = max(larger, x);
        sum += x;
    }
    sum -= larger;
    if(larger > sum && (larger - sum) * (larger - sum) > DIST) {
        cout << "NO" << endl;
        return;
    }
    if((sum + larger) * (sum + larger) < DIST) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i < t;i++) {
        solve();
    }
}