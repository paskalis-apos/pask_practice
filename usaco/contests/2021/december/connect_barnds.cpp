#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n , m;
ll num;
vector<vector<ll>> adj;
vector<ll> visited;
vector<ll> onevis;
bool first, last;

int find_min_dist(ll ind, vector<ll> &v, ll &startpos) {
    ll min_dist = 1e10;  
    while(startpos < v.size() ) {
        ll tempdist = abs(v[startpos] - ind);
        if(tempdist > min_dist) {
            break;
        }
        min_dist = tempdist;
        startpos++;
    }
    startpos--;
    return min_dist;
}   

void dfs(int index) {
    if(visited[index] != 0) {
        return;
    }
    visited[index] = num;
    onevis.push_back(index);
    if(index == 0) {
        first = true;
    }
    else if(index == n - 1) {
        last = true;
    }

    for(auto &x : adj[index]) {
        if(!visited[x]) {
            dfs(x);
        }
    }

}

void solve() {
    cin >> n >> m;
    adj.assign(n, {});
    visited.assign(n , false);
    for(int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    num = 1;
    vector<vector<ll>> span;
    vector<ll> left;
    vector<ll> right;


    for(int i = 0 ;i < n ;i++) {
        first = false;
        last = false;
        if(visited[i] != 0) {
            continue;
        }
        onevis.clear();
        dfs(i);
        sort(onevis.begin(), onevis.end());
        span.push_back(onevis);
        if(first) {
            left = onevis;
        }
        if(last) {
            right = onevis;
        }
        num++;
    }
    ll min_cost = 1e10;
    ll startposl = 0;
    ll startposr = 0;
    vector<ll>toright(num, 1e10);
    vector<ll>toleft(num, 1e10);
    for(int i = 0 ;i < n;i++) {
        ll distleft = find_min_dist(i , left, startposl);
        ll distright = find_min_dist(i, right, startposr);
        toleft[visited[i]] = min(toleft[visited[i]], distleft * distleft);
        toright[visited[i]] = min(toright[visited[i]], distright * distright);

    }

    for(int i = 1 ;i < num ;i++) {
        min_cost = min(min_cost, toleft[i] + toright[i]);
    }

    cout << min_cost << endl;

}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}