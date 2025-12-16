#include<bits/stdc++.h>
using namespace std;

int n ,m;
int smallcircle = INT_MAX;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;

void bfs(int startnode) {
    queue<pair<int,int>> q;
    q.push({startnode, startnode});
    visited[startnode] = true;
    dist[startnode] = 0;
    while(!q.empty()) {
        int cur = q.front().first;
        int par = q.front().second;
        q.pop();
        visited[cur] = true;
        for(auto &x : adj[cur]) {
            if(visited[x]) {
                if(x != par) {
                    smallcircle = min(smallcircle, dist[x] + dist[cur] + 1);
                }
                continue;
            }
            visited[x] = true;
            dist[x] = dist[cur] + 1;
            q.push({x, cur});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);   
    visited.resize(n + 1); 
    dist.resize(n + 1);

    for(int i = 0 ;i < m ;i++) {
        int a , b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    for(int i = 1 ;i <= n; i++) {
        visited.assign(n + 1 , false);
        bfs(i);
    }

    if(smallcircle == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << smallcircle << endl;

}