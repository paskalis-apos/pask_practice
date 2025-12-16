#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<int> parents;
vector<int> teamsize;
vector<int> maxnum;
vector<int> minnum;

int get(int a){
    if(a != parents[a]) {
        parents[a] = get(parents[a]);
    }
    return parents[a];
}

void unite(int a , int b){
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a,b);
    }
    parents[a] = b;
    teamsize[b] += teamsize[a];
    maxnum[b] = max(maxnum[b], maxnum[a]);
    minnum[b] = min(minnum[b], minnum[a]);
}

void print_answer(int a){
    a = get(a);
    cout << minnum[a] << " " << maxnum[a] << " " << teamsize[a] << endl;
}

int main() {
    cin >> n >> m;
    parents.resize(n + 1);
    teamsize.resize(n + 1, 1);
    minnum.resize(n + 1);
    maxnum.resize(n + 1);

    for(int i = i; i <= n; i++) {
        parents[i] = i;
        minnum[i] = i;
        maxnum[i] = i;
    }

    for(int i = 0 ;i < m ;i++) {
        string s;
        cin >> s;
        if(s == "union") {
            int a , b;
            cin >> a >> b;
            unite(a , b);
        }
        else{
            int a;
            cin >> a;
            print_answer(a);
        }
    }
}