#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n , m;
vector<vector<pair<ll,ll>>> adj;
vector<bool> visited;
vector<ll> distances;

void dikstra() {
    priority_queue<pair<ll,ll>> q;
    distances[1] = 0;
    q.push({0 , 1});
    while(!q.empty()) {
        int a = q.top().second; 
        q.pop();
        if(visited[a] == true) {
            continue;
        }
        visited[a] = true;
        for(auto &x : adj[a]) {
            int b = x.first;
            int w = x.second;
            if(distances[a] + w < distances[b]) {
                distances[b] = distances[a] + w;
                q.push({-distances[b], b});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    distances.resize(n + 1, 2 * 1e16 );

    for(int i = 0; i < m ;i++) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].push_back({b , w});
    }   

    dikstra();

    for(int i = 1;i <= n ;i++) {
        cout << distances[i] <<" ";
    }
    cout << endl;

}