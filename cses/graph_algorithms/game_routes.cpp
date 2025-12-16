#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod int(1e9 + 7)

int n , m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tsort;


void dfs(int ind) {
    visited[ind] = true;
    for(auto &x : adj[ind]) {
        if(visited[x]) {
            continue;
        }
        dfs(x);
    }
    tsort.push_back(ind);
}

void top_sort() {
    dfs(1);
    reverse(tsort.begin(), tsort.end());
}



int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);

    for(int i = 0 ;i < m; i++) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    top_sort();

    vector<ll> dp(n + 1, 0);
    dp[1] =1;

    for(auto &x : tsort) {
        for(auto &y : adj[x]) {
            dp[y] += dp[x];
            dp[y] %= mod;
        }
    }

    cout << dp[n] << endl;

}