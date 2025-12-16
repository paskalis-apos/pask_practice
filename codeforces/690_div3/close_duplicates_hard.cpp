#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
vector<ll> fact(2 * 1e5 + 1);

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

ll modinv(ll a) {
    return exp(a , MOD -2);
}

ll chose(ll a ,ll b) {
    if(b > a){ 
        return 0;
    }
    ll ans = fact[a] * modinv(fact[b]);
    ans %= MOD;
    ans *= modinv(fact[a - b]);
    ans %= MOD;
    return ans;
}

void solve() {
    ll n , m ,k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    int r = n - 1;
    int l = n - 1;
    ll ans = 0;
    while(r >= 0){ 
        while(l >= 0 && v[r] - v[l] <= k) {
            l--;
        }
        l++;
        ans += chose(r - l,m - 1);
        ans %= MOD;
        r--;    
    }

    cout << ans << endl;
}

int main() {
    fact[0] = 1;
    for(int i = 1; i <= 2 * 1e5; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}