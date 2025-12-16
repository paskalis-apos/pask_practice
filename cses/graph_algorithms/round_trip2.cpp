#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cycle;
vector<bool> visited, on_stack;
bool stop = false;

bool dfs(int cur){ 
    visited[cur] = on_stack[cur] = true;
    for(auto &x : adj[cur]) {
        if(on_stack[x]) {
            cycle.push_back(x);
            cycle.push_back(cur);
            on_stack[x] = on_stack[cur] = false;
            return true;
        }
        else if(!visited[x]) {
            if(dfs(x)) {
                cycle.push_back(cur);
                if(on_stack[cur]) {
                    on_stack[cur] = true;
                    return true;
                }
                else {
                    return false;
                }
            }
        }

        if(!cycle.empty()) {
            return false;
        }
    }
    on_stack[cur] = false;
    return false;
}

int main() {
    int n , m;
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    on_stack.resize(n);
    for(int i = 0; i < m ;i++) {
        int  a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }

    for(int i = 0; i < n ;i++) {
        if(!visited[i] && cycle.size() == 0) {
            dfs(i);
        }
    }
    if(cycle.size() == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << cycle.size() << endl;
    reverse(cycle.begin(), cycle.end());
    for(auto &x : cycle) {
        cout << x + 1 << " ";
    }
    cout << endl;
}