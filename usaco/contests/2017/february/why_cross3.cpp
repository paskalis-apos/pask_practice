#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n , k , r;
vector<int>teams;
vector<vector<bool>>visited;
vector<vector<bool>> cows;
struct rd{
    int x1 , y1 , x2 , y2;
};
bool operator<(const rd &a , const rd &b) {
    if(b.x1 == a.x1) {
        if(b.y1 == a.y1) {
            if(b.x2 == a.x2) {
                return a.y2 < b.y2;
            }
            return a.x2 < b.x2;
        }
        return a.y1 < b.y1;
    }
    return a.x1 < b.x1;
}
map<rd , bool> roads;


void floodfill(int i, int j) {
    int numcows = 0;
    queue<pair<int,int>> q;
    q.push({i , j});
    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(visited[i][j]) {
            continue;
        }
        visited[i][j] = true;
        if(i > 0 && !roads[{i, j, i - 1, j}]) {
            q.push({i - 1, j});
        }
        if(i < n - 1 && !roads[{i, j, i + 1, j}]) {
            q.push({i + 1, j});
        }
        if(j > 0 && !roads[{i, j, i, j - 1}]) {
            q.push({i, j - 1});
        }
        if(j < n - 1 && !roads[{i, j, i, j + 1}]) {
            q.push({i, j + 1});
        }
        if(cows[i][j]) {
            numcows++;
        }
    }

    teams.push_back(numcows);
}

int main() {
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    cin >> n >> k >> r;
    visited.resize(n , vector<bool>(n));
    cows.resize(n, vector<bool>(n));

    for(int i = 0 ;i < r ; i++) {
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        rd one = {x1 , y1 , x2 , y2};
        rd two = {x2 , y2 , x1, y1};
        roads[one] = true;
        roads[two] = true;
    }

    for(int i = 0 ;i < k ;i++) {
        int x , y;
        cin >> x >> y;
        x--;
        y--;
        cows[x][y] = true;
    }

    for(int i = 0; i < n ;i++) {
        for(int j = 0; j < n ;j++) {
            if(!cows[i][j] || visited[i][j]) {
                continue;
            }
            floodfill(i , j);
        }
    }

    ll answer = 1;
    for(auto &x : teams) {
        answer += x * (k - x);
    }
    answer /= 2;
    cout << answer << endl;
}