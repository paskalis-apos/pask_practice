#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct segtree{
    int size;
    vector<ll> values;
    void init(int n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.resize(2 * size, 0);
    }
    void add(ll i,ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            values[x] += v;   
            values[x] %= MOD; 
            return;
        }
        ll m = (lx + rx) / 2;
        if(i < m) {
            add(i , v,  2 * x + 1, lx , m);
        }
        else{
            add(i ,v ,  2 * x+ 2, m , rx);
        }

        values[x] = values[2 * x + 1] + values[2 * x + 2];
        values[x] %= MOD;
    }
    void add(ll i, ll v) {
        add(i ,v ,  0 , 0 , size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if(rx <= r && lx >= l) {
            return values[x];
        }
        if(rx <= l || lx >= r) {
            return 0;
        }
        ll m = (lx + rx) / 2;
        ll sum1 = sum(l,r , 2 * x + 1, lx, m);
        ll sum2 = sum(l, r , 2 * x + 2, m, rx);
        return(sum1 + sum2) % MOD;
    }

    ll sum(int l, int r) {
        return sum(l , r ,0 , 0 , size);
    }

};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v){ 
        cin >> x;
    }
    vector<int> sortv = v;
    sort(sortv.begin(), sortv.end());   
    map<int,int> cordcomp;
    for(int i = 0;i < n;i++) {
        cordcomp[sortv[i]] = i;
    }
    vector<ll> dp(n);
    segtree st;
    st.init(n + 1);
    for(int i = 0;i < n;i++) {
        dp[i] = st.sum(0 , cordcomp[v[i]]) + 1;
        st.add(cordcomp[v[i]], dp[i]);
    }

    cout << st.sum(0, n) << endl;
}