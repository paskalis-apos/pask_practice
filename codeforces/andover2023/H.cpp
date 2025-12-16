#include<bits/stdc++.h>
using namespace std;

struct val{
    int zeros, ones;
};

struct segtree{
    int size;
    vector<val> values;
    val BASE = {0, 0};
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.resize(2 * size, BASE);
    }

    val merge(val a, val b){
        val ans;
        ans.ones = a.ones + max(0, b.ones - a.zeros);
        ans.zeros = b.zeros + max(0, a.zeros - b.ones);
        return ans;
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(v == 1) {
                values[x].ones = 1;
                values[x].zeros = 0;
            }
            else {
                values[x].zeros = 1;
                values[x].ones = 0;
            }
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i , v , 2 * x + 1, lx , m);
        }
        else {
            set(i , v , 2 * x + 2, m , rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v){
        set(i , v , 0 , 0, size);
    }

    val length(int l, int r, int x, int lx, int rx){
        if(rx <= l || lx >= r) {
            return BASE;
        }
        else if(rx <= r && lx >= l) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        val length1 = length(l ,r, 2 * x + 1, lx ,m);
        val length2 = length(l , r, 2 * x + 2, m , rx);
        return merge(length1, length2);
    }

    int length(int l, int r){
        val temp = length(l, r , 0 ,0 , size);
        return temp.ones + temp.zeros;
    }
};

int main() {
    string bs;
    cin >> bs;
    int q;
    cin >> q;

    segtree st;
    st.init(bs.size());
    for(int i = 0;i < bs.size(); i++) {
        st.set(i , bs[i] - '0');
    }

    for(int i = 0;i < q ; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x;
            cin >> x;
            x--;
            if(bs[x] == '0') {
                bs[x] = '1';
            }
            else {
                bs[x] = '0';
            }
            st.set(x, bs[x] - '0');
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            cout << st.length(l , r + 1) << endl;
        }
    }
}