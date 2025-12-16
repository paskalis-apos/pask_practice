#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct val{
    ll sum, minsum; 
};

struct segtree{
    int size;
    vector<val> values;

    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.resize(2 * size);
    }
    val merge(val a, val b) {
        val temp;
        temp.sum = a.sum + b.sum;
        temp.minsum = min(b.minsum, a.minsum + b.sum);
        return temp;
    }
    void add(int i,int v,int x, int lx, int rx) {
        if(rx - lx == 1){
            values[x].sum += v;
            values[x].minsum += v;
            return;
        }
        int m = (lx + rx) /2 ;
        if(i < m){
            add(i , v , 2 * x + 1, lx , m);
        }
        else{
            add(i , v , 2 * x + 2, m , rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void add(int i , int v) {
        add(i , v , 0 ,0 , size);
    }
    
    int smaller(int v, int x, int lx, int rx) {
        if(values[x].minsum >= v) {
            return -1;
        }
        if(rx - lx == 1){
            return lx;
        }
        int m = (lx + rx) / 2;
        if(values[2 * x + 2].minsum < v) {
            return smaller(v, 2 * x + 2, m , rx);
        }
        else {
            return smaller(v - values[2 * x + 2].sum, 2 * x +1, lx , m);
        }
    }

    int smaller() {
        return smaller(0, 0 ,0 , size);
    }
    
};

int main() {
    int n, m;
    cin >> n >> m;

    segtree st;
    st.init(1e6 + 1);
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        a[i] = num;
        st.add(num, -1);
    }
    vector<int> b(m);
    for(int i = 0;i < m; i++) {
        int num;
        cin >> num;
        b[i] = num;
        st.add(num, +1);
    }

    int q;  
    cin >> q;
    for(int i = 0;i < q; i++) {
        int op, j , x;
        cin >>op >> j >> x;
        j--;
        if(op == 1) {
            st.add(a[j] , 1);
            st.add(x , -1);
            a[j] = x;
        }
        else {
            st.add(b[j],  -1);
            st.add(x, 1);
            b[j] = x;
        }

        int ans = st.smaller();
        cout << ans << endl;
    }

}