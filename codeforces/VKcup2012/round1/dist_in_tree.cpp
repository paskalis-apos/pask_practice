#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n , k;
vector<vector<ll>> adj;
vector<vector<ll>> dp;
ll ans = 0;

void dfs(ll cur, ll par) {
    dp[cur][0] = 1;
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        dfs(x, cur);
        for(int i = 0 ;i < k; i++) {
            ans += dp[cur][i] * dp[x][k - i - 1];
        }
        for(int i = 1;i <= k ;i++) {
            dp[cur][i] += dp[x][i - 1];
        }
    }

}

int main() {    
    cin >> n >> k;
    adj.resize(n);
    dp.resize(n, vector<ll>(k + 1));
    for(int i = 0 ;i < n -1 ;i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);

    cout << ans << endl;
}