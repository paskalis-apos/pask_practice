#include<bits/stdc++.h>
using namespace std;
vector<map<int, bool>> adj;
set<int> unvisited;
int cursize;


void dfs(int cur) {
    cursize++;
    unvisited.erase(cur);
    int prev = 0;
    while(!unvisited.empty() && unvisited.upper_bound(prev) != unvisited.end()) {
        prev = *unvisited.upper_bound(prev);
        if(adj[cur][prev]) {
            continue;
        }
        dfs(prev);
    }
}

int main() {
    int n , m;
    cin >> n >> m;
    adj.resize(n + 1);
    for(int i =1 ;i <= m;i++) {
        int a , b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }   
    for(int i = 1;i <= n;i++) {
        unvisited.insert(i);
    }
    vector<int> ans;
    for(int i =1 ;i <= n; i++) {
        if(unvisited.find(i) == unvisited.end()) {
            continue;
        }
        cursize = 0;
        dfs(i);
        ans.push_back(cursize);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

}