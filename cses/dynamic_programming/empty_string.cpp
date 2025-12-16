#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
vector<ll> fact(501);
vector<vector<ll>> CHOSE(501, vector<ll> (501));

ll exp(ll a , ll b) {
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
    return exp(a , MOD - 2);
}

ll chose(ll a , ll b) {
    ll ans = fact[a] * modinv(fact[b]);
    ans %= MOD;
    ans *= modinv(fact[a - b]);
    ans %= MOD;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1;i <= 500; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    for(int i = 0;i <= 500;i++) {
        for(int j = 0;j <= i;j++) {
            CHOSE[i][j] = chose(i , j);
        }
    }
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> occs(1000);
    for(int i= 0; i < n;i++){ 
        occs[s[i]].push_back(i);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for(int i = 1;i <= n ;i++) {
        dp[i][i -1] = 1;
    }

    for(int d = 1; d < n ;d++) {
        for(int i = 0;i < n - d;i++) {
            for(auto &x : occs[s[i]])  {
                if(i < x && x <= i + d) {
                    ll ans = dp[i + 1][x - 1] * dp[x + 1][d + i];
                    ans %= MOD;
                    ans *= CHOSE[(d + 1) / 2][(x - i + 1) / 2];
                    ans %= MOD;
                    dp[i][i + d] += ans;
                    dp[i][i + d] %= MOD;
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}