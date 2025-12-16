#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<vector<int>> grid;

void bfs(queue<pair<int,int>> q, vector<vector<pair<int,char>>> &dist) {
    if(!q.empty()) {
        dist[q.front().first][q.front().second].first = 0;
    }
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        
        int curdist = dist[cur.first][cur.second].first + 1;
        if(cur.first < n -1 && grid[cur.first + 1][cur.second] == 0) {
            if(dist[cur.first + 1][cur.second].first == INT_MAX) {
                q.push({cur.first + 1, cur.second});
                dist[cur.first + 1][cur.second] = {curdist, 'D'};
            }
        }
        if(cur.first > 0 && grid[cur.first - 1][cur.second] == 0) {
            if(dist[cur.first - 1][cur.second].first == INT_MAX) {
                q.push({cur.first - 1, cur.second});
                dist[cur.first - 1][cur.second] = {curdist, 'U'};
            }
        }
        if(cur.second < m -1 && grid[cur.first ][cur.second + 1] == 0) {
            if(dist[cur.first ][cur.second + 1].first == INT_MAX)  {
                q.push({cur.first, cur.second + 1});
                dist[cur.first][cur.second + 1] = {curdist, 'R'};
            }
        }
        if(cur.second > 0 && grid[cur.first][cur.second - 1] == 0) {
            if(dist[cur.first ][cur.second - 1].first == INT_MAX) {
                q.push({cur.first, cur.second - 1});
                dist[cur.first][cur.second - 1] = {curdist, 'L'};
            }
        }
    }
}

int main() {
    cin >> n >> m;

    vector<vector<pair<int,char>>> monsterdist(n, vector<pair<int,char>>(m, {INT_MAX, '0'}));
    queue<pair<int,int>>monsters;
    queue <pair<int,int>> start;    
    grid.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0;j < m; j++) {
            char temp;
            cin >> temp;
            if(temp == '#') {
                grid[i][j] = - 1;
            }
            else {
                if(temp == 'A') {
                    start.push({i , j});
                }
                else if(temp == 'M') {
                    monsters.push({i, j});
                    monsterdist[i][j].first = 0;
                }
            }
        }
    }

    vector<vector<pair<int,char>>> mydist(n , vector<pair<int,char>>(m, {INT_MAX, '0'}));   

    bfs(start, mydist);
    bfs(monsters, monsterdist);

    int x , y;
    bool valid = false;
    for(int i = 0 ;i < n && !valid; i++) {
        if(mydist[i][0].first < monsterdist[i][0].first) {
            x = i;
            y = 0;
            valid = true;
        }
        else if(mydist[i][m - 1].first < monsterdist[i][m - 1].first){
            x = i;
            y = m - 1;
            valid = true;
        }
    }

    for(int j = 0; j < m && !valid; j++) {
        if(mydist[0][j].first < monsterdist[0][j].first) {
            x = 0;
            y = j;
            valid = true;
        }
        else if(mydist[n -1][j].first < monsterdist[n - 1][j].first) {
            x = n - 1;
            y = j;
            valid = true;
        }
    }

    if(!valid) {
        cout << "NO" << endl;
    }

    else {
        cout << "YES" << endl;
        vector<char> ans;
        while(mydist[x][y].first > 0) {
            ans.push_back(mydist[x][y].second);
            if(mydist[x][y].second == 'U') {
                x++;
            }
            else if(mydist[x][y].second == 'D') {
                x--;
            }
            else if(mydist[x][y].second == 'L') {
                y++;
            }
            else {
                y--;
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(auto &x : ans){
            cout << x ;
        }
        cout << endl;
    }

}