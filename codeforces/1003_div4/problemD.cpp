#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

bool cmp(vector<ll> a, vector<ll> b) {
    int size = a.size();
    ll value1 = 0;
    ll value2 = 0;
    for(auto &x: a) {
        value1 += x ;
    }
    for(auto &x: b) {
        value2 += x;
    }

    return value1 > value2;
}

void solve() {
    ll n , m;
    cin >> n >> m;

    vector<vector<ll>>v(n);
    for(int j = 0 ; j < n ;j ++) {
        for(int i = 0 ;i < m; i++) {
            ll temp;
            cin >> temp;
            v[j].push_back(temp);
        }
    }

    sort(v.begin(),v.end(), cmp);

    vector<ll>toadd(n * m + 1);
    ll i = 0 ;
    ll j = 0;
    for(ll counter = 1 ;counter <= n * m; counter++) {
        ll add = v[i][j];
        toadd[counter] =toadd[counter - 1] + add;
        j++;
        if(j == m) {
            j = 0;
            i++;
        }
    }

    ll answer = 0;
    for(auto &x : toadd) {
        answer += x;
    }

    cout << answer << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) {
        solve();
    }
}