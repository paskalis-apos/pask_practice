#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<string>inp;
vector<vector<bool>> visited;
vector<vector<bool>> grid;

void floodfill() {
    if(grid[n - 1][m -1] == false) {
        return;
    }
    queue<pair<int,int>> q;
    q.push({n -1, m - 1});

    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(visited[i][j]) {
            continue;
        }
        visited[i][j] = true;
        if(i > 0 && grid[i -1][j]) {
            q.push({i - 1, j});
        }
        if(i < n -1 && grid[i + 1][j]) {
            q.push({i + 1, j});
        }
        if(j > 0 && grid[i][j - 1]) {
            q.push({i , j -1});
        }
        if(j < m -1 && grid[i][j + 1]) {
            q.push({i , j + 1});
        }
    }

}

void solve() {
    cin >> n >> m;
    inp.resize(n);
    visited.resize(n , vector<bool>(m));
    grid.resize(n , vector<bool>(m));
    for(int i = 0 ;i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            grid[i][j] = true;
        }
    }

    for(int i = 0; i < n ;i++) {
        cin >> inp[i];
    }
    bool onegood = false;
    bool valid = true;
    for(int i = 0 ;i < n;i++) {
        for(int j = 0; j < m; j++) {
            if(inp[i][j] == 'G') {
                onegood = true;
            }
            if(inp[i][j] == 'B') {
                if(i > 0) {
                    if(inp[i -1][j] == 'G') {
                        valid = false;
                    }
                    grid[i -1][j] = false;
                }
                if(i < n -1) {
                    if(inp[i + 1][j] == 'G') {
                        valid = false;
                    }
                    grid[i +1][j] = false;
                }
                if(j > 0) {
                    if(inp[i][j - 1] == 'G') {
                        valid = false;
                    }
                    grid[i][j -1] = false;
                }
                if(j < m- 1) {
                    if(inp[i][j + 1] == 'G') {
                        valid = false;
                    }
                    grid[i][j + 1] = false;
                }
            }
            else if(inp[i][j] == '#') {
                grid[i][j] = false;
            }
            if(!valid) {
                cout << "No" << endl;
                return;
            }
        }
    }


    floodfill();
    for(int i = 0 ;i < n ;i++) {
        for(int j = 0; j < m ;j++) {
            if(inp[i][j] == 'G' && visited[i][j] == false) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        inp.clear();
        visited.clear();
        grid.clear();
        solve();
    }
}