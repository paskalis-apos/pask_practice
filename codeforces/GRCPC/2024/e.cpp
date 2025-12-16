#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> rk;

struct ed{
    int a , b, c;
    bool operator<(ed &test) {
        return c < test.c;
    }
};

int get(int a) {
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}

void unite(int a , int b) {
    a = get(a);
    b = get(b);
    if(rk[a] < rk[b]) {
        swap(a , b);
    }

    if(rk[a] == rk[b]) {
        rk[a]++;
    }
    rk[b] = rk[a];
    p[b] = p[a];
}

bool together(int a , int b) {
    if(get(a) == get(b)) {
        return true;
    }
    return false;
}



int main() {
    int n;
    cin >> n;
    p.resize(n + 1);
    rk.resize(n + 1);
    for(int i = 0;i <= n;i++) {
        p[i] = i;
    }
    vector<ed> edges(n + 1);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n ;j++) {
            int c;
            cin >> c;
            if(i == j) {
                edges.push_back({i, n, c});
            }
            else {
                edges.push_back({i, j , c});
            }
        }
    }

    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto &x : edges) {
        if(together(x.a, x.b)) {
            continue;
        }
        ans += x.c;
        unite(x.a, x.b);
    }

    cout << ans << endl;
}