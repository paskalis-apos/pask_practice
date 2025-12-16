#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
vector<vector<int>> adj;
vector<int> start;
vector<int> stop;

int counter = 0;

struct segtree {
    int size;
    vector<ll> values;

    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(size * 2, 0);
    } 
    void set(int i , int v, int x ,int lx ,int rx) {
        if(rx - lx == 1) {
            values[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < mid) {
            set(i , v , 2 * x + 1, lx , mid);
        }
        else {
            set(i , v , 2 * x + 2, mid , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void set(int i, int v) {
        set(i, v , 0 , 0, size);
    }

    ll sum(int l , int r, int x , int lx, int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        else if(lx >= l && rx <= r) {
            return values[x];
        }
        int mid = (lx + rx) / 2;
        ll s1 = sum(l , r , 2 * x + 1 ,lx , mid);
        ll s2 = sum(l , r , 2 * x + 2, mid , rx);
        return s1 + s2;
    }
    ll sum(int l ,int r) {
        return sum(l , r , 0 , 0 , size);
    }
};

void euler_tour(int cur , int par) {
    start[cur] = counter;
    counter++;
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        euler_tour(x, cur);
    }
    stop[cur] = counter;
}


int main() {
    cin >> n >> q;
    adj.resize(n);
    start.resize(n);
    stop.resize(n);

    vector<int> nodes(n);
    for(auto &x : nodes) {
        cin >> x;
    }
    
    for(int i = 0 ;i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    euler_tour(0 , -1);

    segtree st;

    st.init(n + 1);
    for(int i = 0 ;i < n ;i++) {
        st.set(start[i] , nodes[i]);
    }
    for(int i = 0 ;i < q; i++) {
        int op;
        cin >> op;
        if(op == 1){ 
            int i , v;
            cin >> i >> v;
            i--;
            st.set(start[i], v);
        }
        else {
            int s;
            cin >> s;
            s--;
            int l = start[s];
            int r = stop[s];
            cout << st.sum(l , r) << endl;
        }
    }

}
