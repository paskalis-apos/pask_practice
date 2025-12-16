#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int n , m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> circleid;
vector<bool> downedge;
vector<int> start;
vector<int> timeline;
vector<int> depth;
vector<int> circlecount;
vector<pair<int,int>> edges;
int befcircles = 0;
int id;
int curtime = 0;
int curdepth = 0;

struct segtree {
    int size;
    vector<pair<int,int>> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.resize(2 * size, {INT_MAX, -1});
    }
    void set(int i, pair<int,int> v, int x, int lx , int rx) {
        if(rx - lx == 1) {
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v , 2 * x + 1, lx , m);
        }
        else {
            set(i , v , 2 * x + 2, m , rx);
        }
        values[x] = min(values[2 * x + 1], values[2 * x + 2]);
    }
    void set(int i, pair<int,int> v) {
        set(i , v , 0 , 0 , size);
    }
    
    pair<int,int> lca(int l, int r, int x, int lx,int rx) {
        if(l >= rx || r <= lx) {
            return {INT_MAX, -1};
        }
        if(l >= lx && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        pair<int,int> s1 = lca(l , r , 2 * x + 1,lx , m);
        pair<int,int>s2 = lca(l , r , 2 * x + 2, m , rx);
        return min(s1, s2);
    }

    pair<int,int> lca(int l, int r) {
        return lca(l, r, 0, 0 , size);
    }
};

void dfs(int cur, int par) {
    visited[cur] = true;
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        if(visited[x]) {
            circleid[cur] = id++;
            downedge[x] = true;
            continue;
        }
        edges.push_back({x, cur});
        dfs(x, cur);
    }
    if(circleid[cur] == 0) {
        circleid[cur] = cur;
        for(auto &x : adj[cur]) {
            if(x == par) {
                continue;
            }
            if(circleid[x] != x && !downedge[cur]) {
                circleid[cur] = circleid[x];
            }
        }
    }
}

void euler_tour(int cur, int par) {
    depth[cur] = curdepth++;
    start[cur] = curtime;
    timeline.push_back(cur);
    befcircles += (cur >= n);
    circlecount[cur] = befcircles;
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        euler_tour(x, cur);
    }
    curdepth--;
    timeline.push_back(cur);
    befcircles -= (cur >= n);
}


int main() {    
    cin >> n >> m;
    id = n;
    adj.resize(n);
    visited.resize(n);
    circleid.resize(n);
    downedge.assign(n, false);

    for(int i = 0 ;i < m;i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);

    
    // for new adj
    adj.assign(2 * n , {});
    start.resize(2 * n);
    depth.resize(2 * n);
    depth.resize(2 * n);
    circlecount.resize(2 * n);

    for(auto &x : edges) {
        if(circleid[x.first] == circleid[x.second]) {
            continue;
        }
        adj[circleid[x.first]].push_back(circleid[x.second]);
        adj[circleid[x.second]].push_back(circleid[x.first]);
    }

    euler_tour(circleid[0], -1);
    segtree st;
    st.init(timeline.size());
    for(int i = 0; i < timeline.size() ;i++) {
        st.set(i, {depth[timeline[i]], timeline[i]});
    }

    int k;
    cin >> k;
    vector<ll> pow2(1e5 + 1);
    pow2[0] = 1;
    for(int i = 1; i <= 1e5; i++) {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= MOD;
    }
    for(int i = 0;i  < k; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        int curlca = st.lca(start[a], start[b] + 1).second;
        ll ans = pow2[circlecount[a]] * pow2[circlecount[b]] / pow2[circlecount[curlca]] / pow2[circlecount[curlca]];
        ans %= MOD;
        cout << ans << endl;
    }
}