#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj;
vector<bool> visited;
int in_circle = 0;

void find_circles(int ind) {
    stack<int> s;
    vector<bool> nowvisited(n);
    while(!nowvisited[ind]) {
        if(visited[ind]) {
            return;
        }
        nowvisited[ind] = true;
        visited[ind] = true;
        s.push(ind);
        ind = adj[ind];
    }

    while(s.top() != ind) {
        s.pop();
        in_circle++;
    }
    in_circle++;
}

int main() {
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    cin >> n;
    adj.resize(n);
    visited.resize(n);
    for(auto &x : adj) {
        cin >> x;
        x--;
    }
    for(int i = 0 ;i < n ;i ++) {
        if(visited[i]) {
            continue;
        }
        find_circles(i);
    }

    cout << in_circle << endl;






}