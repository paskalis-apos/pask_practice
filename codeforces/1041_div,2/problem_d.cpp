#include<bits/stdc++.h>
using namespace std;
#define MOD ll(1e9 + 7);
using ll = long long;
vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> fact(2 * 1e5 + 1);
ll possibilities;

bool dfs(int cur, int par) {
    int bad = 0;
    visited[cur] = true;
    for(auto &x : adj[cur]) {
        if(adj[x].size() > 1) {
            bad++;
        }
        if(x == par) {
            continue;
        }
        if(visited[x]) {
            return false;
        }
        if(!dfs(x, cur)) {
            return false;
        }
    }
    if(bad > 2) {
        return false;
    }
    if(bad > 0 && par == -1) {
        possibilities *= 2;
        possibilities %= MOD;
    }
    int cursize = adj[cur].size() - bad;
    possibilities *= fact[cursize];
    possibilities %= MOD;
    return true;
}

void solve() {
    int n ,m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    possibilities = 2;


    for(int i = 0;i  < m ;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <=n ;i++) {
        if(adj[i].size() > 1) {
            possibilities %= MOD;
            if(!dfs(i , -1)) {
                cout << 0 << endl;
            }
            else {
                cout << possibilities << endl;
            }
            return;
        }
    }
    cout << 2 << endl;
}

int main() {
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i = 1;i <= 2 * 1e5 ;i++) {
        fact[i] = (fact[i -1] * i) %MOD
    }
    for(int i = 0 ; i < t; i++) {
        solve();
    }
}