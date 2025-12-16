#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9 + 10;
vector<vector<pair<ll,ll>>> adj;
vector<bool> visited;

void dijkstra(priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> &q, vector<ll> &minimum) {
    while(!q.empty()) {
        pair<int,int> cur = q.top();
        q.pop();
        if(visited[cur.second]) {
            continue;
        }
        visited[cur.second] = true;
        for(auto &x : adj[cur.second]) {
            if(minimum[x.first] > max(minimum[cur.second], x.second)) {
                minimum[x.first] = max(minimum[cur.second], x.second);
                q.push({minimum[x.first], x.first});
            }
        }
    }
}   

void solve() {
    ll n , m;
    cin >> n >> m;
    adj.assign(n , {});
    for(int i = 0;i < m;i++) {
        int a, b , w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b , w});
        adj[b].push_back({a , w});
    }
    vector<ll> minfrom1(n, INF);
    minfrom1[0] = 0;
    vector<ll> minfromn(n, INF);
    minfromn[n - 1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push({0, 0});
    visited.assign(n, false);
    dijkstra(q, minfrom1);
    q.push({0 , n - 1});
    visited.assign(n, false);
    dijkstra(q, minfromn);


    ll ans = 2 * INF;
    for(int i = 0;i < n;i++) {
        for(auto &x : adj[i]) {
            if(minfrom1[i] == 0 && minfromn[x.first] == 0) {
                ans = min(ans, 2 * x.second) ;
                continue;
            }
            ans = min(ans, max(minfrom1[i],minfromn[x.first]) + x.second);
        }
    }

    cout << ans << endl;

    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}