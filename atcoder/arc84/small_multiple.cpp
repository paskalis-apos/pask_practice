#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main( ){
    int k;
    cin >> k;   
    vector<int> dist(k, INF);
    deque<int> q;
    dist[1] = 1;
    q.push_back(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop_front();
        int temp = (cur * 10);
        temp %= k;
        if(dist[cur] < dist[temp]) {
            dist[temp] = dist[cur];
            q.push_front(temp);
        }
        temp = cur + 1;
        temp %= k;
        if(dist[cur] + 1 < dist[temp]) {
            dist[temp] = dist[cur] + 1;
            q.push_back(temp);
        }
    }

    cout << dist[0] << endl;
}