#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<int> top_sort;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int i) {
    visited[i] = true;
    for(auto &x : adj[i]) {
        if(visited[x]) {
            continue;
        }
        dfs(x);
    }
    top_sort.push_back(i);
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0 ;i < m; i++) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n ;i++) {
        if(visited[i]) {
            continue;
        }
        dfs(i);
    }

    reverse(top_sort.begin(), top_sort.end());
    vector<int> ind(n + 1);
    for(int i = 0; i < n; i++) {
        ind[top_sort[i]] = i;
    }
    bool valid = true;
    for(int i = 1; i <= n; i++) {
        for(auto &x : adj[i]) {
            if(ind[x] <= ind[i]) {
                valid = false;
            }
        }
    }

    if(valid) {
        for(auto &x : top_sort) {
            cout << x << " ";
        }
    }
    else  {
        cout << "IMPOSSIBLE";
    }

    cout << endl;


}