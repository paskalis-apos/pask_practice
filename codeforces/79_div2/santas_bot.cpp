#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD ll(998244353)

ll exp(ll num ,ll m) {
    if(m == 0) {
        return 1;
    }
    ll answer = exp(num , m / 2);
    answer *= answer;
    answer %= MOD;
    if(m % 2 == 1) {
        answer *= num;
        answer %= MOD;
    }
    return answer % MOD;
}

ll modinv(ll num) {
    return exp(num, MOD - 2);
}

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> presents(1e6 + 1);
    vector<ll> prnum(n);
    for(int i = 0 ;i < n; i++) {
        ll k;
        cin >> k;
        prnum[i] = k;
        for(int j = 0;j < k; j++){
            ll temp;
            cin >> temp;
            presents[temp].push_back(i);
        }
    }

    ll chance = 0;

    for(int i = 1; i <= 1e6; i++) {
        ll curchance = 0;
        for(auto &x : presents[i]) {
            curchance += modinv(n) % MOD * modinv(prnum[x]) % MOD;
            curchance %= MOD;
        }
        chance += curchance % MOD * presents[i].size() % MOD * modinv(n) %MOD;
        chance %= MOD;
    }


    cout << chance << endl;
}