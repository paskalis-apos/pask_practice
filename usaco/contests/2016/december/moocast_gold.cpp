#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;

vector<vector<ll>> cowdist;
vector<bool> visited;

void dfs(int cur, ll mid){
    visited[cur] = true;
    for(int i = 0 ;i < n; i++) {
        if(visited[i]) {
            continue;
        }
        else if(cowdist[cur][i] <= mid) {
            dfs(i, mid);
        }
    }   
}

bool valid(ll mid) {
    dfs(0, mid);
    for(int i = 0 ;i < n ;i++) {
        if(visited[i] == false) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    vector<pair<int,int>>cowloc(n);
    for(auto &x : cowloc) {
        cin >> x.first >> x.second;
    }
    cowdist.resize(n , vector<ll>(n));
    visited.resize(n);
    for(int i = 0;i < n ;i++) {
        for(int j = 0 ;j < n;j ++) {
            cowdist[i][j] = (cowloc[i].first - cowloc[j].first) * (cowloc[i].first - cowloc[j].first) + (cowloc[i].second - cowloc[j].second) * (cowloc[i].second - cowloc[j].second);
        }
    }

    ll l = 0, r = ll(50000) * ll(50000);
    while(l < r ) {
        visited.assign(n, false);
        ll mid = (l + r) / 2;
        if(valid(mid )) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    int answer = l;
    cout << answer << endl;
}