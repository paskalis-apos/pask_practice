#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited;
int X, Y , k, m;

struct val { 
    int op, x, y;
};

int bfs() {
    queue<val> q;
    int res = INT_MAX;
    q.push({0,0,0});
    while(!q.empty()) {
        int op = q.front().op;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        res = min(res, abs(m - (x + y)));
        if(op == k) {
            continue;;
        }
        if(!visited[X][y]) {
            visited[X][y] = true;
            q.push({op + 1, X, y});
        }
        if(!visited[x][Y]) {
            visited[x][Y] = true;
            q.push({op + 1, x, Y});
        }
        if(!visited[0][y]) {
            visited[0][y] = true;
            q.push({op + 1, 0 , y});
        }
        if(!visited[x][0]) {
            visited[x][0] = true;
            q.push({op + 1, x , 0});
        }
        int x_to_y = min(x, Y -y);
        if(!visited[x - x_to_y][ y + x_to_y]) {
            visited[x - x_to_y][y + x_to_y] = true;
            q.push({op + 1, x - x_to_y, y + x_to_y});
        }
        int y_to_x = min(y, X - x);
        if(!visited[x + y_to_x][y - y_to_x]) {
            visited[x + y_to_x][y -y_to_x] = true;
            q.push({op + 1, x + y_to_x, y - y_to_x});
        }
    }

    return res;
}

int main() {
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    cin >> X >> Y >> k >> m;
    visited.resize(X + 1, vector<bool>(Y + 1));
    visited[0][0] = true;

    int ans = bfs();
    cout << ans << endl;
}