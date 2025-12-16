#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll modinv(ll i , ll MOD) {
    return 1;
}

int main() {
    ll n , MOD;
    cin >> n >> MOD;

    vector<ll> fact(n + 1);
    fact[0] =1;
    for(int i = 1; i <= n;i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    ll ans = fact[n];
    for(ll i = 1;i <= n; i++) {
        if(i % 2 == 1) {
            ans -= fact[n] * modinv(i , MOD);
        }
    }
}