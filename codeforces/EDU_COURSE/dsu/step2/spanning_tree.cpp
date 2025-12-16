#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p(2 * 1e5 + 5);
vector<int> cr(2 * 1e5 + 5);

int get(int a) {
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if(cr[a] < cr[b]) {
        swap(a, b);
    }
    cr[a] += (cr[a] == cr[b]);
    p[b] = a;
}

bool together(int a, int b){
    if(get(a) == get(b)) {
        return true;
    }
    return false;
}

struct edge{
    int a , b , w;
    bool operator<(const edge &b){
        return w < b.w;
    }
};

int main() {
    int n ,m;
    cin >> n >> m;
    vector<edge> v(m);
    for(auto &x : v){
        cin >> x.a >> x.b >> x.w;
    }
    for(int i = 1 ;i <=n ;i++) {
        p[i] = i;
    }
    sort(v.begin(), v.end());
    ll totalw = 0;
    for(auto &x : v) {
        if(!together(x.a , x.b)) {
            unite(x.a , x.b);
            totalw += x.w ; 
        }
    }

    cout << totalw << endl;
}