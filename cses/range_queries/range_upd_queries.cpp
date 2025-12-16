#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;

struct segtree {
    int size;
    vector<ll> adds;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        adds.assign(2 * size, 0);
    }
    void add(int l ,int r, int u,int x, int lx , int rx) {
        if(lx >= r || rx <= l) {
            return;
        }
        if(lx >= l && rx <= r) {
            adds[x] += u;
            return;
        }
        int m = (lx + rx ) / 2 ;
        add(l , r , u , 2 * x + 1, lx , m);
        add(l , r , u , 2 * x + 2, m , rx);
    }
    void add(int l ,int r, int u) {
        add(l , r , u , 0 , 0, size);
    }
    ll find_value(int k, int x , int lx ,int rx, ll sum) {
        sum += adds[x];
        if(rx - lx == 1) {
            return sum + v[k];
        }
        int m = (lx + rx) / 2 ;
        if(k < m) {
            return find_value(k , 2 * x + 1, lx , m , sum);
        }
        else {
            return find_value(k , 2 * x + 2, m , rx, sum);
        }
    }
    ll find_value(int k) {
        return find_value(k , 0 , 0 , size, 0);
    }
};

int main() {
    int n , q;
    cin >> n >> q;
    segtree st;
    st.init(n);
    v.resize(n);
    for(auto &x : v) {
        cin >> x;
    }


    for(int i = 0 ;i < q; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int a, b , u;
            cin >> a >> b >> u;
            a--;
            st.add(a, b , u);
        }
        else {
            int k;
            cin >> k;
            k--;
            cout << st.find_value(k) << endl;
        }
    }
}