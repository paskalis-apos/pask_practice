#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n , m;
vector<int> distances;
vector<bool> visited;
vector<int> prevnod;

void bfs() {
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int curval = q.front();
        q.pop();
        for(auto &x : adj[curval]) {
            if(visited[x]) {
                continue;
            }
            visited[x] = true;
            distances[x] = distances[curval] + 1; 
            prevnod[x] = curval;
            q.push(x);
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    distances.resize(n);
    visited.resize(n);
    prevnod.resize(n);
    distances[0] = 1;
    for(int i = 0 ;i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();

    if(visited[n - 1] == false) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    cout << distances[n - 1] << endl;
    int curnode = n -1;
    vector<int> answer(distances[n - 1]);
    int counter = distances[n - 1] -1;
    while(counter >= 0) {
        answer[counter] = curnode + 1;
        curnode = prevnod[curnode];
        counter--;
    }

    for(auto &x : answer) {
        cout << x << " ";
    }
    cout << endl;
}