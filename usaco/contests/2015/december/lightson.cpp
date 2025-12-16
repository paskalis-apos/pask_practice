#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<vector<bool>> lit;
vector<vector<vector<pair<int,int>>>> toggle;
vector<vector<bool>> cango;
vector<vector<bool>> visited;

void floodfill() {
    lit[0][0] = true;
    queue<pair<int,int>>q;
    q.push({0 , 0});
    
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(visited[i][j]) {
            continue;
        }
        visited[i][j] = true;
        if(i > 0 ) {
            cango[i -1][j] = true;
            if(lit[i -1][j]) {
                q.push({i - 1, j});
            }
        }
        if(i < n - 1 ) {
            cango[i + 1][j] = true;
            if(lit[i + 1][j]) {
                q.push({i + 1, j});
            }
        }
        if(j > 0 ) {
            cango[i][j - 1] = true;
            if(lit[i][j - 1]) {
                q.push({i, j - 1});
            }
        }
        if(j < n -1) {
            cango[i][j + 1] = true;
            if(lit[i][j + 1]) {
                q.push({i , j + 1});
            }
        }

        for(auto &x : toggle[i][j]) {
            lit[x.first][x.second] = true;
            if(cango[x.first][x.second]) {
                q.push({x.first, x.second});
            }
        }

    }
}



int main() {
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    cin >> n >> m;
    lit.resize(n, vector<bool>(n));
    visited.resize(n , vector<bool>(n));
    cango.resize(n, vector<bool>(n));
    toggle.resize(n, vector<vector<pair<int,int>>>(n));
    for(int i = 0 ;i < m ;i++) {
        int a , b , c ,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        toggle[a][b].push_back({c , d});
    }

    floodfill();
    int numlit = 0;
    for(int i = 0 ;i < n ;i++) {
        for(int j = 0 ;j < n ;j++) {
            if(lit[i][j]) {
                numlit++;
            }
        }
    }

    cout << numlit << endl;

}