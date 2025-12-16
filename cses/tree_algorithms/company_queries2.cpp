#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> timeline;
vector<int> depth;
vector<vector<int>> adj;
vector<int> start;
int curdepth = 1;
int curtime = 0;

struct segtree {
    int size;
    vector<pair<int,int>> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.resize(size * 2 , {INT_MAX, -1});
    }
    void set(int i , pair<int,int> v, int x ,int  lx ,int rx) {
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
    void set(int i , pair<int,int> v) {
        set(i , v , 0 , 0, size);
    }

    pair<int,int> calc(int l , int r , int x , int lx , int rx) {
        if(rx <= l || lx >= r) {
            return {INT_MAX, -1};
        }
        if(lx >= l && rx <= r){ 
            return values[x];
        }
        int m = (lx + rx) / 2;
        pair<int,int> s1 = calc(l , r , 2 * x + 1, lx , m);
        pair<int,int> s2 = calc(l , r , 2 * x + 2, m , rx);
        return min(s1 ,s2); 
    }
    pair<int,int> calc(int l , int r) {
        return calc(l , r , 0 , 0, size);
    }
};

void euler_tour(int cur, int par) {
    depth[cur] = curdepth++;
    start[cur] = curtime;
    timeline[curtime++] = cur;
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        euler_tour(x, cur);
        timeline[curtime++] = cur;
    }
    curdepth--;
}

int main(){
    int n , q;
    cin >> n >> q;
    timeline.resize(2 * n);
    depth.resize(n + 1);
    adj.resize(n + 1);
    start.resize(n + 1);
    for(int i = 2;i <= n;i++) {
        int a;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    
    euler_tour(1 , -1);
    segtree st;
    st.init(2 * n - 1);
    for(int i = 0 ;i < 2 * n - 1; i++) {
        st.set(i, {depth[timeline[i]], timeline[i]});
    }
    for(int i = 0; i < q ;i++) {
        int a, b;
        cin >> a >> b;
        if(start[a] > start[b]) {
            swap(a , b);
        }
        cout << st.calc(start[a], start[b] + 1).second << endl;
    }
}