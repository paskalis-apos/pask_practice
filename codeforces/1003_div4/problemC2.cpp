#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n , m;
    cin >> n >> m;
    vector<ll> a1(n);
    set<ll> a2;
    for(auto &x : a1) {
        cin >> x;
    }
    for(int i = 0 ;i < m ;i++) {
        ll temp;
        cin >> temp;
        a2.insert(temp);
    }

    a1[0] = min(a1[0], *a2.begin() - a1[0]);
    for(int i = 1; i < n ;i++) {
        ll sroute;
        auto pick2 = a2.lower_bound(a1[i] + a1[i - 1]);
        if(pick2 != a2.end()) {
            sroute = *pick2 - a1[i];
            if(a1[i] >= a1[i - 1]) {
                a1[i] = min(a1[i] ,sroute);
            }
            else {
                a1[i] = sroute;
            }
        }
    }

    bool valid = true;
    for(int i = 1 ;i < n; i++) {
        if(a1[i] < a1[i - 1]) {
            valid = false;
            break;
        }
    }
    if(valid) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    cout << endl;


}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}