#include<bits/stdc++.h>
using namespace std;

int n ,m, k;
vector<vector<pair<int,int>>> adj;
vector<bool>visited;

vector<int> dijkstra(priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q) {
    visited.assign(n, false);
    vector<int> dist(n, INT_MAX);
    vector<pair<int,int>> v;
    while(!q.empty()) {
        v.push_back(q.top());
        dist[q.top().second] = q.top().first;
        q.pop();
    }
    for(auto &x : v) {
        q.push(x);
    }

    while(!q.empty()) {
        int cur = q.top().second;
        q.pop();
        if(visited[cur]) {
            continue;
        }
        visited[cur] = true;
        for(auto &x : adj[cur]) {
            if(dist[cur] + x.second < dist[x.first]) {
                dist[x.first] = dist[cur] + x.second;
                q.push({dist[x.first], x.first});
            }
        }
    }
    return dist;
}

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out","w", stdout);
    cin >> n >> m >> k;
    adj.resize(n);
    for(int i = 0;i < m ;i++) {
        int a , b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b , w});
        adj[b].push_back({a , w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, n - 1});
    vector<int> novisdist  = dijkstra(q);
    q.pop();

    for(int i = 0;i < k ;i++) {
        int ind , num;
        cin >> ind >> num;
        ind--;
        int curdist =  novisdist[ind] - num;
        q.push({curdist, ind});
    }
    vector<int> yesvisdist = dijkstra(q);
    for(int i = 0;i < n - 1;i++) {
        if(yesvisdist[i] <= novisdist[i]){ 
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}