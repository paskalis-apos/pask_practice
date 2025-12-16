#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> revadj;
vector<bool> visited;
int totalvisited;

void dfs(vector<vector<int>> &paths, int index) {
    if(visited[index]) {
        return;
    }
    visited[index] = true;
    totalvisited++;
    for(auto &x : paths[index]) {
        dfs(paths, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int citiesnum , flightsnum;
    cin >> citiesnum >> flightsnum;

    adj.resize(citiesnum);
    revadj.resize(citiesnum);
    visited.resize(citiesnum);
    for(int i = 0 ;i < flightsnum; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        revadj[b].push_back(a);
    }

    totalvisited = 0;
    dfs(adj, 0);
    if(totalvisited == citiesnum) {
        visited.assign(citiesnum, false);
        totalvisited = 0;
        dfs(revadj , 0);
        if(totalvisited == citiesnum) {
            cout << "YES" << endl;

        }

        else {
            for(int i = 0 ;i < citiesnum ; i++) {
                if(visited[i] == false) {
                    cout << "NO" << endl;
                    cout << i + 1 << " 1";
                    break;
                }
            }
        }
    }
    else {
        for(int i = 0 ;i < citiesnum; i++) {
            if(visited[i] == false) {
                cout << "NO" << endl;
                cout << "1 " << i +1;
                break;
            }
        }
    }



}