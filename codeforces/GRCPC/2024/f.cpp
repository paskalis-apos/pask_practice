#include<bits/stdc++.h>
using namespace std;
int n, m , d;

int dx[4] = {-1 , 1 , 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};

bool inrange(int x , int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    return true;
} 

int main() {
    cin >> n >> m >> d;

    vector<vector<char>> grid(n, vector<char>(m));
    for(auto &x: grid) {
        for(auto &y : x) { 
            cin >> y;
        }
    }

    vector<vector<bool>> cansee(n , vector<bool>(m));
    pair<int,int> endcord;
    pair<int,int> startcord;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m; j++) {
            if(grid[i][j] == 'v') {
                cansee[i][j] = true;
                for(int ind = i + 1;ind < min(i + d + 1, n); ind++) {
                    cansee[ind][j] = true;
                    if(grid[ind][j] != '.' && grid[ind][j] != 'H' && grid[ind][j] != 'F') {
                        break;
                    }
                }
            }
            else if(grid[i][j] == '^') {
                cansee[i][j] = true;
                for(int ind = i - 1;ind > max(-1, i - d - 1); ind--) {
                    cansee[ind][j] = true;
                    if(grid[ind][j] != '.' && grid[ind][j] != 'H' && grid[ind][j] != 'F') {
                        break;
                    }
                }
            }
            else if(grid[i][j] == '>') {
                cansee[i][j] = true;
                for(int ind = j + 1;ind < min(j + d + 1, m); ind++) {
                    cansee[i][ind] = true;
                    if(grid[i][ind] != '.' && grid[i][ind] != 'H' && grid[i][ind] != 'F') {
                        break;
                    }
                }
            }
            else if(grid[i][j] == '<') {
                cansee[i][j] = true;
                for(int ind = j - 1;ind > max(j - d - 1, -1); ind--) {
                    cansee[i][ind] = true;
                    if(grid[i][ind] != '.' && grid[i][ind] != 'H' && grid[i][ind] != 'F') {
                        break;
                    }
                }
            }
            else if(grid[i][j] == '#') {
                cansee[i][j] = true;
            }
            else if(grid[i][j] == 'H') {
                endcord = {i , j};
            }
            else if(grid[i][j] == 'F') {
                startcord = {i , j};
            }
        }
    }
    if(cansee[startcord.first][startcord.second]) {
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<bool>> visited(n , vector<bool>(m));
    visited[startcord.first][startcord.second] = true;
    queue<pair<int,int>> q;
    q.push(startcord);
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0;i < 4 ;i++) {
            int newx = cur.first + dx[i];
            int newy = cur.second + dy[i];
            if(!inrange(newx, newy) || cansee[newx][newy] || visited[newx][newy]) {
                continue;
            }
            visited[newx][newy] = true;
            q.push({newx, newy}); 
        }
    }

    if(visited[endcord.first][endcord.second]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }


}