#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n , k;
    cin >> n >> k;
    vector<ll> v(n);
    vector<ll>  occs(n + 1);
    for(auto &x : v) {
        cin >> x;
        occs[x]++;
    }
    ll mex;
    for(int i = 0;i <= n ;i++) {
        if(occs[i] == 0) {
            mex = i;
            break;
        }
    }
    if(k > 1) {
        vector<ll> newoccs (n + 1);
        for(auto &x : v) {
            if(occs[x] > 1 || x > mex) {
                x = mex;
            }
            newoccs[x]++;
        }
        occs = newoccs;
        for(ll i = 0;i <= n ;i++) {
            if(occs[i] == 0) {
                mex = i;
                break;
            }
        }
        k--;
        if(mex == n) {
            cout << n * (n - 1) / 2 << endl;
            return;
        }
        ll bigger = 0;
        for(auto &x : v){
            if(x > mex){
                bigger++;
            }
        }
        if(bigger == 0) {
            mex--;
            k++;
            for(auto &x : v){
                if(x >= mex){
                    bigger++;
                }
            }
        }
        ll still = mex * (mex - 1) / 2;
        if(k % 2 == 1) {
            still += mex * bigger;
        }
        else {
            still += (mex + 1) * bigger;
        }
        cout << still << endl;
        return;

    }
    ll ans = 0;
    for(auto &x : v) {
        if(occs[x] > 1 || x > mex) {
            ans += mex;
        }
        else {
            ans += x;
        }
    }
    cout << ans << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i< t; i++) {
        solve();
    }
}