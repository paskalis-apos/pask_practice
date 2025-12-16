#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
vector<ll> fact(1e5 + 1);


ll exp(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    ll ans = exp(a , b / 2);
    ans *= ans;
    ans %= MOD;
    if(b % 2 == 1) {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

ll modinv(ll a){
    return exp(a , MOD - 2);
}

ll choose(ll a, ll b) {
    if(b > a) {
        return 0;
    }
    ll ans = fact[a] * modinv(fact[b]);
    ans %= MOD;
    ans *= modinv(fact[a - b]);
    return ans % MOD;
}

void solve() {
    int n;
    cin >> n;
    cout << 0 << " ";
    for(int i = 1; i < n ;i++) {
        ll cur = choose(n - i - 2, i - 1);
        if(cur == 0){
            cout << 0 << " ";
            continue;
        }
        cur *= fact[2 * i];
        cur %= MOD;
        cur*= fact[n - 2 * i + 1];
        cur %= MOD;
        cout << cur << " "; 
    }
    cout << endl;

}

int main() {
    fact[0] = 1;
    for(int i = 1;i <= 1e5 ; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}