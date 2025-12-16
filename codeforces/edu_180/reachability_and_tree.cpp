#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> inedge, outedge;
vector<pair<int,int>> ans;
int goodind = -1;

void dfs(int cur, int par) {
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        if(inedge[cur] ) {
            outedge[x] = true;
            if(cur != goodind && x != goodind) {
                ans.push_back({x , cur});
            }
        }
        else {
            if(!outedge[x]) {
                inedge[x] = true;
            }
            if(cur != goodind && x != goodind) {
                ans.push_back({cur , x});
            }
        }

        dfs(x , cur);
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n, {});
    inedge.assign(n, false);
    outedge.assign(n, false);
    goodind = -1;
    ans.clear();
    for(int i = 0 ;i < n - 1;i ++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   
    for(int i = 0;i < n; i++) {
        if(adj[i].size() == 2) {
            goodind = i;
            break;
        }
    }
    if(goodind == -1) {
        cout << "NO" << endl;
        return;
    }
    inedge[adj[goodind][0]] = true;
    outedge[adj[goodind][1]] = true;
    dfs(adj[goodind][0], -1);

    cout << "YES" << endl;
    ans.push_back({goodind, adj[goodind][0]});
    ans.push_back({adj[goodind][1], goodind});
    for(auto &x : ans) {
        cout << x.first + 1<< " " << x.second + 1<< endl;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}