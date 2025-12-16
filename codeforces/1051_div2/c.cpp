#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 0;i < n - 1;i++) {
        int a , b , x,  y;
        cin >> a >> b >> x >> y;
        a--;
        b--;
        if(x > y) {
            adj[b].push_back(a);
        }
        else {
            adj[a].push_back(b);
        }
    }

    vector<int> indeg(n);
    for(int i = 0;i < n;i++) {
        for(auto &x : adj[i]) {
            indeg[x]++;
        }
    }
    vector<int> tsort;
    queue<int> q;
    for(int i = 0;i < n;i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        tsort.push_back(cur);
        for(auto &x : adj[cur]) {
            indeg[x]--;
            if(indeg[x] == 0) {
                q.push(x);
            }
        }
    }

    vector<int> ans(n);
    for(int i = 0;i < n ;i++) {
        ans[tsort[i]] = i + 1;
    }
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;



}

int main( ){
    int t;
    cin >> t;
    for(int i = 0;i < t ;i++) {
        solve();
    }
}