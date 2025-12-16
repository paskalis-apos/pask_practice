#include<bits/stdc++.h>
using namespace std;

vector<int>p(50005);
vector<int>sz(50005);


int get(int a) {
    if(a != p[a]) {
        p[a] = get(p[a]);
    }
    return p[a];
}
void unify(int a , int b) {
    a = get(a);
    b = get(b);

    if(a == b) {
        return;
    }
    if(sz[a] < sz[b]) {
        swap(a , b);
    }
    sz[a] += sz[b];
    p[b] = p[a];
}

bool together(int a , int b) {
    if(get(a) == get(b)) {
        return true;
    }
    return false;
}

int main( ){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i =1 ;i <= n ;i++) {
        p[i] = i;
    }
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
    }
    vector<pair<bool, pair<int,int>>> q;
    for(int i = 0 ;i < k; i++) {
        string s;
        int a , b;
        cin >> s >> a >> b;
        if(s == "cut") {
            q.push_back({true, {a , b}});
        }
        else {
            q.push_back({false, {a , b}});
        }
    }

    reverse(q.begin(), q.end());
    vector<bool> ans;
    for(auto &x : q) {
        if(x.first == true) {
            unify(x.second.first, x.second.second);
        }
        else {
            ans.push_back(together(x.second.first , x.second.second));
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0 ;i < ans.size() ;i++) {
        if(ans[i] == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


}