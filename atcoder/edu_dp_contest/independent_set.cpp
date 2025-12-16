#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod ll(1e9 + 7);

int n;
vector<vector<int>> adj;
vector<ll>dp[2];
void dfs(int cur ,int par) {
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        dfs(x, cur);
        dp[0][cur] *= (dp[0][x] + dp[1][x]);
        dp[1][cur] *= dp[0][x];
        dp[0][cur] %= mod;
        dp[1][cur] %= mod;
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    dp[0].resize(n , 1);
    dp[1].resize(n, 1);

    for(int i = 0 ;i < n - 1; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0 , -1);

    ll answer = dp[0][0] + dp[1][0];
    answer %= mod;
    cout << answer << endl;
}