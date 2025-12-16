#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct segtree {
    vector<ll> sums;
    int size;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        sums.assign(2 * size, ll(0));
    }

    void set(int i ,int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v , 2 * x + 1, lx, m);
        }
        else {
            set(i , v , 2 * x + 2, m , rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }


    void set(int i , int v) {
        set(i , v , 0 , 0 , size);
    }

    ll sum(int l , int r, int x , int lx ,int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return sums[x];
        }
        int m = (lx + rx) / 2;
        ll s1 = sum(l , r, 2 * x + 1, lx , m);
        ll s2 = sum(l , r , 2 * x + 2, m , rx);
        return s1 + s2;
    }

    ll sum(int l , int r){
        return sum(l , r + 1, 0 , 0 , size);
    }
};

int main(){
    int n , q;
    segtree st;
    cin >> n >> q;
    st.init(n);
    for(int i = 0 ;i < n ;i++) {
        int val;
        cin >> val;
        st.set(i , val);
    }
    for(int i = 0 ;i < q; i++) {
        int op;
        cin >> op;
        if(op == 1){
            int k , u;
            cin >> k >> u;
            k--;
            st.set(k , u);
        }
        else {
            int l ,r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.sum(l , r) << endl;
        }
    }
}