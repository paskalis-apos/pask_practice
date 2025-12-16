#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> visited;
vector<bool> cut;
int sizee;

void dfs(int cur, int prev) {
    visited[cur] = true;
    for(auto &x : adj[cur]) {
        if(x.first == prev || cut[x.second]) {
            continue;
        }
        if(visited[x.first]) {
            cut[x.second] = true;
            sizee--;
            continue;
        }
        dfs(x.first, cur);
    }
}

void solve() {
    int n;
    cin >> n;
    sizee = n;
    adj.assign(2 * n + 1, {});
    visited.assign(2 * n + 1, false);
    cut.assign(2  * n + 1, false);
    for(int i = 1; i <= n; i++) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back({b , i});
        adj[b].push_back({a , i});
    }

    for(int i = 1; i <= 2 * n ;i++) {
        if(!visited[i]) {
            dfs(i, -1);
        }
    }

    cout << sizee << endl;

    for(int i = 1;i <= n ;i++) {
        if(cut[i]) {
            continue;
        }
        cout << i << " ";
    }
    cout << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }

}