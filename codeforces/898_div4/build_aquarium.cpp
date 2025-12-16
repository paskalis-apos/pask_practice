#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n , x;
vector<int> heights;

bool valid(ll mid) {
    ll sum = 0;
    for(auto &x : heights) {
        sum += max(ll(0) , mid - x);
    }
    if(sum <= x) {
        return true;
    }
    else {
        return false;
    }
}

void solve() {
    cin >> n >> x;
    heights.assign(n, 0);
    for(auto &x : heights) {
        cin >> x;
    }
    ll l = 1;
    ll r = 1e11;

    while(l < r) {
        ll mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    ll answer = l;
    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}