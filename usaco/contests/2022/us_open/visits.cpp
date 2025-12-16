#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<pair<ll,ll>> adj;
ll totalsum = 0;
vector<bool> visited;

ll min_of_cicle(int ind) {
    vector<bool> nowvisited(n);
    stack<pair<ll,ll>> s;
    while(!nowvisited[ind]) {
        if(visited[ind]) {
            return 0;
        }
        visited[ind] = true;
        nowvisited[ind] = true;
        s.push({ind, adj[ind].second});
        ind = adj[ind].first;
    }
    ll minmoos = 1e9;
    while(s.top().first != ind) {
        minmoos = min(minmoos, s.top().second);
        s.pop();
    }
    minmoos = min(minmoos, s.top().second);
    return minmoos;
}

int main( ) {
    cin >> n;
    adj.resize(n);
    visited.resize(n);
    for(auto &x : adj)  {
        cin >> x.first >> x.second;
        x.first--;
        totalsum += x.second;
    }
    for(int i = 0 ;i < n; i++) {
        if(visited[i]) {
            continue;
        }
        totalsum -= min_of_cicle(i);
    }

    cout << totalsum << endl;






}