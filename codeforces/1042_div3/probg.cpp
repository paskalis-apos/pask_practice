#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
vector<ll> v;
ll ans ;
ll n , k;
vector<ll>pow2(33);
vector<ll> mult(33);

void check() {
    for(auto &x : v) {
        if(k == 0) {
            break;
        }
        else if(x > 30 || pow2[x - 1] > k) {
            ans *= x;
            k--;
            ans %= MOD;
            ll cur = x;
            v.clear();
            for(int i = 1; i <= 30 && i < cur;i ++) {
                v.push_back(i);
            }
            check();
            break;
        }
        else {
            k -= pow2[x - 1];
            ans *= mult[x];
            ans %= MOD;
        }
    }
}

void solve() {
    cin >> n >> k;
    ans = 1;
    v.assign(n , 0);
    for(auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    ll sum = 0;
    mult[1] = 1;
    
    check();
    
    cout << ans << endl;
    
}

int main() {
    int t;
    cin >> t;
    pow2[0] = 1;
    for(int i = 1; i <= 32; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    mult[1] = 1;
    for(int i = 2;i <= 32 ; i++) {
        mult[i] = i;
        for(int j = 1;j < i; j++) {
            mult[i] *= mult[j];
            mult[i] %= MOD;
        }
    }
    for(int i = 0; i < t; i++) {
        solve();
    }
}