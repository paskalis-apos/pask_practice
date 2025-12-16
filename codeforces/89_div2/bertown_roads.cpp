#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
vector<pair<int,int>> ans;
vector<vector<int>> adj;
vector<bool> visited;
map<pair<int,int> , bool> nodevis;

void dfs(int cur, int par) {
    visited[cur] = true;
    for(auto &x : adj[cur]) {
        if(x == par || nodevis[{cur, x}]) {
            continue;
        }
        if(visited[x]) {
            dp[x]--;
            dp[cur]++;
            ans.push_back({cur, x});
            nodevis[{x, cur}] = true;
            continue;
        }
        ans.push_back({cur, x});
        nodevis[{x, cur}] = true;
        dfs(x, cur);
        dp[cur] += dp[x];
    }
}

int main() {
    int n , m;
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    dp.resize(n);
    for(int i = 0 ;i < m; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    for(int i = 1;i < n ;i++) {
        if(dp[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(auto &x : ans) {
        cout << x.first + 1<< " " << x.second + 1<< endl;
    }
}