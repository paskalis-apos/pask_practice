#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct item{
    ll seg , pref, suf , sum;
};

struct segtree {
    int size;
    vector<item> values;

    item nt_element = {0 , 0 , 0 , 0};
    
    item merge(item a , item b) {
        return{
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, a.suf + b.sum),
            a.sum + b.sum
        };
    }

    item single(int v) {
        if(v > 0) {
            return{v , v , v,v };
        }
        return{0 , 0 , 0, v};
    }
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(size * 2, nt_element);
    }
    void set(int i , int v , int x , int lx ,int rx) {
        if(rx - lx == 1) {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v, 2 * x + 1,lx , m);
        }
        else {
            set(i , v , 2 * x + 2 ,m , rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void set(int i , int v) {
        set(i , v , 0 , 0 , size);
    }
    item calc(int l , int r , int x , int lx , int rx) {
        if(lx >= r || rx <= l) {
            return nt_element;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        item s1 = calc(l , r, 2 * x + 1, lx , m);
        item s2 = calc(l , r ,2 * x + 2, m ,rx);
        return merge(s1 , s2);
    }

    item calc(int l, int r ) {
        return calc(l , r , 0 , 0 , size);
    }

};

int main() {
    int n , m;
    segtree st;
    cin >> n >> m;

    st.init(n);

    for(int i = 0 ;i < n; i++) {
        int v;
        cin >> v;
        st.set(i , v);
    }
    cout << st.calc(0 , n).seg << endl;
    for(int i = 0; i < m ; i++) {
        int ind , v;
        cin >> ind >> v;
        st.set(ind , v);
        cout << st.calc(0 , n).seg << endl;
    }

}