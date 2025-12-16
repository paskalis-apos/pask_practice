#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct segtree {
    int size;
    vector<ll> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size , 0);
    }
    void addone(int i , int x ,int lx ,int rx) {
        if(rx - lx == 1){ 
            values[x]++;
            return;
        }
        int m = (lx + rx) /2 ;
        if(i < m){ 
            addone(i , 2 * x+ 1, lx , m);
        }
        else{
            addone(i , 2 * x + 2, m, rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void addone(int i) {
        addone(i ,0, 0, size);
    }
    ll suf(int l , int x , int lx ,int rx) {
        if(rx <= l || lx >= size) {
            return 0;
        }
        if(rx <= size && lx >= l) {
            return values[x];
        }
        int m = (lx + rx) /2 ;
        ll s1 = suf(l , 2 * x+ 1,lx ,m);
        ll s2 = suf(l , 2 * x + 2, m , rx);
        return s1 + s2;
    }

    ll suf(int l) {
        return suf(l , 0 ,0 ,size);
    }
};

int main() {
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
    int n;
    cin >> n;
    vector<ll> minval(n + 1);
    segtree st;
    st.init(n);

    for(int i = 0 ;i < n; i++) {
        int val;
        cin >> val;
        minval[val] += st.suf(val + 1);
        st.addone(val);
    }

    ll sum = 0;
    for(int i = 0 ;i < n ;i ++ ){
        cout << sum << endl;
        sum += minval[i];
    }
}