#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

void solve() {
    int n;
    cin >> n;
    adj.assign( n + 1  , {});

    for(int i =0; i < n - 1; i++) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n == 2) {
        cout << 0 << endl;
        return;
    }
    int curleafs = 0;
    int totalleafs = 0;
    for(int i =1 ;i <= n ;i++) {
        int cur = 0;
        for(auto &y : adj[i]) {
            if(adj[y].size() == 1) {
                cur++;
            }
        }
        curleafs = max(curleafs, cur);
        if(adj[i].size() == 1) {
            totalleafs++;
        }
    }

    int ans = totalleafs - curleafs;
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t ;i++ ){
        solve();
    }
}