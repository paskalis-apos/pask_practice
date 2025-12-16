#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    ll n;
    cin >> n;
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll ans = 0;
    int xdist = 0;
    int ydist = 0;
    if(r1 > r2) {
        xdist = n - r2;
    }
    else if(r1 < r2) {
        xdist = r2;
    }
    if(c1 > c2 ){
        ydist = n - c2;
    }
    else if(c1 < c2) {
        ydist = c2;
    }

    ans = max(xdist, ydist);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}