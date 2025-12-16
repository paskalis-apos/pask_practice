#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int n , m;
void dfs(int s);

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);

    for(int i = 0 ;i < m ; i++) {
        int start_road;
        cin >> start_road;
        int end_road;
        cin >> end_road;

        adj[start_road ].push_back(end_road );
        adj[end_road].push_back(start_road);
    }

    unordered_set<int> cities;
    int dif_cities = 0;
    for(int i = 1; i <= n;i++) {
        if(visited[i]) {
            continue;
        }
        cities.insert(i);
        dif_cities++;
        dfs(i);
    }

    dif_cities--;
    cout << dif_cities << endl;


    auto x = cities.begin();
    x++;
    for(int i = 0; i <dif_cities; i++) {
        cout << *cities.begin() << " ";
        cout << *x << endl;
        x++;
    }

}

void dfs(int s) {
    if(visited[s]) {
        return;
    }
    visited[s] = true;
    for(auto x : adj[s]) {
        dfs(x);    
    }
}