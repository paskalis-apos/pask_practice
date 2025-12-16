#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>subnum;
vector<vector<int>> adj;

int dfs(int cur , int par) {
    for(auto &x : adj[cur]) {
        subnum[cur] += dfs(x , cur) + 1;
    }
    return subnum[cur];
}

int main() {
    cin >> n;
    subnum.resize(n);
    adj.resize(n);

    for(int i = 1; i < n; i++) {
        int boss; 
        cin >> boss;
        boss--;
        adj[boss].push_back(i);
    }

    dfs(0 , 0);

    for(auto &x : subnum) {
        cout << x <<" ";
    }
    cout << endl;
}