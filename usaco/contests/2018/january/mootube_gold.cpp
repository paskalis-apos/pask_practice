#include<bits/stdc++.h>
using namespace std;

struct road{
    int a, b, r;

    bool operator<(road oth) {
        return r > oth.r;
    }
};

vector<road>adj;
vector<pair<pair<int,int>,int>> queries;
vector<int> parent;
vector<int> teamsize;
int n, q;

int get(int a) {
    if(parent[a] != a) {
        parent[a] = get(parent[a]);
    }
    return parent[a];
}

void unite(int a , int b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a ,b);
    }
    teamsize[b] += teamsize[a];
    parent[a] = b;
}

int canreach(int a) {
    a = get(a);
    return teamsize[a] - 1;
}


int main() {
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    cin >> n >> q;
    vector<int> answers;
    answers.resize(q);
    adj.resize(n);
    queries.resize(q);
    parent.resize(n + 1);
    teamsize.resize(n + 1, 1);

    for(int i = 1 ; i <= n ;i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n-1; i++) {
        int a , b , r;
        cin >> a >> b >> r;
        adj[i] = { a, b , r};
    }

    sort(adj.begin(), adj.end());

    for(int i = 0 ;i < q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries.rbegin(), queries.rend());

    int counter = 0;
    for(auto &x : queries) {
        while(adj[counter].r >= x.first.first) {
            int a = adj[counter].a;
            int b = adj[counter].b;
            unite(a , b);
            counter++;
        }   

        answers[x.second] = canreach(x.first.second);
    }

    for(auto &x : answers) {
        cout << x << endl;
    }
}