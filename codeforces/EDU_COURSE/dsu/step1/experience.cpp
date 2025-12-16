#include<bits/stdc++.h>
using namespace std;

vector<int> p(200005);
vector<int> sz(200005);
vector<int> score(200005);
vector<int> extra(200005);

int get(int a) {
    if(a == p[a]) {
        return a;
    } 
    return get(p[a]);
}

void unite(int a , int b) {
    int pa = get(a);
    int pb = get(b);
    if(pa == pb) {
        return;
    }
    if(sz[pa] < sz[pb]) {
        swap(pa , pb);
    }
    sz[pa] += sz[pb];
    extra[pb] = score[pa];
    p[pb] = pa;
}

void upd_score(int a, int u) {
    a = get(a);
    score[a] += u;
}

int find_score(int a) {
    if(a == p[a]) {
        return score[a];
    }
    return (score[a] - extra[a]) + find_score(p[a]);
}

int main() {
    ios:: sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;  
    for(int i = 1 ;i <= n;i++) {
        p[i] = i;
    }

    for(int i = 0; i < m ;i++) {
        string s;
        cin >> s;
        if(s == "join") {
            int a , b;
            cin >> a >> b;
            unite(a , b);
        }
        else if(s == "add") {
            int x, v;
            cin >> x >> v;
            upd_score(x , v);
        }
        else {
            int x;
            cin >> x;
            cout << find_score(x) << endl;
        }
    }
}