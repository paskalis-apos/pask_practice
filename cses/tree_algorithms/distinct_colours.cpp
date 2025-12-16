#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> startstop;
vector<int> timeline;
int curtime = 0;

struct segtree {
    int size;
    vector<int> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size , 0);
    }

    void set(int i , int v, int x ,int lx , int rx) {
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
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void set(int i , int v){
        set(i , v , 0 , 0 , size);
    }

    int sum(int l , int r, int x, int lx , int rx) {
        if(lx >= r || rx <= l ) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = sum(l , r, 2 * x + 1, lx , m);
        int s2 = sum(l , r , 2* x + 2, m , rx);
        return s1 + s2;
    }
    int sum(int l, int r){
        return sum(l, r , 0 , 0 , size);
    }
};

void euler_tour(int cur, int par) {
    timeline[curtime] = cur;
    startstop[cur].first = curtime++;
    for(auto &x : adj[cur]) {
        if(x == par) {
            continue;
        }
        euler_tour(x , cur);
    }
    startstop[cur].second = curtime;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nodes(n );
    adj.resize(n);
    startstop.resize(n);
    timeline.resize(n);
    for(int i = 0 ;i < n ;i++) {
        cin >> nodes[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int a ,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    euler_tour(0 , -1);
    sort(startstop.rbegin(), startstop.rend());
    map<int,int> seenbefore;
    int curind = n - 1;
    segtree st;
    st.init(n);
    vector<int> queries(n);
    for(auto &x : startstop) {
        while(curind >= x.first) {
            st.set(curind, 1);
            if(seenbefore[nodes[timeline[curind]]]) {
                st.set(seenbefore[nodes[timeline[curind]]], 0);
            }
            seenbefore[nodes[timeline[curind]]] = curind;
            curind--;
        }
        queries[timeline[x.first]] = st.sum(x.first, x.second);
    }

    for(int i = 0;i < q; i++) {
        cout << queries[i] << endl;
    }


    
}