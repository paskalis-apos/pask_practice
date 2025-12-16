    #include<bits/stdc++.h>
    using namespace std;
    const int INF = 1e9;

    int n , s;
    vector<string> grid;
    vector<pair<int,int>> hiveloc;
    pair<int,int> mecholoc;
    pair<int,int> mechohome;
    vector<vector<int>> beetime;
    vector<vector<int>> mechodist;
    int dx[4] = {1 , - 1, 0 , 0};
    int dy[4] = {0 , 0 , 1 , -1};
    bool inside(int x , int y) {
        return (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] != 'T' && grid[x][y] != 'D');
    }

    bool valid(int m) {
        vector<vector<bool>> visited(n , vector<bool> (n));
        queue<pair<int,int>> q;
        q.push({mecholoc.first, mecholoc.second});
        int mechtime = m + 1;
        if(mechtime > beetime[mecholoc.first][mecholoc.second]) {
            return false;
        }
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0;i < 4; i++){ 
                int x = cur.first + dx[i];
                int y = cur.second + dy[i];
                if(x == mechohome.first && y == mechohome.second) {
                    visited[x][y] = true;
                }
                if(!inside(x , y) || visited[x][y] || mechodist[x][y] == INF) {
                    continue;
                }
                mechtime = m + mechodist[x][y] / s;
                if(mechodist[x][y] % s != 0) {
                    mechtime++;
                }
                if(mechtime <= beetime[x][y]) {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        return visited[mechohome.first][mechohome.second];
    }

    int main() {
        cin >> n >> s;
        grid.resize(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'H') {
                    hiveloc.push_back({i , j});
                }
                else if(grid[i][j] == 'M') {
                    mecholoc = {i , j};
                }
                else if(grid[i][j] == 'D') {
                    mechohome = {i , j};
                }
            }
        }
        beetime.assign(n , vector<int>(n , INF));
        queue<pair<int,int>> q;
        for(auto &x : hiveloc) {
            q.push(x);
            beetime[x.first][x.second] = 0;
        }    
        while(!q.empty()) {
            pair<int,int> cur= q.front();
            q.pop();
            for(int i = 0;i < 4; i++) {
                int x = cur.first + dx[i];
                int y = cur.second + dy[i];
                if(!inside(x , y) || beetime[x][y] != INF){ 
                    continue;
                }
                beetime[x][y] = beetime[cur.first][cur.second] + 1;
                q.push({x , y});
            }
        }
        
        
        
        mechodist.assign(n , vector<int>(n ,INF));
        while(!q.empty()) {
            q.pop();
        }
        q.push({mecholoc.first, mecholoc.second});
        mechodist[mecholoc.first][mecholoc.second] = 0;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for(int i = 0 ;i < 4 ;i++) {
                int x = cur.first + dx[i];
                int y = cur.second + dy[i];
                if(!inside(x ,y)|| mechodist[x][y] != INF) {
                    continue;
                }
                mechodist[x][y] = mechodist[cur.first][cur.second] + 1;
                q.push({x , y});
            }
        }
        
        int lo = 0;
        int hi = 1e6;

        while(lo < hi) {
            int m = (lo + hi + 1) / 2;
            if(valid(m)) {
                lo = m;
            }
            else {
                hi = m - 1;
            }
        }

        int ans = lo;
        cout << ans  << endl;
    }