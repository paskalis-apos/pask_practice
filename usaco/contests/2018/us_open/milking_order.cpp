#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> tsort;
vector<int> inpath;
vector<bool> visited;
vector<vector<pair<int,int>>> edges;

bool dfs(int cur) {
    visited[cur] = inpath[cur] = true;
    for(auto &x: adj[cur]) {
        if(inpath[x]) {
            inpath[cur] = false;
            return false;
        }
        if(visited[x]) {
            continue;
        }
        if(!dfs(x)) {
            inpath[cur] = false;
            return false;
        }
    }

    tsort.push_back(cur);
    inpath[cur] = false;
    return true;
}

bool valid(int mid) {
    adj.assign(n,{});
    tsort.clear();
    inpath.assign(n , false);
    visited.assign(n , false);
    vector<int> indeg(n);
    for(int i = 0;i < mid; i++) {
        for(auto &x : edges[i]) {
            adj[x.first].push_back(x.second);
            indeg[x.second]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    int total = 0;
    for(int i = 0;i < n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
            total++;
        }
    }
    while(!q.empty()) {
        int cur = q.top();
        tsort.push_back(cur + 1);
        q.pop();
        for(auto &x : adj[cur]) {
            indeg[x]--;
            if(indeg[x] == 0) {
                q.push(x);
                total++;
            }
        }
    }
    if(total < n) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    cin >> n >> m;  
    edges.resize(m);
    for(int i = 0;i < m; i++) {
        int num;
        cin >> num;
        int bef;
        cin >> bef;
        bef--;
        for(int j = 1;j < num; j++) {
            int cur;
            cin >> cur;
            cur--;
            edges[i].push_back({bef ,cur});
            bef = cur;
        }
    }
    int l = 0, r = m;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(valid(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    valid(l);
    for(int i = 0;i < n - 1; i++) {
        cout << tsort[i] <<" ";
    }
    cout << tsort[n - 1];

}