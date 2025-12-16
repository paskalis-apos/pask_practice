#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;


int main( ){
    int n , m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0 ;i < m ;i++) {
        int a , b , c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b , c});
    }

    vector<ll> distance(n, INF);
    vector<ll> minflights(n, INF);
    vector<ll> maxflights(n, 0);
    vector<ll> distnum(n, 0);
    vector<bool> visited(n, 0);

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    distance[0] = 0;
    minflights[0] = 0;
    maxflights[0] = 0;
    distnum[0] = 1;

    q.push({0, 0});
    while(!q.empty()) {
        int cur = q.top().second;
        q.pop();
        if(visited[cur]) {
            continue;
        }
        visited[cur] = true;
        for(auto &x : adj[cur]) {
            if(distance[cur] + x.second < distance[x.first]) {
                distance[x.first] = distance[cur] + x.second;
                minflights[x.first] = minflights[cur] + 1;
                maxflights[x.first] = maxflights[cur] + 1;
                distnum[x.first] = distnum[cur];
                q.push({distance[x.first], x.first});   
            }
            else if(distance[cur] + x.second == distance[x.first]) {
                minflights[x.first] = min(minflights[x.first], minflights[cur] + 1);
                maxflights[x.first] = max(maxflights[x.first], maxflights[cur] + 1);
                distnum[x.first] = (distnum[x.first] + distnum[cur]) % MOD;
            }
        }
    }

    cout << distance[n - 1] << " " << distnum[n - 1] << " " << minflights[n - 1] << " " << maxflights[n - 1] << endl;
    
}