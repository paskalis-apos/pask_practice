#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<vector<char>>v;
vector<vector<int>> distances;
vector<vector<bool>> visited;
vector<vector<char>> prevstep;
pair<int,int> start;
pair<int,int> finish;

void floodfill() {
    queue<pair<int,int>>q;
    q.push({start.first, start.second});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;

        if(x > 0 && v[x -1][y] == '.' && !visited[x - 1][y]) {
            q.push({x - 1, y});
            distances[x -1][y] = distances[x][y] + 1;
            prevstep[x -1][y] = 'U';
            visited[x-1][y] = true;
        }
        if(x < n - 1 && v[x + 1][y] == '.' && !visited[x + 1][y]) {
            q.push({x + 1, y});
            distances[x + 1][y] = distances[x][y] + 1;
            prevstep[x + 1][y] = 'D';
            visited[x + 1][y] = true;
        }
        if(y > 0 && v[x][y - 1] == '.' && !visited[x][y - 1]) {
            q.push({x, y - 1});
            distances[x][y - 1] = distances[x][y] + 1;
            prevstep[x][y - 1] = 'L';
            visited[x][y - 1] = true;
        }
        if(y < m - 1&& v[x][y + 1] == '.' && !visited[x][y + 1]) {
            q.push({x, y + 1});
            distances[x][y + 1] = distances[x][y] + 1;
            prevstep[x][y + 1] = 'R';
            visited[x][y + 1] = true;
        }
    }
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n , vector<char>(m));
    distances.resize(n, vector<int>(m));
    visited.resize(n , vector<bool>(m));
    prevstep.resize(n, vector<char>(m));
    for(int i = 0 ;i < n ;i++) {
        for(int j = 0; j < m;j ++) {
            cin >> v[i][j];
            if(v[i][j] == 'A') {
                start.first =  i;
                start.second = j;
            }
            else if(v[i][j] == 'B') {
                finish.first = i;
                finish.second = j;
                v[i][j] = '.';
            }
        }
    }

    floodfill();

    if(!visited[finish.first][finish.second]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int dist = distances[finish.first][finish.second];
    cout << dist << endl;

    vector<char>moves(dist);
    int x = finish.first;
    int y = finish.second;
    int counter = dist -1;
    while(counter >= 0) {
        moves[counter] = prevstep[x][y];
        if(prevstep[x][y] == 'L') {
            y++;
        }
        else if(prevstep[x][y] == 'R') {
            y--;
        }
        else if(prevstep[x][y] == 'U') {
            x++;
        }
        else {
            x--;
        }
        counter --;
    }
    for(auto &x : moves) {
        cout << x;
    }
    cout << endl;
    
}