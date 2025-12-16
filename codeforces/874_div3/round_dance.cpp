#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int>rem;
vector<bool> visited;
int mindance, maxdance;
bool found;

bool is_circle(int ind, int parent) {
    visited[ind] = true;
    for(auto &x : adj[ind]) {
        if(!visited[x]) {
            if(is_circle(x, ind)) {
                return true;
            }
        }
        else if(parent != x){
            return true;
        }
    }
    return false;
}


void solve() {
    cin >> n;
    adj.assign(n, {});
    rem.assign(n, 0);
    visited.assign(n, false);
    mindance = 0;
    maxdance = 0;

    for(int i = 0 ;i < n; i++) {
        int temp;
        cin >> temp;
        temp--;
        bool a = true;
        bool b = true;
        for(auto &x: adj[temp]) {
            if(x == i) {
                a = false;
            }
        }
        for(auto &x : adj[i]) {
            if(x == temp) {
                b = false;
            }
        }
        if(a) {
            adj[temp].push_back(i);
        }
        if(b) {
            adj[i].push_back(temp);
        }
        rem[i] = temp;
        
    }
    bool fno = false;

    for(int i = 0 ;i < n ;i++) {
        if(visited[i]) {
            continue;
        }
        found = false;
        if(is_circle(i, i)) {
            mindance++;
        }
        else {
            if(!fno) {
                mindance++;
                fno = true;
            }
        }
        maxdance++;
    }

    cout << mindance << " " << maxdance << endl;
    
}


int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t;i++) {
        solve();
    }
}