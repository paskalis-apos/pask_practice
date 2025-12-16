#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n , k;
vector<ll> v;

bool valid(ll num) {
    ll l = 0;
    ll r = 0;
    vector<ll>pref(n + 1);

    while(r < n) {
        ll cur = v[r];
        pref[r + 1] = pref[r];
        if(cur >= num) {
            pref[r + 1] += 1;
        }
        else {
            pref[r + 1] -= 1;
        }
        if(r >= k - 1) {
            if(pref[r + 1- k] - pref[l] < 0) {
                l = r + 1 - k;
            }
            if(pref[r + 1] - pref[l] > 0) {
                return true;
            }  
        }
        r++;
    }

    return false;
}

int main() {
    cin >> n >> k;
    v.resize(n);
    for(auto &x :v) {
        cin >> x;
    }

    ll l = 1 , r  = 2e5;

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
