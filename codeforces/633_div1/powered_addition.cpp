#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll minvalue = 0;
    for(auto &x : v) {
        cin >> x;
        minvalue = min(minvalue, x);
    }
    for(auto &x : v) {
        x -= minvalue;
    }

    int mintime = 0;
    for(int i = 1; i < n;i++) {
        int diff = v[i - 1] - v[i];
        if(diff <= 0) {
            continue;
        }
        for(int j = 0 ;j <= 30;j++) {
            int cur = (1 << j);
            if((diff | cur) == diff) {
                mintime = max(mintime , j + 1);
            }
        }
        v[i] += diff;

    }

    cout << mintime << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
}