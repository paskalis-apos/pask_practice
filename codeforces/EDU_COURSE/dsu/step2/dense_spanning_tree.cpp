#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> p(1000 + 5);
vector<ll> cr(1000 + 5);

ll get(ll a) {
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}

void unite(ll a, ll b) {
    a = get(a);
    b = get(b);
    if(cr[a] < cr[b]) {
        swap(a, b);
    }
    cr[a] += (cr[a] == cr[b]);
    p[b] = a;
}

bool together(ll a, ll b){
    if(get(a) == get(b)) {
        return true;
    }
    return false;
}

struct edge{
    ll a , b , w;
    bool operator<(const edge &b){
        return w < b.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n ,m;
    cin >> n >> m;
    vector<edge> v(m);
    for(auto &x : v){
        cin >> x.a >> x.b >> x.w;
    }
    sort(v.begin(), v.end());
    ll ans = 1e12;
    for(int i = 0 ;i < m ;i++) {
        for(int j = 1; j <=n ;j++) {
            p[j] = j;
            cr[j] = 1;
        }
        ll minw = 1e9;
        ll maxw = -1e9;
        for(int j = i;j < m; j++) {
            if(!together(v[j].a, v[j].b)) {
                unite(v[j].a, v[j].b);
                maxw = max(maxw, v[j].w);
                minw = min(minw, v[j].w);
            }
        }
        bool valid = true;
        for(int j = 2; j <= n;j++) {
            if(!together(1 , j)) {
                valid = false;
                break;
            }
        }
        if(!valid) {
            continue;
        }
        ans = min(ans, maxw - minw);
    }
    if(ans == 1e12) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl << ans << endl;
    }
    
}