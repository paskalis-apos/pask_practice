#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll>v;

ll check(ll j) {
    vector<ll> temp = v;
    ll ans = 0;
    while(j >= 0) {
        ll ind = 0;
        ll diff = 1e10;
        for(ll i = 0;i < temp.size(); i++) {
            temp[i] %= 1 << (j + 1);
            if((temp[i] & (1 << j)) > 0) {
                ind = i;
                diff = 0;
                break;
            }
            if((1 << j) - temp[i] < diff) {
                diff = (1 << j) - temp[i];
                ind = i;
            }
        }
        if(temp[ind] < (1 << j)) {
            temp[ind] = 0;
        }
        ans += diff;
        j--;
    }
    return ans;

}

void solve() {
    int n , q;
    cin >> n >> q;
    v.assign(n, 0);
    for(auto &x : v) {
        cin >> x;
    }
    vector<ll> startones;
    vector<ll> need(31);
    for(ll i = 0;i <= 30;i ++) {
        need[i] = check(i);
        for(auto &x : v) {
            if((x & (1 << i)) > 0) {
                startones.push_back(i);
                break;
            }
        }
    }

        for(ll i = 0;i < q; i++) {
            ll b;
            cin >> b;
            ll cur = upper_bound(need.begin(), need.end(), b) - need.begin();
            cur--;
            cur +=  startones.end() - upper_bound(startones.begin(), startones.end(), cur );
            ll ans = cur + 1;
            cout << ans << endl;
    }
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}