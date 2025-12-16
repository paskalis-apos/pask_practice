#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using dd = double;

struct pp {
    ll a, b , c;
    ll flow;

    bool operator<(pp x) {
        return flow > x.flow;
    }
};

ll n , m;
vector<vector<pair<ll,ll>>> adj;
vector<ll> cost;

void dijkstra() {
    priority_queue<pair<ll,ll>> q;
    cost.assign(n + 1, 1e14);
    cost[1] = 0;
    q.push({0 , 1});
    while(!q.empty()) {
        ll curnode = q.top().second;
        ll curcost = -q.top().first;
        q.pop();
        if(curcost != cost[curnode]) {
            continue;
        }
        for(auto &x : adj[curnode]) {
            if(cost[x.first] > curcost + x.second) {
                cost[x.first] = curcost + x.second;
                q.push({-cost[x.first], x.first});
            }
        }
    }
}

int main() {
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);
    cin >> n >> m;
    adj.resize(n + 1);
    vector<pp> pipes;
    for(int i = 0 ;i < m ;i++) {
        pp temp;
        cin >> temp.a >> temp.b >> temp.c >> temp.flow;
        pipes.push_back(temp);
    }
    sort(pipes.begin(), pipes.end());
    dd minflow;
    dd answer = 0;

    for(int i = 0 ;i < m; i++) {
        int a = pipes[i].a;
        int b = pipes[i].b;
        int c = pipes[i].c;
        minflow = pipes[i].flow;
        adj[a].push_back({b , c});
        adj[b].push_back({a, c});
        dijkstra();
        if(cost[n] == 1e14) {
            continue;
        }
        answer = max(answer , dd(minflow / cost[n]) * 1e6);
    }
    int output = int(answer);
    cout << output << endl;

}