#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
vector<ll>fact(2e6 + 1);

ll exp(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    ll ans = exp(a , b/2);
    ans *= ans;
    ans %= MOD;
    if(b % 2 == 1) {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

ll modinv(ll a) {
    return exp(a, MOD - 2);
}

ll choose(ll a, ll b) {
    if(b > a) {
        return 0;
    }
    ll ans = fact[a] * modinv(fact[b]);
    ans %= MOD;
    ans *= modinv(fact[a - b]);
    ans %= MOD;
    return ans;
}

int main() {
    ll n;
    cin >> n;
    fact[0] = 1;
    for(int i =1 ;i <= 2 * 1e6; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    ll states = 1;
    ll curstates = 1;
    for(int i = 0; i < 2 * n;i++) {
        ll still = 2 *choose(i , n);
        curstates *= 2;
        curstates %= MOD;
        curstates -= still;
        states += curstates;
        states %= MOD;
    }
    if(states < 0) {
        states += MOD;
    }
    cout << states << endl;

}