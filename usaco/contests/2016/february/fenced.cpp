#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct road{
    int a , b;
    int c;
    bool operator<(road temp) {
        return c > temp.c;
    }
};

int A , B , n , m;
vector<road> adj;
vector<int> parents(2003 * 2003);
vector<int> teamsize(2003 * 2003);

int get(int a) {
    if(a != parents[a]) {
        parents[a] = get(parents[a]);
    }
    return parents[a];
}

bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if(a == b){ 
        return true;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a , b);
    }
    teamsize[b] += teamsize[a];
    parents[a] = b;
    return false;
}


int main() {
    freopen("fencedin.in","r",stdin);
    freopen("fencedin.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("fencedin.in","r",stdin);
    //freopen("fencedin.out","w",stdout);
    cin >> A >> B >> n >> m;
    vector<int> as(n);
    for(auto &x : as) {
        cin >> x;
    }
    as.push_back({0});
    as.push_back({A});
    vector<int> bs(m);
    for(auto &x : bs) {
        cin >> x;
    }
    bs.push_back({0});
    bs.push_back({B});

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    ll allcost = 0;
    for(int i = 0 ;i <= n + 1 ;i++) {
        for(int j = 0; j <= m ;j ++) {
            parents[i * (m + 2) + j] = i * (m + 2) + j;
            parents[i * (m + 2)+ j + 1] = i * (m + 2) + j + 1;
            teamsize[i * m + j] = 1;
            teamsize[i * m + j + 1] = 1;
            if(i == 0 || i == n + 1) {
                unite(i * (m + 2) + j, i * (m + 2)+  j + 1);
                continue;
            }
            adj.push_back({i * (m + 2) + j, i * (m + 2) + j + 1, bs[j + 1] - bs[j]});
            allcost += bs[j + 1] - bs[j];
        }
    }
    for(int j = 0 ;j <= m + 1 ;j++) {
        for(int i = 0; i <= n  ;i ++) {
            if(j == 0 || j == m + 1) {
                unite(i * (m + 2) + j , (i + 1) * (m + 2) + j);
                continue;
            }
            adj.push_back({i * (m + 2) + j , (i + 1) * (m + 2)+ j, as[i + 1]- as[i]});
            allcost += as[i + 1] - as[i];
        }
    }

    sort(adj.begin(), adj.end()); 
    ll endcost = 0;
     for(auto &x : adj) {
        if(unite(x.a, x.b)) {
            continue;
        }
        endcost += x.c;     
    }

    ll answer = allcost - endcost;
    cout << answer << endl;
}