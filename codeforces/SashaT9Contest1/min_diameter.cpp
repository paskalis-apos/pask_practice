#include<bits/stdc++.h>
using namespace std;

int n;
int m;
vector<vector<int>> one;
vector<vector<int>> two;
vector<int> onedist;
vector<int> twodist;
vector<bool> onevisited;
vector<bool> twovisited;

void bfsone(int starting) {
    queue<int> q;
    q.push(starting);
    onedist[starting] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        onevisited[cur] = true;
        for(auto &x : one[cur]) {
            if(!onevisited[x]) {
                onevisited[x] = true;
                onedist[x] = onedist[cur] + 1;
                q.push(x);
            }
        }
    }
}

void bfstwo(int starting) {
    queue<int> q;
    q.push(starting);
    twodist[starting] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        twovisited[cur] = true;
        for(auto &x : two[cur]) {
            if(!twovisited[x]) {
                twovisited[x] = true;
                twodist[x] = twodist[cur] + 1;
                q.push(x);
            }
        }
    }
}



int main() {
    cin >> n;
    one.resize(n);
    onedist.resize(n);
    onevisited.resize(n);
    for(int i = 0 ;i < n - 1; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        one[a].push_back(b);
        one[b].push_back(a);
    }
    cin >> m;
    two.resize(m);
    twodist.resize(m);
    twovisited.resize(m);
    for(int i = 0 ;i < m - 1; i++) {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        two[a].push_back(b);
        two[b].push_back(a);
    }

    bfsone(0);
    int furthest = 0;
    int maxdist1 = 0;
    for(int i = 0 ;i < n ;i++) {
        if(onedist[i] > maxdist1) {
            furthest = i;
            maxdist1 = onedist[i];
        }
    }
    onevisited.assign(n , false);
    bfsone(furthest);
    for(auto &x: onedist) {
        maxdist1 = max(maxdist1, x);
    }

    bfstwo(0);
    furthest = 0;
    int maxdist2 = 0;
    for(int i = 0 ;i < m ;i++) {
        if(twodist[i] > maxdist2) {
            furthest = i;
            maxdist2 = twodist[i];
        }
    }
    twovisited.assign(m , false);
    bfstwo(furthest);
    for(auto &x: twodist) {
        maxdist2 = max(maxdist2, x);
    }

    int answer = (maxdist1 + 1) / 2 + (maxdist2  + 1) / 2+ 1;
    answer = max(answer , maxdist1);
    answer = max(answer , maxdist2);
    cout << answer << endl;
    
}