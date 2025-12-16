#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct pos{
    ll dist, node;
    bool used;

};

bool operator<(pos a, pos b) {
    return a.dist > b.dist;
}

ll n , m;
vector<vector<pair<ll,ll>>> adj;
vector<ll> distances[2];

void dijkstra() {
    priority_queue<pos> q;
    q.push({0 , 1 , false});
    while(!q.empty()) {
        ll node = q.top().node;
        ll dist = q.top().dist;
        bool used = q.top().used;
        q.pop();
        if(distances[used][node] != dist) {
            continue;
        }
        for(auto &x : adj[node]) {
            if(!used) {
                if(distances[true][x.first] > dist + x.second / 2) {
                    distances[true][x.first] = dist + x.second / 2;
                    q.push({distances[true][x.first], x.first , true});
                }
                if(distances[false][x.first] > dist + x.second) {
                    distances[false][x.first] = dist + x.second;
                    q.push({distances[false][x.first], x.first, false});
                }
            }
            if(distances[true][x.first] > dist + x.second) {
                distances[true][x.first] = dist + x.second;
                q.push({distances[true][x.first], x.first , true});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    distances[0].resize(n + 1, 1e16);
    distances[1].resize(n + 1, 1e16);
    distances[0][1] = 0;
    distances[1][1] = 0;

    for(int i = 0 ;i < m; i++) {
        int a, b , c;
        cin >> a >> b >> c;
        adj[a].push_back({b , c});
    }

    dijkstra();
    cout << distances[1][n];


}