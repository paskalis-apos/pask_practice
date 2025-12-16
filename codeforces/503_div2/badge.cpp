#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> in_cycle;
vector<bool> boolean_cycle;
vector<int> reports;
vector<int> two_holes;
vector<vector<int>> adj;
int outside_var;
vector<bool> visited;



void cycle_detection(int ind) {
    vector<bool> nowvisited(n);
    stack<int> nodes;
    int cur = ind;
    while(!nowvisited[cur]) {
        nowvisited[cur] = true;
        if(visited[cur] == true) {
            return;
        }
        visited[cur] = true;
        nodes.push(cur);
        cur = reports[cur];
    }

    while(nodes.top() != cur) {
        in_cycle.push_back(nodes.top());
        boolean_cycle[nodes.top()] = true;
        nodes.pop();
    }
    in_cycle.push_back(nodes.top());
    boolean_cycle[nodes.top()] = true;
    nodes.pop();
}

void dfs(int cur) {
    two_holes[cur] = outside_var;
    for(auto &x : adj[cur]) {
        if(boolean_cycle[x] != true) {
            dfs(x);
        }
    }
}

int main() {
    cin >> n;
    reports.resize(n);
    two_holes.resize(n);
    adj.resize(n);
    boolean_cycle.resize(n);
    visited.resize(n);
    for(auto &x : reports) {
        cin >> x;
        x--;
    }

    for(int i = 0 ;i < n ;i++) {
        if(!visited[i]) {
            cycle_detection(i);
        }
    }
    for(int i = 0; i < n ;i++) {
        adj[reports[i]].push_back(i);
    }

    for(auto &x : in_cycle) {
        outside_var = x;
        dfs(x);
    }

    for(auto &x : two_holes) {
        cout << x + 1<< " ";
    }

    cout << endl;

} 