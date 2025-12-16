#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> tsort;

void dfs(int ind) {
    visited[ind] = true;
    for(auto &x : adj[ind]) {
        if(visited[x]) {
            continue;
        }
        dfs(x);
    }
    tsort.push_back(ind);
}

void top_sort()  {
    dfs(1);
    reverse(tsort.begin(), tsort.end());
}

int main() {
    int n , m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0 ;i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    top_sort();
    if(!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<pair<int,int>> sdp(n + 1, {1 , 0});
    for(int i = 0 ;i < int(tsort.size()); i++) {
        int cur = tsort[i];
        for(auto &x : adj[cur]) {
            if(sdp[x].first < sdp[cur].first + 1) {
                sdp[x].first = sdp[cur].first + 1;
                sdp[x].second = cur;
            }
        }
    }

    int answer = sdp[n].first;
    int index = n;
    cout << answer << endl;
    vector<int> route;
    while(answer > 0) {
        route.push_back(index);
        index = sdp[index].second;
        answer--;
    }
    reverse(route.begin(), route.end());
    for(auto &x : route) {
        cout << x << " ";
    }
}