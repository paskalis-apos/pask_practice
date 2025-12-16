#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> maxelement;

    int merge(int a , int b) {
        return(max( a , b));
    }
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        maxelement.assign(2 * size , 0);
    }
    void set(int i ,int v, int x ,int lx, int rx) {
        if(rx - lx == 1) {
            maxelement[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            set(i , v ,2 * x + 1, lx , m);
        }
        else {
            set(i , v , 2 * x + 2, m ,rx);
        }
        maxelement[x] = merge(maxelement[2 * x + 1], maxelement[2 * x + 2]);
    }
    void set(int i , int v) {
        set(i , v, 0 , 0 , size);
    }
    int find_max(int l , int r, int x, int lx , int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return maxelement[x];
        }
        int m = (lx + rx) / 2;
        int s1 = find_max(l , r, 2 * x + 1, lx , m);
        int s2 = find_max(l , r, 2 * x + 2, m , rx);
        return merge(s1 , s2);
        
    }
    int find_max(int l , int r) {
        return find_max(l ,r , 0 , 0, size);
    }


    int find_index(int el , int lx , int rx) {
        if(find_max(lx , rx) < el) {
            return -1;
        }
        if(rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if(find_max(lx , m ) >= el) {
            return find_index(el ,lx, m);
        }
        else {
            return find_index(el , m, rx);
        }

    }
    int find_index(int el, int l) {
        return find_index(el ,l, size);
    }
};

int main(){ 
    int n, m;
    segtree st;
    cin >> n >> m;
    st.init(n);
    for(int i = 0 ;i < n ;i++) {
        int val;
        cin >> val;
        st.set(i , val);
    }

    for(int i = 0  ;i < m; i++) {
        int op;
        cin >> op;
        if(op ==1 ){ 
            int ind , v;
            cin >> ind >> v;
            st.set(ind , v);
        }
        else {
            int x, l;
            cin >> x >> l;
            cout << st.find_index(x , l) << endl;
        }
    }
}