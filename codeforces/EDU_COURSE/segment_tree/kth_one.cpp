#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> sums;

    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        sums.assign(size * 2, 0);
    }

    void set(int i, int x , int lx, int rx) {
        if(rx - lx == 1) {
            if(sums[x]) {
                sums[x] = 0;
            }
            else {
                sums[x] = 1;
            }
            return;
        }
        int m = (lx + rx)  / 2;
        if(i < m) {
            set(i ,2 * x + 1, lx , m);
        }
        else {
            set(i ,2 * x + 2, m , rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i) {
        set(i, 0 , 0, size);
    }
    int sum(int l , int r , int x, int lx , int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return sums[x];
        }
        int m = (lx + rx)  / 2;
        int s1 = sum(l , r , 2 * x + 1,lx , m);
        int s2 = sum(l , r, 2 * x + 2, m , rx);
        return s1 + s2;
    }
    int sum(int l , int r) {
        return sum(l , r , 0 , 0, size);
    }
    int find_index(int k ,int lx ,int rx) {
        if(rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx)  / 2;
        int cursum = sum(lx , m);
        if(cursum >= k) {
            return find_index(k, lx, m);
        }
        else {
            return find_index(k - cursum, m , rx);
        }
    }

    int find_index(int k) {
        return find_index(k , 0 , size);
    }
};

int main() {
    int n, m;
    segtree st;
    cin >> n >> m;
    st.init(n);
    for(int i = 0 ;i < n; i++) {
        int val;
        cin >> val;
        if(val == 1) {
            st.set(i);
        }
    }

    for(int i = 0 ;i < m ;i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int i;
            cin >> i;
            st.set(i);
        }
        else {
            int k;
            cin >> k;
            cout << st.find_index(k + 1) << endl;
        }
    }
}