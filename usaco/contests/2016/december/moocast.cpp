#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int cowsreached ;


void dfs(int index) {
    if(visited[index]) {
        return;
    }
    visited[index] = true;
    cowsreached++;
    for(auto &x : adj[index]) {
        dfs(x);
    }
}


int main() {
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int cownum;
    cin >> cownum;

    adj.resize(cownum);

    vector<pair<int,int>> cords(cownum);
    vector<int>range(cownum);
    for(int i = 0 ;i < cownum; i++) {
        cin >> cords[i].first >> cords[i].second >> range[i];
    }

    for(int i = 0 ;i < cownum; i++) {
        for(int j = i ; j < cownum; j++) {
            int sqdist = (cords[i].first - cords[j].first) * (cords[i].first - cords[j].first) +   (cords[i].second - cords[j].second) * (cords[i].second - cords[j].second);
            if(range[i] * range[i] >= sqdist) {
                adj[i].push_back(j);
            }
            if(range[j] * range[j] >= sqdist) {
                adj[j].push_back(i);
            }
        }
    }
    int answer = 0;

    for(int i = 0 ;i <cownum; i++) {
        visited.assign(cownum, false);
        cowsreached = 0;
        dfs(i);
        answer = max(answer ,cowsreached);
    }

    cout << answer << endl;


}