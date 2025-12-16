#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> p;
vector<int> sz;
vector<bool> magical;

int get(int a) {
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}

int unite(int a , int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return 0;
    }
    if(sz[a] < sz[b]) {
        swap(a , b);
    }
    int ans;
    if(!magical[a] && magical[b]) {
        ans = sz[a];
    }
    else if(!magical[b] && magical[a]){
        ans = sz[b];
    }
    else {
        ans = 0;
    }
    magical[a] = magical[a] || magical[b];
    sz[a] += sz[b];
    p[b] = a;
    return ans;
    
}


int main( ){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m, c;
    cin >> n >> m >> c;
    magical.resize(n);

    vector<int> S(c);
    for(auto &x : S) {
        cin >> x;
        x--;
        magical[x] = true;
    }
    adj.resize(n);
    p.resize(n);
    sz.resize(n);

    for(int i = 0 ;i < m; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> stopped(n);
    int q;
    cin >> q;
    vector<int> queries(q);
    for(int i = 0;i < q; i++) {
        cin >> queries[i];
        queries[i]--;
        stopped[queries[i]] = true;
    }

    for(int i = 0;i < n;i++) {
        sz[i] = 1;
        p[i] = i;
    }

    for(int i = 0;i < n; i++) {
        for(auto &x : adj[i]) {
            if(stopped[i] || stopped[x]) {
                continue;
            }
            unite(i , x);
        }
    }

    vector<int> ans(q);
    for(int i = q - 1;i >= 0; i--) {
        int temp = 0;
        if(magical[queries[i]]) {
            temp++;
        }
        stopped[queries[i]] = false;
        for(auto &x : adj[queries[i]]) {
            if(stopped[x]) {
                continue;
            }
            temp += unite(queries[i], x);
        }
        ans[i] = temp;
    }

    for(auto &x : ans) {
        cout << x << endl;
    }



}