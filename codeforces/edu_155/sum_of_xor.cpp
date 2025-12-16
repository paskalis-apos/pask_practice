#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    
    ll curpow = 1;
    ll ans = 0;
    
    for(int i = 0 ;i < 30; i++) {
        ll oddseq = 0;
        ll evenseq = 0;
        ll oddlength = 0;
        ll evenlength = 0;
        bool reverse = false;
        for(int j = 0;j < n ;j++) {
            ll cur = ((1 << i) & v[j]);
            evenlength += evenseq;
            oddlength += oddseq;
            evenlength %= MOD;
            oddlength %= MOD;
            if(cur > 0) {
                if(reverse) {
                    oddseq++;
                    oddlength++;
                    ans += oddlength * curpow;
                    reverse = false;
            
                }
                else {
                    evenseq++;
                    evenlength++;
                    ans += evenlength * curpow;
                    reverse = true;
                }
            }
            else {
                if(reverse) {
                    ans += evenlength * curpow;
                    oddseq++;
                    oddlength++;
                }
                else {
                    ans += oddlength * curpow;
                    evenseq++;
                    evenlength++;
                }
            }
            ans %= MOD;

        }
        curpow *= 2;
    }

    cout << ans << endl;
}