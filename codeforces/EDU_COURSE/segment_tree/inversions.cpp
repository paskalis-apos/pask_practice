#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> values;

    int merge(int a , int b) {
        return a + b;
    }
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size, 0);
    }
    void add(int i , int x ,int lx , int rx) {
        if(rx - lx == 1) {
            values[x]++;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            add(i ,2 * x + 1, lx , m);
        }
        else {
            add(i , 2 * x + 2 , m , rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void add(int i) {
        add(i , 0 , 0, size);
    }
    int sum(int l ,int r, int x, int lx , int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = sum(l , r , 2 * x + 1, lx , m);
        int s2 = sum(l , r , 2 * x + 2, m ,rx);
        return merge(s1 , s2);
    }
    int sum(int l ,int r) {
        return sum(l , r , 0 ,0 ,size);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> tosort(n);
    vector<int> temp(n);
    segtree st;
    st.init(n);
    for(int i = 0; i < n ;i++) {
        int help;
        cin >> help;
        tosort[i] = help;
        temp[i] = help;
    }
    
    sort(tosort.begin(), tosort.end());
    unique(tosort.begin(), tosort.end());
    map<int,int> realval;
    for(int i = 0 ;i < n; i++) {
        realval[tosort[i]] = i;
    }   
    long long invs = 0;

    for(int i = 0 ;i < n ;i++) {
        int rval = realval[temp[i]];
        cout << st.sum(rval , n + 1) << " ";
        st.add(rval);
    }   
}



int main (){
    solve();

}