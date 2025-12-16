#include<bits/stdc++.h>
using namespace std;

int b , e , p , n , m;
vector<vector<int>> adj(n + 1);
vector<bool> visited(n + 1);

void bfs(int startnode, vector<int> &dist) {
    queue<int> q;
    q.push(startnode);
    visited[startnode] = true;
    dist[startnode] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x : adj[cur]) {
            if(visited[x]) {
                continue;
            }
            dist[x] = dist[cur] + 1;
            visited[x] = true;
            q.push(x);
        }
    }
}

int main() {
    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    cin >> b >> e >> p >> n >> m;
    adj.reserve(n + 1);
    visited.resize(n + 1);
    for(int i = 0 ;i < m ; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }  

    vector<int>onedist(n + 1, -1);
    vector<int> twodist(n + 1, -1);
    vector<int> barndist(n + 1, -1);
    bfs(1 , onedist);
    visited.assign(n + 1, false);
    bfs(2, twodist);
    visited.assign(n + 1, false);
    bfs(n, barndist);

    int minenergy = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(onedist[i] == -1 || twodist[i] == -1) {
            continue;
        }
        int energyone = onedist[i] * b;
        int energytwo = twodist[i] * e;
        int energyboth = barndist[i] * p;
        int totalenergy = energyone + energytwo + energyboth;
        minenergy = min(minenergy, totalenergy);
    }

    cout << minenergy << endl;
}