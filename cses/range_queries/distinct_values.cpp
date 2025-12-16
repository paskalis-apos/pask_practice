#include<bits/stdc++.h>
using namespace std;

struct range {
    int l, r;
    bool operator<(range b) {
        return r < b.r;
    }

    int qnum;
};

struct segtree {
    int size;
    vector<int> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size + 1, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){ 
            set(i , v , 2 * x + 1,lx ,m);
        }
        else {
            set(i , v , 2 * x + 2, m , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void set(int i , int v) {
        set(i, v, 0, 0, size);
    }
    int sum(int l , int r , int x, int lx, int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = sum(l , r ,2 * x + 1,lx ,m);
        int s2 = sum(l , r, 2* x + 2, m ,rx);
        return s1 + s2;
    }
    int sum(int l , int r) {
        return sum(l , r , 0 , 0 , size);
    }
};



int main() {
    int n , q;
    cin >> n >> q;
    segtree st;
    st.init(n);
    vector<int> v(n);
    vector<range> queries(q);
    for(auto &x : v){ 
        cin >> x;
    }
    for(int i = 0 ;i < q ;i++) {
        queries[i].qnum = i;
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
    }
    sort(queries.begin(), queries.end());
    map<int, int> lastvisit;
    vector<int> answer(q);    
    int vindex = 0;
    for(auto &x : queries) {
        while(vindex <= x.r) {
            int val = v[vindex];
            if(lastvisit[val]) {
                st.set(lastvisit[val] - 1, 0);
            }
            lastvisit[val] = vindex + 1;
            st.set(vindex, 1);
            vindex++;
        }

        answer[x.qnum] = st.sum(x.l, x.r + 1);

    }

    for(auto &x : answer) {
        cout << x << endl;
    }


}