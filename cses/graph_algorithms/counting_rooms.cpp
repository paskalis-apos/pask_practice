#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> grid;
vector<vector<bool>> visited;

void floodfill(int i , int j) {
    queue<pair<int,int>> q;
    q.push({i , j});
    
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        if(visited[i][j]) {
            continue;
        }
        visited[i][j] = true;

        if(i > 0 && grid[i - 1][j] == true) {
            q.push({i - 1, j});
        }
        if(i < n - 1 && grid[i + 1][j] == true) {
            q.push({i + 1, j});
        }
        if(j > 0 && grid[i][j -1] == true) {
            q.push({i , j - 1});
        }
        if(j < m - 1 && grid[i][j + 1] == true) {
            q.push({i , j + 1});
        }
    }
    
}

int main() {
    cin >> n >> m;
    grid.resize(n , vector<bool>(m));
    visited.resize(n , vector<bool>(m));
    for(int i = 0 ;i < n ;i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if(temp == '.') {
                grid[i][j] = true;
            }
            else {
                grid[i][j] = false;
            }
        }
    }

    int rooms = 0;

    for(int i = 0 ;i < n ;i++) {
        for(int j = 0 ; j < m; j++) {
            if(visited[i][j] || grid[i][j] == false){
                continue;
            }
            floodfill(i , j);
            rooms++;
        }
    }

    cout << rooms << endl;
}