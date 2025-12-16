#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> values;
    void init(int n) {
        size = 1;
        while(size < n){ 
            size *= 2;
        }
        values.assign(2 * size, 0);
    }
    void add(int i, int x, int lx, int rx) {
        if(rx - lx == 1) {
            values[x]++;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) {
            add(i , 2 * x + 1 , lx , m);
        }
        else {
            add(i , 2 * x + 2, m , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void add(int i) {
        add(i , 0 ,0 , size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if(rx <= r && lx >= l) {
            return values[x];
        }
        if(rx <= l || lx >= r) {
            return 0;
        }
        int m = (lx + rx) / 2;
        int sum1 = sum(l, r, 2 * x + 1, lx, m);
        int sum2 = sum(l, r , 2 * x + 2, m , rx);
        return sum1 + sum2;
    }

    int sum(int l, int r) {
        return sum(l ,r , 0 ,0 ,size);
    }
};

int main() {
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);
    int n;
    cin >> n;   
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
    vector<int> sortv = v;
    sort(sortv.begin(), sortv.end());

    map<int,int> heightcomp;
    for(int i =0; i < n; i++) {
        heightcomp[sortv[i]] = i;
    }

    segtree st;
    st.init(n);

    vector<int> lsum(n);
    for(int i = 0;i < n;i++) {
        lsum[i] = st.sum(heightcomp[v[i]] + 1, n + 1);
        st.add(heightcomp[v[i]]);
    }
    int ans = 0;

    for(int i = 0;i < n;i++) {
        int totalsum = st.sum(heightcomp[v[i]] + 1, n + 1);
        if(totalsum - lsum[i] > 2 * lsum[i] || lsum[i] > 2 * (totalsum - lsum[i])) {
            ans++;
        }
    }

    cout << ans << endl;
}