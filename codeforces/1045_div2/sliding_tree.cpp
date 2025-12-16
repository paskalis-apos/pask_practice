#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int>p;
vector<int>dist;

void dfs(int cur, int par){
    p[cur] = par;
    for(auto &x : adj[cur]) {
        if(x == par){
            continue;
        }
        dist[x] = dist[cur] + 1;
        dfs(x, cur);
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n , {});
    dist.assign(n , 0);
    p.assign(n , -1);
    for(int i = 0;i < n- 1; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0 , -1);
    int maxind = 0, maxdist = 0;
    for(int i = 0; i < n; i++) {
        if(dist[i] > maxdist) {
            maxind = i;
            maxdist = dist[i];
        }
    }
    dist[maxind] = 0;   
    dfs(maxind, -1);
    maxind = 0;
    maxdist = 0;
    for(int i = 0;i < n;i++) {
        if(dist[i] > maxdist){ 
            maxind = i;
            maxdist = dist[i];
        }
    }
    if(maxdist == n-1) {
        cout << -1 << endl;
        return;
    }
    int cur = maxind;
    vector<bool> on_diameter(n , false);
    while(cur != -1) {
        on_diameter[cur] = true;
        cur = p[cur];
    }
    int a, b , c;
    for(int i = 0;i < n;i++) {
        for(auto &x : adj[i]) {
            if(on_diameter[i] && !on_diameter[x]) {
                a = p[i];
                b = i;
                c = x;
                break;
            }
        }
    }

    cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}