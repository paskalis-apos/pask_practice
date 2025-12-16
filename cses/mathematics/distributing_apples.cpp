#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;


ll exp(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    ll ans = exp(a , b / 2);
    ans *= ans;
    ans %= MOD;
    if(b % 2 == 1){
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

ll modinv(ll a) {
    return exp(a, MOD -2);
}

int main() {
    ll n , m;
    cin >> n >> m;
    vector<ll> fact(2 * 1e6 + 1);
    fact[0] =1;
    for(int i = 1 ;i <= 2 * 1e6; i++) {
        fact[i] =fact[i -1] * i;
        fact[i] %= MOD;
    }
    swap(n , m);
    ll ans = fact[n + m - 1] * modinv(fact[m - 1]);
    ans %= MOD;
    ans *= modinv(fact[n]);
    ans %= MOD;

    cout << ans << endl;

}