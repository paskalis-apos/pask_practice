#include<bits/stdc++.h>
using namespace std;

int n ,m;
vector<vector<int>> adj;
vector<vector<int>> opadj;
vector<int> top_sort;
vector<bool> visited;
vector<bool> in_path;

bool dfs(int cur){ 
    visited[cur] = in_path[cur] = true;
    for(auto &x : adj[cur]) {
        if(in_path[x]) {
            return false;
        }  
        if(visited[x]) {
            continue;
        } 
        if(!dfs(x)) {
            return false;
        }
    }
    in_path[cur] = false;
    top_sort.push_back(cur);
    return true;
}

int main( ){
    cin >> n >> m;
    adj.resize(n); 
    opadj.resize(n); 
    visited.resize(n);
    in_path.resize(n);
    string s;
    cin >> s;
    for(int i = 0;i < m ;i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        opadj[b].push_back(a);
    }

    for(int i = 0; i < n;i++) {
        if(visited[i]) {
            continue;
        }
        if(!dfs(i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    vector<vector<int>> maxlet(n , vector<int>(26));

    int ans = 0;

    for(auto &x : top_sort) {
        for(auto &y : opadj[x]) {
            for(int i = 0 ;i < 26;i++) {
                maxlet[x][i] = max(maxlet[x][i], maxlet[y][i]);
                ans = max(ans, maxlet[x][i]);
            }
        }
        maxlet[x][s[x] - 'a']++;
        ans = max(ans, maxlet[x][s[x] - 'a']);
    }

    cout << ans << endl;
}