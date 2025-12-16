#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> distances;
vector<bool> visited;

void bfs(int starting) {
    queue<int> q;
    q.push(starting);
    visited[starting] = true;
    distances[starting] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto &x : adj[cur]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
                distances[x] = distances[cur] + 1;
            }
        }
    }
}


int main() {
    cin >> n;
    adj.resize(n);
    visited.resize(n);
    distances.resize(n);

    for(int i = 0 ;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0);
    int oneindex = 0;
    int maxdist = 0;
    for(int i = 0 ;i < n; i++) {
        if(distances[i] > maxdist) {
            oneindex = i;
            maxdist = distances[i];
        }
    }
    visited.assign(n, false);
    bfs(oneindex);
    maxdist = 0;
    int twoindex = 0;
    for(int i = 0 ;i < n ;i++) {
        if(distances[i] > maxdist) {
            twoindex = i;
            maxdist = distances[i];
        }
    }
    vector<int> onedist = distances;
    visited.assign(n, false);
    bfs(twoindex);

    for(int i = 0 ;i < n ;i++) {
        cout << max(distances[i] , onedist[i]) << endl;
    }


    
}