#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct val{
    ll sum, pref, suf, ans;
};

struct segtree{
    int size;
    vector<val> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(size * 2, {0 , 0 ,0, 0});
    }
    val merge(val a, val b) {
        val temp;
        temp.sum = a.sum + b.sum;
        temp.suf = max(b.suf, b.sum + a.suf);
        temp.pref = max(a.pref, a.sum + b.pref);
        temp.ans = max(a.ans, max(b.ans, a.suf + b.pref));
        return temp;
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x].sum = v;
            values[x].suf = values[x].ans = values[x].pref = max(ll(0), v);
            return ;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i , v , 2 * x + 1, lx , m);
        }
        else {
            set(i ,v, 2 * x + 2, m , rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);

    }
    void set(int i, int v) {
        set(i, v, 0 , 0, size);
    }
};

int main() {
    int n ,m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        st.set(i , num);
    }

    for(int i = 0;i < m; i++) {
        int j , v;
        cin >> j >> v;
        j--;
        st.set(j , v);
        cout << st.values[0].ans << endl;
    }
}