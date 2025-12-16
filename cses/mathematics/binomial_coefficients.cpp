#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll exp(ll a , ll b) {
    if(b == 0) {
        return 1;
    }
    ll ans = exp(a , b/ 2);
    ans *= ans;
    ans %= MOD;
    if(b % 2 == 1) {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

ll modinv(ll a) {
    return exp(a , MOD - 2);
}


int main() {
    int n;
    cin >> n;
    vector<ll> fact(1e6 + 1);
    fact[0] = 1;
    for(int i =1 ;i <= 1e6; i++) {
        fact[i] = (fact[i -1] * i) % MOD;
    }
    for(int i = 0; i < n; i++) {
        ll a , b;
        cin >> a >> b;
        ll ans = fact[a] * modinv(fact[b]) %MOD;
        ans *= modinv(fact[a - b]);
        ans %= MOD; 
        cout << ans << endl;
    }
}
