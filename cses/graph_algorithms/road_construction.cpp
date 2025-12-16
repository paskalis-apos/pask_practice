#include<bits/stdc++.h>
using namespace std;

int n ,m;
int maxteam = 1;
int totalteams;
vector<int> parents;
vector<int> teamsize;

int get(int a){
    if(a != parents[a]) {
        parents[a] = get(parents[a]);
    }
    return parents[a];
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a, b);
    }
    teamsize[b] += teamsize[a];
    parents[a] = parents[b];
    totalteams--;
    maxteam = max(maxteam, teamsize[b]);
}

int main() {
    cin >> n >> m;
    totalteams = n;
    parents.resize(n + 1);
    teamsize.resize(n + 1, 1);
    for(int i = 1;i <= n;i++) {
        parents[i] = i;
    }

    for(int i = 0 ;i < m ;i++) {
        int a, b;
        cin >> a >> b ;
        unite(a , b);
        cout << totalteams << " " << maxteam << endl;
    }
}