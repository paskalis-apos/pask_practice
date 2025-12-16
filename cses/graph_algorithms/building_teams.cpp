#include<bits/stdc++.h>
using namespace std;

int pupilnum , friendsnum;
vector<int>pupilteam;
vector<vector<int>>adj;
bool valid = true;


void dfs(int index, int team) {
    if(!valid) {
        return;
    }
    if(pupilteam[index] != 0) {
        if(pupilteam[index] != team) {
            valid = false;
        }
        return;      
    }
    pupilteam[index] = team;
    if(team == 1) {
        for(auto &x : adj[index]) {
            dfs(x, 2);
        }
    }
    else {
        for(auto &x :adj[index]) {
            dfs(x , 1);
        }
    }
    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> pupilnum >> friendsnum;
    adj.resize(pupilnum);
    pupilteam.resize(pupilnum);
    for(int i = 0 ;i < friendsnum; i++) {
        int a , b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    for(int i = 0 ;i < pupilnum && valid; i++) {
        if(pupilteam[i] == 0) {
            dfs(i, 1);
        }
    }
    
    if(!valid) {
        cout <<"IMPOSSIBLE";
        return 0;
    }
    else {
        for(auto &x : pupilteam) {
            cout << x << " ";
        }
    }


}