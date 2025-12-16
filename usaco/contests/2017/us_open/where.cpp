#include<bits/stdc++.h>
using namespace std;

struct pcl {
    int x1 , y1 , x2 , y2;
};

int n;
vector<vector<int>> image;
vector<pcl>all;
vector<vector<bool>> visited(n, vector<bool>(n));
vector<int> colours(26);

bool contained(int i , int j) {
    if(all[i].x1 <= all[j].x1 && all[i].y1 <= all[j].y1 && all[i].x2 >= all[j].x2 && all[i].y2 >= all[j].y2) {
        all[j].x1 = -1;
        return true;
    }
    if(all[j].x1 <= all[i].x1 && all[j].y1 <= all[i].y1 && all[j].x2 >= all[i].x2 && all[j].y2 >= all[i].y2) {
        all[i].x1 = -1;
        return true;
    }
    return false;
}

void floodfill(int i , int j, int x1 , int y1 , int x2 , int y2, int colour) {
    queue<pair<int,int>> q;
    q.push({i , j});

    while(!q.empty()) {
        int x  = q.front().first;
        int y = q.front().second;
        q.pop();

        if(visited[x][y]) {
            continue;
        }
        visited[x][y] = true;
        if(x > x1 && image[x -1][y] == colour) {
            q.push({x - 1, y});
        }
        if(x < x2 && image[x + 1][y] == colour) {
            q.push({x + 1, y});
        }
        if(y > y1 && image[x][y - 1] == colour) {
            q.push({x, y - 1});
        }
        if(y < y2 && image[x][y + 1] == colour) {
            q.push({x , y + 1});
        }
    }
}

bool valid(int x1 , int y1 , int x2 , int y2) {
    queue<pair<int,int>> q;
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(visited[i][j]) {
                continue;
            }
            else {
                floodfill(i , j , x1 , y1 , x2 , y2, image[i][j]);
                colours[image[i][j]]++;
            }
        }
    }

    bool onereg = false;
    bool morereg = false;
    int colourspresent = 0;

    for(auto &x : colours) {
        if(x > 0) {
            if(x == 1) {
                onereg = true;
            }
            else {
                morereg = true;
            }
            colourspresent++;
        }
    }

    if(onereg && morereg && colourspresent == 2) {
        return true;
    }

    return false;

}

void check_rectangles(int i , int j) {
    int x = i ;
    int y = j;
    while(x < n) {
        y = j;
        while(y < n) {
            visited.assign(n , vector<bool>(n));
            colours.assign(26, 0);
            if(valid(i , j , x , y)) {
                pcl temp;
                temp.x1 = i;
                temp.x2 = x;
                temp.y1 = j;
                temp.y2 = y;
                all.push_back(temp);
            }
            y++;
        }
        x++;
    }
}

int main() {
    freopen("where.in","r",stdin);
    freopen("where.out","w",stdout);
    cin >> n;
    image.resize(n);

    for(int i = 0 ;i < n ;i++) {
        for(int j = 0; j < n ;j++) {
            char temp;
            cin >> temp;
            image[i].push_back(temp - 'A');
        }
    }

    for(int i = 0 ;i < n ;i++) {
        for(int j = 0 ;j < n; j++) {
            check_rectangles(i , j);
        }
    }

    int msize = int(all.size());
    int remove = 0;

    for(int i = 0 ;i < msize; i++) {
        for(int j = i + 1; j < msize; j++) {
            if(all[i].x1 == -1 || all[j].x1 == -1) {
                continue;
            }
            if(contained(i , j)) {
                remove++;
            }
        }
    }

    int total = msize - remove;
    cout << total << endl;
}
