#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<ll> start;
vector<ll> stop;
vector<ll> timeline;
vector<ll> nodeval;
ll curtime = 0;

struct segtree {
    ll size;
    vector<ll> values;
    void init(ll n) {
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size , 0);
    }

    void set(ll i , ll v, ll x ,ll lx , ll rx) {
        if(rx - lx == 1) {
            values[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if(i < m) {
            set(i , v , 2 * x + 1, lx , m);
        }
        else {
            set(i , v , 2 * x + 2, m , rx);
        }
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void set(ll i , ll v){
        set(i , v , 0 , 0 , size);
    }

    ll sum(ll l , ll r, ll x, ll lx , ll rx) {
        if(lx >= r || rx <= l ) {
            return 0;
        }
        if(lx >= l && rx <= r) {
            return values[x];
        }
        ll m = (lx + rx) / 2;
        ll s1 = sum(l , r, 2 * x + 1, lx , m);
        ll s2 = sum(l , r , 2* x + 2, m , rx);
        return s1 + s2;
    }
    ll sum(ll l, ll r){
        return sum(l, r , 0 , 0 , size);
    }
};

void euler_tour(ll cur, ll par) {
    timeline[curtime] = nodeval[cur];
    start[cur] = curtime++;
    for(auto &x :adj[cur]) {
        if(x == par){
            continue;
        }
        euler_tour(x , cur);
    }
    timeline[curtime] = -nodeval[cur];
    stop[cur] =curtime++;
}

int main() {
    ll n , q;
    cin >> n >> q;
    nodeval.resize(n);
    adj.resize(n);
    start.resize(n);
    stop.resize(n);
    timeline.resize(2 * n);
    for(auto &x : nodeval) {
        cin >> x;
    }

    for(int i = 0; i < n - 1;i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    euler_tour(0 , -1);
    segtree st;
    st.init(2 * n);
    for(int i = 0; i <2 * n; i++) {
        st.set(i , timeline[i]);
    }

    for(int i = 0; i < q; i++) {
        ll opp;   
        cin >> opp;
        if(opp == 1){
            ll i , v;
            cin >> i >> v;
            i--;
            st.set(start[i], v);
            st.set(stop[i], -v);
        }
        else {
            ll x;
            cin >> x;
            x--;
            cout << st.sum(0 , start[x] + 1) << endl;
        }
    }

}