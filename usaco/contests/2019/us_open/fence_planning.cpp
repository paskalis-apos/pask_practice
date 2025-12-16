#include<bits/stdc++.h>
using namespace std;

struct loc {
    int x, y;
};

vector<vector<int>> adj;
vector<bool> visited;
vector<loc> cords;
int minx, miny , maxx, maxy;

void dfs(int index) {
    if(visited[index]) {
        return;
    }
    visited[index] = true;
    minx = min(minx, cords[index].x);
    maxx = max(maxx, cords[index].x);
    miny = min(miny, cords[index].y);
    maxy = max(maxy, cords[index].y);
    for(auto &x : adj[index]) {
        dfs(x);
    }
}


int main() {
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    int cownum, pathnum;
    cin >> cownum >> pathnum;
    adj.resize(cownum);
    visited.resize(cownum);
    cords.resize(cownum);

    for(auto &x : cords) {
        cin >> x.x >> x.y;
    }

    for(int i = 0; i< pathnum; i++) {
        int a, b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int answer = INT_MAX;

    for(int index = 0;index < cownum; index++) {
        if(visited[index]) {
            continue;
        }
        minx = INT_MAX;
        miny = INT_MAX;
        maxx = 0;
        maxy = 0;
        dfs(index);

        int perimeter = 2 * (maxx - minx) + 2 * (maxy - miny);
        answer = min(answer , perimeter);
    }

    cout << answer << endl;

    
}