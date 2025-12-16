#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n , m;
vector<vector<ll>> grid;
vector<vector<bool>> waypoint;
vector<vector<bool>> visited;

void floodfill(int i , int j, ll mid) {
    queue<pair<int,int>>q;
    q.push({i , j});

    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(visited[i][j]) {
            continue;
        }
        visited[i][j] = true;
        if(i > 0 && abs(grid[i][j] - grid[i -1][j]) <= mid) {
            q.push({i - 1, j});
        }
        if(i < n - 1 && abs(grid[i][j] - grid[i + 1][j]) <= mid) {
            q.push({i + 1, j});
        }
        if(j > 0 && abs(grid[i][j] - grid[i][j - 1]) <= mid) {
            q.push({i, j - 1});
        }
        if(j < m - 1 && abs(grid[i][j] - grid[i][j + 1]) <= mid) {
            q.push({i , j + 1});
        }
    }
}


bool valid(ll mid) {
    visited.clear();
    visited.resize(n ,vector<bool>(m));
    bool searched = false;
    for(int i = 0 ;i < n && !searched; i++) {
        for(int j = 0 ;j < m && !searched; j++) {
            if(waypoint[i][j]) {
                floodfill(i , j, mid);
                searched = true;
            }
        }
    }

    for(int i = 0 ;i < n ;i++) {
        for(int j = 0; j < m ;j++) {
            if(waypoint[i][j] && !visited[i][j]) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
    cin >> n >> m;
    grid.resize(n, vector<ll>(m));
    waypoint.resize(n , vector<bool>(m));

    for(int i = 0 ;i < n;i++) {
        for(int j = 0 ;j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0 ;i < n ;i++) {
        for(int j = 0 ; j < m; j++) {
            int temp;
            cin >> temp;
            waypoint[i][j] = temp;
        }
    }

    ll l = 0;
    ll r = 1e9;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(valid(mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}

