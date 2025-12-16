#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<int> parent;
vector<int>teamsize;

int get(int a) {
    if(a != parent[a]) {
        parent[a] = get(parent[a]);
    }
    return parent[a];
}

void unify(int a ,int  b) {
    a = get(a);
    b = get(b);
    if(a == b) {
        return;
    }
    if(teamsize[a] > teamsize[b]) {
        swap(a , b);
    }
    parent[a] = b;
    teamsize[b] += teamsize[a];
}

string together(int a , int b) {
    a = get(a);
    b = get(b);

    if(a == b) {
        return "YES";
    }
    return "NO";
}

int main() {
    cin >> n >> m;
    parent.resize(n + 1);
    teamsize.resize(n + 1, 1);

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for(int i = 0 ;i < m; i++) {
        string s;
        cin >> s;
        if(s == "union") {
            int a, b;
            cin >> a >> b;
            unify(a , b);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << together(a , b) << endl;
        }
    }
}