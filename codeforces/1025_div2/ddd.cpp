#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e10;

vector<vector<ll>> adj;

void solve() {
    ll n, m , l;
    cin >> n >> m >> l;
    vector<vector<ll>> adj(n);
    vector<ll> ms(l);
    ll mineven = INF;
    ll minodd = INF;
    ll totalsum = 0;
    for(auto &x : ms) {
        cin >>x ;
        totalsum += x;
        if(x % 2 == 0) {
            mineven = min(mineven, x);
        }
        else{
            minodd = min(minodd, x);
        }
    }
    for(int i = 0;i< m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[0][0] = 0;
    queue<pair<ll,ll>> q;
    q.push({0 , 0});
    while(!q.empty()) {
        pair<ll,ll> cur = q.front();
        q.pop();
        int curdist = dist[cur.first][cur.second] + 1;
        for(auto &x : adj[cur.first]) {
            if(dist[x][curdist % 2] != INF) {
                continue;
            }
            dist[x][curdist % 2] = curdist;
            q.push({x , curdist % 2});
        }
    }

    ll evensum = totalsum;
    ll oddsum = totalsum;
    if(totalsum % 2 == 0) {
        oddsum -= minodd;
    }
    else {
        evensum -= minodd;
    }

    for(int i = 0;i< n;i++) {
        if(dist[i][0] <= evensum || dist[i][1] <= oddsum) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
    
}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t; i++) {
        solve();
    }
}