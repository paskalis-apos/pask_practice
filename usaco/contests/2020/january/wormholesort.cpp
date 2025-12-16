#include<bits/stdc++.h>
using namespace std;
int n , m;
vector<int>p;
vector<vector<pair<int,int>>> adj;
vector<bool>visited;
set<int> locs;
set<int> inds;



void dfs(int index, int mid) {
    if(visited[index]) {
        return;
    }
    visited[index] = true;
    locs.insert(index);
    inds.insert(p[index]);
    for(auto &x : adj[index]) {
        if(!visited[x.first] && x.second >= mid) {
            dfs(x.first, mid);
        }
    }

}

bool valid(int mid) {
    for(int i = 0; i < n;i ++) {
        locs.clear();
        inds.clear();
        if(!visited[i]) {
            dfs(i , mid);
        }
        if(locs != inds) {
            return false;
        }
        
    }
    return true;
}



int main() {
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    cin >> n >> m;

    p.resize(n);
    adj.resize(n);
    for(int i = 0 ;i < n ;i++) {
        int temp;
        cin >> temp;
        p[i] = temp - 1;
    }
    for(int i = 0; i < m; i++) {
        int a , b ,w;
        cin >> a >> b >> w;
        a--; 
        b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    int l = 0, r = 1e9 + 1;
    while(l < r) {
        visited.assign(n , false);
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    if(l == 1e9 + 1) {
        cout << -1 << endl;
        return 0;
    }

    cout << l << endl;



}