#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> per(n);
    for(auto &x : per) {
        cin >> x;
    }
    int l = 0;
    int r= n -1;
    string ans;
    bool up = true;
    while(l < r) {
        if(up) {
            if(per[l] < per[r]) {
                ans += "RL";
            }
            else {
                ans += "LR";
            }
            up = false;
        }
        else {
            if(per[r] < per[l]) {
                ans += "RL";
            }
            else {
                ans += "LR";
            }
            up = true;
        }
        r--;
        l++;
    }
    if(r == l) {
        ans += 'R';
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i =0 ;i< t ;i++) {
        solve();
    }
}