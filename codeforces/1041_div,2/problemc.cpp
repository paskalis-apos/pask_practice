#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n , k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    multiset<ll> bigger, smaller;
    ll mincost = INT_MAX;
    ll total = 0;
    for(auto &x : a) {
        cin >> x;
    }
    for(auto &x : b) {
        cin >> x;
    }
    for(int i = 0;i < n; i++) {
        bigger.insert(max(a[i], b[i]));
        smaller.insert(min(a[i], b[i]));
        total += abs(a[i] - b[i]);
    }
    
    for(int i = 0 ;i < n;i++) {
        auto it = bigger.upper_bound(max(a[i],b[i]));
        it--;
        if(it != bigger.begin()) {
            it--;
            mincost = min(mincost, max(ll(0), min(a[i], b[i]) - *it));
        }
        it = smaller.lower_bound(min(a[i], b[i])) ;
        if(next(it) != smaller.end()) {
            it++;
            mincost = min(mincost , max(ll(0), *it - max(a[i], b[i])));
        }
    }

    total += 2 * mincost;
    cout << total << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t ;i++ ){
        solve();
    }
}