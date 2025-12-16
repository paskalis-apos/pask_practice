#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct route{ 
    int a , b , c;
    bool operator<(route temp) {
        return c < temp.c;
    }
};

int n , m;
vector<int> parents;
vector<int> teamsize;

int get(int a) {
    if(a != parents[a]) {
        parents[a] = get(parents[a]);
    }
    return parents[a];
}

bool unite(int a , int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return true;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a , b);
    }
    teamsize[b] += teamsize[a];
    parents[a] = b;
    return false;
}

vector<route> adj;

int main() {
    cin >> n >> m;
    parents.resize(n + 1);
    teamsize.resize(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        parents[i] = i;
    }
    for(int i = 0; i < m ;i++) {
        int a , b , c;
        cin >> a >> b >> c;
        adj.push_back({a , b , c});
    }

    sort(adj.begin(), adj.end());

    ll cost = 0;
    for(auto &x : adj) {
        if(!unite(x.a , x.b)) {
            cost += x.c;
        }
    } 
    
    for(int i = 2 ;i <= n; i++) {
        if(!unite(1 , i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << cost << endl;
}