#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp[2];

void dfs(int cur , int par) {
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        dfs(x , cur);
        dp[0][cur] += max(dp[0][x], dp[1][x]);
    }

    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        dp[1][cur] = max(dp[1][cur], dp[0][x] + 1 + dp[0][cur] - max(dp[0][x], dp[1][x]));
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    dp[0].resize(n, 0);
    dp[1].resize(n, 0 );
    for(int i = 0 ; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0 , -1);

    cout << max(dp[1][0], dp[0][0]) << endl;
}