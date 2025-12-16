#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct segtree
{
    ll size;
    vector<ll> values;
    void init(int n){ 
        size =1 ;
        while(size < n){ 
            size *= 2;
        }
        values.assign(size * 2, ll(0));
    }
    void add(ll i ,ll v, ll x, ll lx, ll rx) {
        if(rx - lx == 1){
            values[x] += v;
            return;
        }
        ll m = (lx + rx) / 2;
        if( i < m){ 
            add(i , v, 2 * x+ 1, lx ,m);
        }
        else {
            add(i , v , 2 * x+ 2, m, rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void add(ll i, ll v){ 
        add(i , v , 0 , 0 , size);
    }
    ll pref(ll r , ll x , ll lx ,ll rx)  {
        if(lx >= r || rx <= 0) {
            return 0;
        }
        if(lx >= 0 && rx <= r) {
            return values[x];
        }
        ll m = (lx + rx) / 2;
        ll s1 = pref(r , 2 * x + 1, lx ,m);
        ll s2 = pref(r, 2 * x + 2, m , rx);
        return s1 + s2;
    }
    ll pref(ll r) {
        return pref(r , 0 , 0 ,size);
    }
};

int main() {
    int n,  m;
    segtree st;
    cin >> n >> m;
    st.init(n + 1);
    for(int i = 0 ;i < m; i++) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll l , r , v;
            cin >> l >> r >> v;
            st.add(l , v);
            st.add(r , v * ll(-1));
        }
        else {
            ll ind;
            cin >> ind;
            cout << st.pref(ind + 1) << endl;
        }
    }
}
