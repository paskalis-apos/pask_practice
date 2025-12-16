#include<bits/stdc++.h>
using namespace std;

int n , q;
vector<vector<pair<int,int>>> adj;
vector<bool> visited;
int videos;

void dfs(int k ,int cur) {
    visited[cur] = true;
    videos++;
    for(auto &x : adj[cur]) {
        if(visited[x.first] || x.second < k) {
            continue;
        }
        dfs(k , x.first);
    }
}


int main() {
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    cin >> n >> q;
    adj.resize(n);
    visited.resize(n);
    for(int i = 0 ;i < n - 1; i++) {
        int a , b, r;
        cin >> a >> b >> r;
        a--;
        b--;
        adj[a].push_back({b , r});
        adj[b].push_back({a , r});
    }



    for(int i = 0 ;i < q; i++) {
        visited.assign(n , false);
        videos = 0;
        int k , v;
        cin >> k >> v;
        v--;
        dfs(k , v);
        videos--;
        cout << videos << endl;
    }
}