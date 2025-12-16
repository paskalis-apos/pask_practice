#include<bits/stdc++.h>
using namespace std;

int n ;
vector<vector<int>> adj;
vector<int> distances;
vector<bool> visited;

void bfs (int starting) {
    queue<int> q;
    q.push(starting);
    visited[starting] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x : adj[cur]) {
            if(visited[x]) {
                continue;
            }
            visited[x] = true;
            distances[x] = distances[cur] + 1;
            q.push(x);
        }
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    distances.resize(n);
    visited.resize(n);

    for(int i = 0; i  < n - 1; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0);
    int mdist = 0;
    int newstart = 0;
    for(int i = 0 ;i < n;i++) {
        if(distances[i] > mdist) {
            newstart = i;
            mdist = distances[i];
        }
    }

    visited.assign(n , false);
    distances.assign(n , 0);

    bfs(newstart);
    mdist = 0;
    for(auto &x : distances) {
        mdist = max(mdist , x);
    }

    cout << mdist << endl;
    

    
}