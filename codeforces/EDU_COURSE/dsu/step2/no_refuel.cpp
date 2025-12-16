#include<bits/stdc++.h>
using namespace std;

vector<int> p(1500 + 5);
vector<int> sz(1500 + 5);

struct rd{
    int a, b , d;
    bool operator<(const rd &b){
        return d < b.d;
    }
};

int get(int a){
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b){
        return;
    }
    if(sz[a] < sz[b]) {
        swap(a , b);
    }
    sz[a] += sz[b];
    p[b] = p[a];

}

int main() {
    int n , k;
    cin >> n >> k;
    
    vector<rd>v(k);
    for(int i = 1;i <= n;i++){
        p[i] =i;
        sz[i] = 1;
    }
    for(auto &x : v) {
        cin >> x.a >> x.b >> x.d;
    }

    sort(v.begin(), v.end());
    int ans;
    for(auto &x : v) {
        unite(x.a, x.b);
        if(sz[get(x.a)] == n) {
            ans = x.d;
            break;
        }
    }

    cout << ans << endl;
}