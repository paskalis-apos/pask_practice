#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(size * 2 , 0);
    }
    void makeone(int i , int x, int lx ,int rx) {
        if(rx - lx == 1) {
            values[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            makeone(i , 2 * x + 1, lx , m);
        }
        else {
            makeone(i , 2 * x + 2, m , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];

    }
    void makeone(int i) {
        makeone(i , 0 , 0 , size);
    }
    int sum(int l , int r, int x ,int lx, int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = sum(l , r , 2 * x + 1,lx , m);
        int s2 = sum(l , r , 2 * x + 2,m , rx);
        return s1 + s2;
    }
    int sum(int l, int r) {
        return sum(l , r , 0 , 0 , size);
    }
};

int main(){
    int n;
    cin >> n;
    segtree st;
    n *= 2;
    st.init(n);
    map<int,int> lastoc;
    vector<int> nestednum(n / 2);
    for(int i = 1 ;i <= n ;i++) {
        int val;
        cin >> val;
        val--;
        if(lastoc[val]) {
            nestednum[val] = st.sum(lastoc[val] - 1, i);
            st.makeone(lastoc[val] - 1);
        }
        else {
            lastoc[val] = i;
        }
    }

    for(auto &x : nestednum) {
        cout << x <<" ";
    }
}