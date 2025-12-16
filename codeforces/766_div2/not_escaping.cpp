#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    ll y , x , h;
};

void solve() {
    ll n , m , k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    map<pair<ll,ll>, vector<edge>> adj;
    vector<vector<ll>> validrooms(n);
    for(ll i = 0; i < k ; i++) {
        ll a , b , c , d , h;
        cin >> a >> b >> c >> d >> h;
        a--;
        b--;
        c--;
        d--;
        adj[{a , b}].push_back({c , d , h});
        validrooms[a].push_back(b);
        validrooms[c].push_back(d);
    }
    validrooms[0].push_back(0);
    validrooms[n - 1].push_back(m - 1);
    for(auto &x : validrooms) {
        sort(x.begin(), x.end());
        vector<ll> newv;
        if(x.empty()) {
            continue;
        }
        newv.push_back(x[0]);
        for(int i = 1;i < x.size() ;i++) {
            if(x[i] != x[i - 1]) {
                newv.push_back(x[i]);
            }
        }
        x = newv;
    }
    map<pair<ll,ll>, ll> dist;  
    map<pair<ll,ll>, ll> visited;  
    dist[{0 , 0}] = 0;
    visited[{0 , 0}] = true;
    for(ll i = 0;i < n; i++) {
        if(!validrooms[i].empty() && !visited[{i , validrooms[i][0]}]) {
            dist[{i, validrooms[i][0]}] = 1e18;
            visited[{i , validrooms[i][0]}] = true; 
        }     
        for(int j = 1;j < validrooms[i].size(); j++) {
            ll testdist = dist[{i , validrooms[i][j - 1]}] + v[i] * (validrooms[i][j] - validrooms[i][j - 1]);
            if(!visited[{i , validrooms[i][j]}]) {
                dist[{i, validrooms[i][j]}] = 1e18;
                visited[{i , validrooms[i][j]}] = true;
            }
            dist[{i, validrooms[i][j]}] = min(dist[{i , validrooms[i][j]}], testdist);
        }
        for(int j = validrooms[i].size() - 2; j >= 0; j--) {
            ll testdist = dist[{i , validrooms[i][j + 1]}] + v[i] * (validrooms[i][j + 1] - validrooms[i][j]);
            if(!visited[{i , validrooms[i][j]}]) {
                dist[{i, validrooms[i][j]}] = 1e18;
                visited[{i , validrooms[i][j]}] = true;
            }
            dist[{i, validrooms[i][j]}] = min(dist[{i , validrooms[i][j]}], testdist);
        }

        for(int j = 0;j < validrooms[i].size(); j++) {
            for(auto &x : adj[{i , validrooms[i][j]}]) {
                if(!visited[{x.y, x.x}]) {
                    dist[{x.y, x.x}] = dist[{i , validrooms[i][j]}] - x.h;
                    visited[{x.y, x.x}] = true;
                }
                else {
                    dist[{x.y, x.x}] = min(dist[{x.y, x.x}], dist[{i , validrooms[i][j]}] - x.h);
                }
            }
        }
    }

    if(dist[{n - 1, m - 1}] > 1e16) {
        cout << "NO ESCAPE" << endl;
        return;
    }
    cout << dist[{n - 1, m - 1}] << endl;



}

int main (){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}