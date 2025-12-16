#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for(auto &x : a){cin >> x;}
    for(auto &x : b){cin >> x;}
    for(auto &x : c){cin >> x;}

    map<ll,ll> a_found;
    for(auto &x : a) {
        a_found[x]++;
    }

    ll vpairs = 0;
    for(auto &x : c) {
        vpairs += a_found[b[x - 1]];
    }

    cout << vpairs << endl;
}