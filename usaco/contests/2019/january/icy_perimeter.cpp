#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<bool>> grid;
vector<vector<bool>> visited;
int temparea , tempper;

void floodfill(int i , int j) {
    queue<pair<int,int>> q;
    q.push({i , j});

    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        if(visited[i][j]) {
            continue;
        }
        visited[i][j] = true;
        if(i == 0 || !visited[i - 1][j]) {
            tempper++;
        }
        else {
            tempper--;
        }
        if(i == n -1 || !visited[i + 1][j]) {
            tempper++;
        }
        else {
            tempper--;
        }
        if(j == 0 || !visited[i][j - 1]) {
            tempper++;
        }
        else {
            tempper--;
        }
        if(j == n - 1 || !visited[i][j + 1]) {
            tempper++;
        }
        else {
            tempper--;
        }

        if(i > 0 && grid[i - 1][j]) {
            q.push({i - 1, j});
        }
        if(i < n - 1 && grid[i + 1][j]) {
            q.push({i + 1, j});
        }
        if(j > 0 && grid[i][j - 1]) {
            q.push({i , j - 1});
        }
        if(j < n -1 && grid[i][j + 1]) {
            q.push({i , j + 1});
        }
    temparea++;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> n;
    grid.resize(n , vector<bool>(n));
    visited.resize(n , vector<bool>(n));

    for(int i = 0 ;i < n; i++) {
        for(int j = 0 ;j < n ; j++) {
            char temp;
            cin >> temp;
            if(temp == '#') {
                grid[i][j] = true;
            }
        }
    }

    int area = 0;
    int per = 0;

    for(int i = 0 ;i < n; i++) {
        for(int j = 0 ;j < n; j++) {
            if(visited[i][j] || grid[i][j] == false) {
                continue;
            }
            temparea = 0;
            tempper = 0;

            floodfill(i , j);
            if(temparea > area) {
                area = temparea;
                per = tempper;
            }
            else if(temparea == area) {
                per = min(per, tempper);
            }
        }
    }

    cout << area << " " << per << endl;


}