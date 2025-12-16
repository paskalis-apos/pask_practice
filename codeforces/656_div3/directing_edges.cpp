#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> nodir;
vector<bool> visited;
vector<bool> in_path;
vector<int> topsort;

bool dfs(int cur){ 
    visited[cur] = in_path[cur] = true;
    for(auto &x : adj[cur]) {
        if(in_path[x]) {
            in_path[cur] = false;
            return false;
        }
        if(visited[x]) {
            continue;
        }
        if(!dfs(x)) {
            in_path[cur] = false;
            return false;
        }
    }

    in_path[cur] = false;
    topsort.push_back(cur);
    return true;
}

void solve() {
    int n , m;
    cin >> n >> m;
    adj.assign(n,{});
    visited.assign(n, false);
    in_path.assign(n, false);
    topsort.clear();
    nodir.clear();

    for(int i = 0;i < m; i++) {
        int t , a , b;
        cin >> t >> a >> b;
        a--;
        b--;
        if(t == 0){ 
            nodir.push_back({a , b});
        }
        else {
            adj[a].push_back(b);
        }
    }

    for(int i =0 ;i < n ;i++) {
        if(visited[i]) {
            continue;
        }
        if(!dfs(i)) {
            cout << "NO" << endl;
            return;
        }
    }
    reverse(topsort.begin(), topsort.end());
    vector<int> tind(n);
    for(int i = 0; i < topsort.size(); i++){ 
        tind[topsort[i]] = i;
    }

    for(auto &x : nodir) {
        if(tind[x.first] > tind[x.second]) {
            swap(x.first, x.second);
        }
        adj[x.first].push_back(x.second);
    }   
    cout << "YES" << endl;
    for(int i = 0;i < n; i++) {
        for(auto &x : adj[i]){ 
            cout << i + 1 << " " << x + 1 << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}