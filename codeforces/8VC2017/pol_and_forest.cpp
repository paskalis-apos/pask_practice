#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int cur , int par) {
    visited[cur] =true;
    for(auto &x: adj[cur]) {
        if(x != par) {
            dfs(x , cur);
        }
    }
} 

int main() {
    cin >> n;
    adj.resize(n);
    visited.resize(n);
    for(int i = 0 ;i < n ;i++) {
        int temp;
        cin >> temp;
        temp--;
        adj[i].push_back(temp);
        adj[temp].push_back(i);
    }

    int trees = 0;

    for(int i = 0 ;i < n ;i++) {
        if(visited[i]) {
            continue;
        }
        dfs(i , i);
        trees++;
    }

    cout << trees << endl;
}