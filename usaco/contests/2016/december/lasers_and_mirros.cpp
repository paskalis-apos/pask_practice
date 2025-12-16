#include<bits/stdc++.h>
using namespace std;

int n, xlaser, ylast, xbarn , ybarn;

int main() {
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    cin >> n ;
    map<int,vector<int>> x_to_y;
    map<int,vector<int>> y_to_x;
    vector<pair<int,int>> points(n + 2);
    cin >> points[0].first >> points[0].second >> points[n + 1].first >> points[n + 1].second;
    for(int i = 1 ;i <= n; i++) {
        cin >> points[i].first >> points[i].second;;
    }

    for(int i = 0; i <= n + 1; i++) {
        x_to_y[points[i].first].push_back(i);
        y_to_x[points[i].second].push_back(i);
    }

    vector<int> dist(n + 2, INT_MAX);
    dist[0] = 0;

    queue<pair<int,int>> q;
    q.push({0 , 1});
    q.push({0 , 0});

    while(!q.empty()) {
        int ind = q.front().first;
        int dir = q.front().second;
        q.pop();
        if(dir == 0) {
            for(auto &x : x_to_y[points[ind].first]) {
                if(dist[x] == INT_MAX) {
                    dist[x] = dist[ind]  +1;
                    q.push({x, 1});
                }
            }
        }
        else {
            for(auto &x : y_to_x[points[ind].second]) {
                if(dist[x] == INT_MAX) {
                    dist[x] = dist[ind] + 1;
                    q.push({x, 0});
                }
            }
        }
    }

    if(dist[n + 1] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << dist[n + 1] - 1;
    }
    cout << endl;
}
