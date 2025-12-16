#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> mins;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        mins.assign(size * 2, 1e9 + 1);
    }

    void set(int i ,int v , int x , int lx , int rx)  {
        if(rx - lx == 1) {
            mins[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v , 2 * x + 1 , lx , m);
        }
        else{
            set(i , v, 2 * x + 2, m , rx);
        }
        mins[x] = min(mins[2 * x + 1] , mins[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i , v , 0 , 0, size);
    }

    int find_min(int l , int r, int x , int lx , int rx) {
        if(l >= rx || r <= lx) {
            return 1e9 + 1;
        }
        if(l <= lx && r >= rx) {
            return mins[x];
        }
        int m = (lx + rx) / 2;
        int s1 = find_min(l , r, 2 * x + 1, lx , m);
        int s2 = find_min(l , r ,2 * x + 2, m , rx);
        return min(s1 , s2);
    }   
    int find_min(int l , int r) {
        return find_min(l , r + 1, 0 , 0, size);
    }
};

int main() {
    int n , q;
    cin >> n >> q;

    segtree st;
    st.init(n);

    for(int i = 0 ;i < n ;i++) {
        int val;
        cin >> val;
        st.set(i , val);
    }

    for(int i = 0 ;i < q; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int k , u;
            cin >> k >> u;
            k--;
            st.set(k ,u);
        }
        else {
            int l , r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.find_min(l , r) << endl;
        }
    }
}