#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<int> cowtype;
vector<int> component;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int cur , int team, int compnum ) {
    visited[cur] = true;
    component[cur] = compnum;
    for(auto &x : adj[cur]) {
        if(!visited[x] && cowtype[x] == team) {
            dfs(x , team , compnum);
        }
    }
}

int main() {
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    cowtype.resize(n);
    component.resize(n);

    for(auto &x : cowtype) {
        char temp;
        cin >> temp;
        if(temp == 'G') {
            x = 0;
        }
        else {
            x = 1;
        }
    }

    for(int i = 0 ;i < n - 1; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int counter = 0;
    for(int i = 0 ;i < n ;i++) {
        if(!visited[i]) {
            dfs(i , cowtype[i], counter);
            counter++;
        }
    }

    for(int i = 0 ;i < m ;i++) {
        int a , b;
        char type;
        cin >> a >> b >> type;
        a--;
        b--;

        int team;
        if(type == 'G') {
            team = 0;
        }
        else {
            team = 1;
        }

        if(component[a] != component[b] || cowtype[a] == team) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

    
}

    