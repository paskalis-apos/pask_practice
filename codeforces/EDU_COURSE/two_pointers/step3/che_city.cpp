#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , dist;
    cin >> n >> dist;

    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    ll l = 0 , r = 1;
    ll noplace = 0;
    while(r < n) {
        while(v[r] - v[l] > dist) {
            l++;
        }
        noplace += r - l;
        r++;
    }

    ll totalplacements = n * (n + 1) / 2;
    totalplacements -= noplace ;
    totalplacements -= n;

    cout << totalplacements << endl;
}