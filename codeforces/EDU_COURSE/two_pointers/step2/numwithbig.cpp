#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n , s;
    cin >> n >> s;
    vector<ll> v(n);
    for(auto &x : v) {
        cin >> x;
    }

    int l = 0 ;
    int r = 0;
    ll cursum = 0;
    ll segnum = 0;

    while(r < n) {
        cursum += v[r];
        r++;
        while(cursum >= s) {
            cursum -= v[l];
            l++;
        }
        segnum += l;
    }

    cout << segnum << endl;
}