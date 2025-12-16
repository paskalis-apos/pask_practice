#include<bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> values;
    void init(int n) {
        size =1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size , 0);
    }
    void set(int i , int v, int x, int lx ,int rx) {
        if(rx - lx == 1) {
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){ 
            set(i, v , 2 * x + 1, lx , m);
        }
        else {
            set(i , v , 2 * x+ 2, m, rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];

    }
    void set(int i , int v) {
        set(i , v , 0 ,0 , size);
    }

    int sum(int l , int r, int x , int lx ,int rx) {
        if(lx >= r || rx <= l) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        int s1 = sum(l , r, 2 * x + 1, lx , m);
        int s2 = sum(l , r , 2 * x + 2, m , rx);
        return s1 + s2;
    }

    int sum(int l , int r){
        return sum(l , r , 0 , 0 , size);
    }
    int find_index(int k, int lx , int rx) {
        if(rx - lx == 1){ 
            return lx;
        }
        int m = (lx + rx) /2 ;
        int cursum = sum(lx , m);
        if(cursum >= k) {
            return find_index(k , lx ,m);
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
    int n;
    cin >> n;
    segtree st;
    st.init(n);

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        st.set(i , 1);
    }





    for(int i = 0 ;i < n ;i++) {
        int val;
        cin >> val;
        int curind = st.find_index(val);
        st.set(curind , 0);
        cout << v[curind] << " ";
    }
}