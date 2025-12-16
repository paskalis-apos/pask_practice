#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> p(50000 + 5);
vector<ll> cr(50000 + 5);

struct edge{
    ll a, b , w;
    bool operator<(const edge &x) {
        return w > x.w;
    }
};

ll get(ll a){
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}
void unite(ll a, ll b) {
    a = get(a);
    b = get(b);
    if(cr[a] < cr[b]) {
        swap(a , b);
    }
    cr[a] += (cr[a] == cr[b]);
    p[b] = a;
}

bool together(ll a , ll b){
    if(get(a) == get(b)) {
        return true;
    }
    return false;
}

int main(){
    ll n , m , s;
    cin >> n >> m >> s;
    vector<edge> v(m);
    map<pair<int,int>, int> edgeind;
    for(int i = 0;i < m; i++){
        cin >> v[i].a >> v[i].b >> v[i].w;
        edgeind[{v[i].a , v[i].b}] = i + 1; 
    }
    for(int i = 1; i<= n;i++) {
        p[i] = i;
    }
    sort(v.begin(), v.end());
    vector<edge> weightsbehind;
    ll delsum = 0;
    for(auto &x : v) {
        if(together(x.a, x.b)) {
            weightsbehind.push_back(x);
            delsum += x.w;
        } 
        else {
            unite(x.a , x.b);
        }
    }

    int ind = 0;
    while(delsum > s) {
        delsum -= weightsbehind[ind].w;
        ind++;
    }
    cout << weightsbehind.size() - ind << endl;
    for(int i = ind;i  < weightsbehind.size(); i++) {
        cout << edgeind[{weightsbehind[i].a, weightsbehind[i].b}] << " ";
    }
    cout << endl;

}