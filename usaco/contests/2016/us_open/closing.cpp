#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool>visited;
vector<bool>closed;
int totalbarns, totalpaths;
int visitednum;

void read_adj() {
    for(int i = 0 ;i < totalpaths; i++) {
        int a , b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
}

void dfs(int index) {
    if(visited[index] || closed[index]) {
        return;
    }
    visited[index] = true;
    visitednum++;
    for(auto &x : adj[index]) {
        dfs(x);
    }
}


int main() {
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    cin >> totalbarns >> totalpaths;
    adj.resize(totalbarns);
    visited.resize(totalbarns);
    closed.resize(totalbarns);
    
    read_adj();

    for(int closednum = 0 ;closednum < totalbarns; closednum++) {
        visited.assign(totalbarns, false);
        for(int i = 0 ;i < totalbarns; i++) {
            if(!closed[i] ) {
                dfs(i);
                break;
            }
        }
        if(visitednum < totalbarns) {
            cout << "NO";
        }
        else {
            cout <<"YES";
        }
        cout << endl;
        int closes;
        cin >> closes;
        closed[--closes] = true;
        visitednum = closednum + 1;
    }
    

}