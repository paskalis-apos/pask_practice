#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct road{
    ll a , b , c;
    bool operator<(road temp) {
        return c > temp.c;
    }
};

ll n;
vector<ll> parents;
vector<ll> teamsize;


ll get(ll a) {
    if(a != parents[a]) {
        parents[a] = get(parents[a]);
    }
    return parents[a];
}

bool unite(ll a , ll b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return true;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a , b);
    }
    teamsize[b] += a;
    parents[a] = b;
    return false;
}

int main() {
    freopen("superbull.in","r",stdin);
    freopen("superbull.out","w",stdout);
    cin >> n;
    vector<road> adj;
    parents.resize(n + 1);
    teamsize.resize(n + 1 , 1);
    for(int i = 1; i <= n ;i++) {
        parents[i] = i;
    }

    vector<int> teams(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> teams[i];
    }

    for(int i = 1; i <= n ; i++) {
        for(int j = i + 1; j <= n;j++) {
            int cost = teams[i] ^ teams[j];
            adj.push_back({i , j, cost});
        }
    }
    ll total_points = 0;
    sort(adj.begin(), adj.end());
    for(auto &x : adj) {
        if(!unite(x.a , x.b)) {
            total_points += x.c;
        }
    }

    cout << total_points << endl;
}