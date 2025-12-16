#include<bits/stdc++.h>
using namespace std;
int n , k;
vector<vector<int>> adj;
vector<int> bdist, fdist;
vector<bool> visited;
int farmernum = 0;

void bfs(queue<int> q, vector<int> &dist){
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x : adj[cur]) {
            if(dist[x] == -1) {
                dist[x] = dist[cur] + 1;
                q.push(x);
            }
        }
    } 
}

void dfs(int cur, int prev) {
    visited[cur] = true;
    if(bdist[cur] >= fdist[cur]) {
        farmernum++;
        return;
    }
    for(auto &x : adj[cur]) {
        if(!visited[x]) {
            dfs(x , cur);
        }
    }
}


int main() {
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);  
    cin >> n >> k;
    visited.resize(n);
    adj.resize(n);
    vector<int> besdist(n, -1);
    vector<int> farmdist(n, -1);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> besnode;
    besnode.push(k - 1);
    besdist[k - 1] = 0;
    bfs(besnode, besdist);
    
    queue<int> farmnodes;
    for(int i = 0 ;i < n ;i++) {
        if(adj[i].size() == 1) {
            farmnodes.push(i);
            farmdist[i] = 0;
        }
    }
    bfs(farmnodes, farmdist);
    bdist = besdist;
    fdist = farmdist;

    dfs(k - 1, -1);

    cout << farmernum << endl;






}