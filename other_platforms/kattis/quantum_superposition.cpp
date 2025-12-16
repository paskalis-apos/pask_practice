#include<bits/stdc++.h>
using namespace std;

void init(vector<vector<int>> &adj,vector<bool> &visited,  int n , int m) {
    adj.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0 ;i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}

void dfs(vector<int> &tsort, vector<vector<int>> &adj, vector<bool> &visited, int cur) {
    visited[cur] = true;
    for(auto &x : adj[cur]) {
        if(visited[x]) {
            continue;
        }
        dfs(tsort, adj, visited, x);
    }
    tsort.push_back(cur);

}

void topsort(vector<int> &tsort, vector<vector<int>> &adj, vector<bool> &visited) {
    dfs(tsort, adj, visited, 1);
    reverse(tsort.begin(), tsort.end());
}

void make_dp(vector<set<int>> &dp, vector<vector<int>> &adj, vector<int> &topsort, int n) {
    dp.resize(n + 1);
    dp[1].insert(0);
    for(int i = 1;i <= n ;i++) {
        for(auto &x : adj[i]) {
            for(auto &y : dp[i]) {
                dp[x].insert(y + 1);
            }
        }
    }
}

int main() {
    int n1 , n2;
    int m1 , m2;
    vector<vector<int>> adj1;
    vector<vector<int>> adj2;
    vector<bool> visited1;
    vector<bool> visited2;
    cin >> n1 >> n2 >> m1 >> m2;
    init(adj1, visited1, n1 , m1);
    init(adj2, visited2, n2 , m2);
    
    vector<int> tsort1;
    vector<int> tsort2;
    topsort(tsort1, adj1, visited1);
    topsort(tsort2, adj2, visited2);

    vector<set<int>> dp1;
    vector<set<int>> dp2;
    make_dp(dp1 , adj1 , tsort1, n1);
    make_dp(dp2, adj2, tsort2, n2);

    set<int> poss1 = dp1[n1];
    set<int> poss2 = dp2[n2];

    int q;
    cin >> q;
    for(int i = 0 ;i < q; i++) {
        int target;
        cin >> target;
        int l = 0;
        int r = poss2.size() - 1;
        bool valid = false;
        for(auto &x : poss1) {
            int want = target - x;
            if(poss2.find(want) != poss2.end()) {
                valid = true;
                break;
            }
        }

        if(valid) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout << endl;
    }  
}