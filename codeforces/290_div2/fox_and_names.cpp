#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> tsort;
vector<int> in_path;

bool dfs(int cur) {
    visited[cur] = in_path[cur] = true;
    for(auto &x :adj[cur]) {
        if(in_path[x]) {
            return false;
        }
        if(visited[x]) {
            continue;
        }
        if(!dfs(x)) {
            return false;
        }
    }
    tsort.push_back(cur);
    in_path[cur] = false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    vector<bool> checked(n);
    in_path.resize(n);
    visited.resize(26);
    for(int i = 0;i < n;i++) {
        cin >> names[i];
    }   
    adj.resize(26);


    for(int i = 0;i < n - 1; i++) {
        bool valid = false;
        for(int j = 0;j < min(names[i].size(), names[i + 1].size()); j++) {
            if(names[i][j] == names[i + 1][j]) {
                continue;
            }
            else {
                adj[names[i][j] - 'a'].push_back(names[i + 1][j] - 'a');
                valid = true;
                break;
            }
        }
        if(!valid && names[i].size() > names[i + 1].size()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(visited[i]) {
            continue;
        }
        in_path.assign(26, false);
        if(!dfs(i)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    reverse(tsort.begin(), tsort.end());
    for(auto &x : tsort) {
        cout << char(x + 'a');
    }
    cout << endl;

}