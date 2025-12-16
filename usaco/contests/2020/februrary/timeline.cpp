#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> visited;
vector<int> v;
int n , m , c;

void dfs(int ind) {
    visited[ind] = true;
    for(auto &x : adj[ind]) {
        if(visited[x.first]) {
            continue;
        }
        dfs(x.first);
    }
    v.push_back(ind);
}

vector<int> top_sort(int ind) {
    for(int i = 1 ;i <= n ;i++) {
        if(visited[i]) {
            continue;
        }
        dfs(i);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    freopen("timeline.in","r", stdin);
    freopen("timeline.out","w",stdout); 
    cin >> n >> m >> c;
    visited.resize(n + 1);
    adj.resize(n + 1);
    vector<int> dp(n + 1);
    for(int i = 1; i <= n ;i++) {
        cin >> dp[i];
    }

    for(int i = 0 ;i < c ; i++) {
        int a,  b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b , c});
    }

    vector<int> tsort;
    tsort = top_sort(1);

    for(auto &x : tsort) {
        for(auto &y : adj[x]) {
            dp[y.first] = max(dp[y.first], dp[x] + y.second);
        }
    }

    for(int i = 1 ;i <= n; i++) {
        cout << dp[i] << endl;
    }


}