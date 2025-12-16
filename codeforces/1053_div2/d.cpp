#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

vector<ll> fact(2 * 1e5 + 10000);

ll exp(ll a , ll b) {
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
    return exp(a, MOD -2);
}

ll chose(ll a , ll b) {
    ll ans = fact[a] * modinv(fact[b]);
    ans %= MOD;
    ans *= modinv(fact[a - b]);
    ans %= MOD;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) {
        cin >> x;
    }
    vector<ll> dp(n + 2);
    dp[n + 1] = 1;
    ll emptypos = 0;
    ll used = 0;
    for(int i = n ;i > 0; i--) {
        dp[i] = dp[i + 1];
        if(i > n / 2 + n % 2) {
            if(a[i - 1] > 0) {
                dp[1] = 0;
                break;
            }
            continue;
        }
        ll options = n - (i - 1) * 2;
        options -= used;
        if(a[i - 1] > options) {
            dp[1] = 0;
            break;
        }
        dp[i] *= chose(options, a[i - 1]);
        dp[i] %= MOD;
        used += a[i - 1];      
    }
    if(used < n) {
        dp[1] = 0;
    }

    cout << dp[1] << endl;

    

}

int main() {

    fact[0] = 1;
    for(int i = 1;i <= 2 * 1e5 ; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    int t;
    cin >> t;
    for(int i = 0;i < t;i++) {
        solve();
    }
}