#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    string s;
    cin >> s;
    map<ll, ll> bitsfound;
    bitsfound[0]++;
    ll curbit = 0;
    for(auto &x : s) {
        ll cur = 1 << (x - '0');
        curbit = (curbit ^ cur);
        bitsfound[curbit]++;
    }
    ll ans = 0;
    for(auto &x : bitsfound) {
        ans += x.second * (x.second - 1) / 2;
    }

    cout << ans << endl;
}