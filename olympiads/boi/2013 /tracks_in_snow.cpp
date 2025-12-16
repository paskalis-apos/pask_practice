#include<bits/stdc++.h>
using namespace std;

int h , w;
vector<string>grid;
int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
bool inside(int y , int x) {
    return (x > -1 && y > -1 && x  < w && y < h && grid[y][x] != '.');
}

int main() {
    cin >> h >> w;
    grid.resize(h);
    for(int i = 0; i < h ;i++) {
        cin >> grid[i];
    }
    deque<pair<int,int>> q;
    q.push_back({0 , 0 });
    vector<vector<int>>depth(h , vector<int>(w));
    int ans = 1;
    depth[0][0] = 1;
    while(!q.empty()) {
        int ycord = q.front().first;
        int xcord = q.front().second;
        q.pop_front();
        ans = max(ans, depth[ycord][xcord]);

        for(int i = 0;i <  4 ;i++) {
            int x = xcord + dx[i];
            int y = ycord + dy[i];
            if(!inside(y , x) || depth[y][x] != 0) {
                continue;
            }
            if(grid[ycord][xcord] == grid[y][x]) {
                q.push_front({y, x});
                depth[y][x] = depth[ycord][xcord];
            }
            else {
                q.push_back({y, x});
                depth[y][x] = depth[ycord][xcord] + 1;
            }
        }
    }


    cout << ans << endl;
}