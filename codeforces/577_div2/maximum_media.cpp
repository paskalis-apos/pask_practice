#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll>v;
ll k , n;

bool check(ll x) {
    ll rec = 0;
    for(int index = n/2; index < n; index++) {
        if(v[index] < x) {
            rec += x - v[index];
        }
        else {
            break;
        }
    }

    return (rec <= k);
}



int main() {
    cin >> n >> k;
    v.resize(n);
    for(auto &x : v) {
        cin >> x;
    }
    sort(v.begin(),v.end());

    ll l = 0, r = 2e9;
    ll ans;
    while(l <= r) {
        ll mid =(l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

}