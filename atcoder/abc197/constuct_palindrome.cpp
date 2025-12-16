#include<bits/stdc++.h>
using namespace std;

struct ed{
    int a , b;
    char c;
};

map<pair<int,int>, vector<pair<int,int>>> adj;
map<pair<int,int>, bool> edgexist;

int main() { 
    int n , m;
    cin >> n >> m;
    vector<ed> edges(m);
    for(auto &x : edges) {
        cin >> x.a >> x.b >> x.c;
        edgexist[{x.a , x.b}] = edgexist[{x.b , x.a}] = true;
    }

    for(int i = 0;i < m ;i ++) {
        for(int j = i + 1; j < m; j++) {
            pair<int,int> a = {min(edges[i].a, edges[j].a), max(edges[i].a, edges[j].a)};
            pair<int,int> b = {min(edges[i].b, edges[j].b), max(edges[i].b, edges[j].b)};
            pair<int,int> a2 = {min(edges[i].a, edges[j].b), max(edges[i].a, edges[j].b)};
            pair<int,int> b2 = {min(edges[i].b, edges[j].a), max(edges[i].b, edges[j].a)};
            if(edges[i].c == edges[j].c){ 
                adj[a].push_back(b);
                adj[b].push_back(a);
                adj[a2].push_back(b2);
                adj[b2].push_back(a2);
            }
        }
    }
    map<pair<int,int>, int> dist;
    queue<pair<int,int>> q;
    q.push({1 , n});
    dist[{1 , n}] = 0;
    int ans = INT_MAX;
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first == cur.second) {
            ans = min(ans , dist[cur]);
        }
        else if(edgexist[{cur.first, cur.second}]) {
            ans = min(ans, dist[cur] + 1);
        }
        for(auto &x : adj[cur]) {
            if(dist[x] != 0 || (x.first == 1 && x.second == n)) {
                continue;
            }
            q.push(x);
            dist[x] = dist[cur] + 2;
        }
    }
    if(ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << endl;

}